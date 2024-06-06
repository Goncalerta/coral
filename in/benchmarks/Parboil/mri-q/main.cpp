/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/*
 * C code for creating the Q data structure for fast convolution-based
 * Hessian multiplication for arbitrary k-space trajectories.
 *
 * Inputs:
 * kx - VECTOR of kx values, same length as ky and kz
 * ky - VECTOR of ky values, same length as kx and kz
 * kz - VECTOR of kz values, same length as kx and ky
 * x  - VECTOR of x values, same length as y and z
 * y  - VECTOR of y values, same length as x and z
 * z  - VECTOR of z values, same length as x and y
 * phi - VECTOR of the Fourier transform of the spatial basis
 *      function, evaluated at [kx, ky, kz].  Same length as kx, ky, and kz.
 *
 * recommended g++ options:
 *  -O3 -lm -ffast-math -funroll-all-loops
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "parboil.h"
#include "file.h"

#define PI 3.1415926535897932384626433832795029f
#define PIx2 6.2831853071795864769252867665590058f

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define K_ELEMS_PER_GRID 2048

#if defined(WIN32) && !defined(UNIX)
#define aligned_alloc calloc
#endif

struct kValues
{
  float Kx;
  float Ky;
  float Kz;
  float PhiMag;
};

inline void
ComputePhiMagCPU(int numK,
                 float *phiR, float *phiI, float *phiMag)
{
  int indexK = 0;
  for (indexK = 0; indexK < numK; indexK++)
  {
    float real = phiR[indexK];
    float imag = phiI[indexK];
    phiMag[indexK] = real * real + imag * imag;
  }
}

inline void
ComputeQCPU(int numK, int numX,
            struct kValues *kVals,
            float *x, float *y, float *z,
            float *Qr, float *Qi)
{
  float expArg;
  float cosArg;
  float sinArg;

  int indexK, indexX;
  for (indexK = 0; indexK < numK; indexK++)
  {
    for (indexX = 0; indexX < numX; indexX++)
    {
      expArg = PIx2 * (kVals[indexK].Kx * x[indexX] +
                       kVals[indexK].Ky * y[indexX] +
                       kVals[indexK].Kz * z[indexX]);

      cosArg = cosf(expArg);
      sinArg = sinf(expArg);

      float phi = kVals[indexK].PhiMag;
      Qr[indexX] += phi * cosArg;
      Qi[indexX] += phi * sinArg;
    }
  }
}

void createDataStructsCPU(int numK, int numX, float **phiMag,
                          float **Qr, float **Qi)
{
  *phiMag = (float *)calloc(16, numK * sizeof(float));
  *Qr = (float *)calloc(16, numX * sizeof(float));
  memset((void *)*Qr, 0, numX * sizeof(float));
  *Qi = (float *)calloc(16, numX * sizeof(float));
  memset((void *)*Qi, 0, numX * sizeof(float));
}

int main(int argc, char *argv[])
{
  int numX, numK;      /* Number of X and K values */
  int original_numK;   /* Number of K values in input file */
  float *kx, *ky, *kz; /* K trajectory (3D vectors) */
  float *x, *y, *z;    /* X coordinates (3D vectors) */
  float *phiR, *phiI;  /* Phi values (complex) */
  float *phiMag;       /* Magnitude of Phi */
  float *Qr, *Qi;      /* Q signal (complex) */
  struct kValues *kVals;

  struct pb_Parameters *params;
  struct pb_TimerSet timers;

  pb_InitializeTimerSet(&timers);

  /* Read command line */
  params = pb_ReadParameters(&argc, argv);
  if ((params->inpFiles[0] == NULL) || (params->inpFiles[1] != NULL))
  {
    fprintf(stderr, "Expecting one input filename\n");
    exit(-1);
  }

  /* Read in data */
  pb_SwitchToTimer(&timers, pb_TimerID_IO);
  inputData(params->inpFiles[0],
            &original_numK, &numX,
            &kx, &ky, &kz,
            &x, &y, &z,
            &phiR, &phiI);

  /* Reduce the number of k-space samples if a number is given
   * on the command line */
  if (argc < 2)
    numK = original_numK;
  else
  {
    int inputK;
    char *end;
    inputK = strtol(argv[1], &end, 10);
    if (end == argv[1])
    {
      fprintf(stderr, "Expecting an integer parameter\n");
      exit(-1);
    }

    numK = MIN(inputK, original_numK);
  }

  printf("%d pixels in output; %d samples in trajectory; using %d samples\n",
         numX, original_numK, numK);

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
  /* Create CPU data structures */
  createDataStructsCPU(numK, numX, &phiMag, &Qr, &Qi);
  
  ComputePhiMagCPU(numK, phiR, phiI, phiMag);

  kVals = (struct kValues *)calloc(numK, sizeof(struct kValues));
  int k;
  for (k = 0; k < numK; k++)
  {
    kVals[k].Kx = kx[k];
    kVals[k].Ky = ky[k];
    kVals[k].Kz = kz[k];
    kVals[k].PhiMag = phiMag[k];
  }
  #pragma kernel
  ComputeQCPU(numK, numX, kVals, x, y, z, Qr, Qi);
  printf("Here2\n");
  if (params->outFile)
  {
    /* Write Q to file */
    pb_SwitchToTimer(&timers, pb_TimerID_IO);
    outputData(params->outFile, Qr, Qi, numX);
    pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
  }

  free(kx);
  free(ky);
  free(kz);
  free(x);
  free(y);
  free(z);
  free(phiR);
  free(phiI);
  free(phiMag);
  free(kVals);
  free(Qr);
  free(Qi);

  pb_SwitchToTimer(&timers, pb_TimerID_NONE);
  pb_PrintTimerSet(&timers);
  pb_FreeParameters(params);

  return 0;
}
