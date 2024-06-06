/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <inttypes.h>

void inputData(char *fName, int *_numK, int *_numX,
               float **kx, float **ky, float **kz,
               float **x, float **y, float **z,
               float **phiR, float **phiI)
{
  int numK, numX;
  FILE *fid = fopen(fName, "r");

  if (fid == NULL)
  {
    fprintf(stderr, "Cannot open input file\n");
    exit(-1);
  }
  fread(&numK, sizeof(int), 1, fid);
  *_numK = numK;
  fread(&numX, sizeof(int), 1, fid);
  *_numX = numX;
  *kx = (float *)calloc(16, numK * sizeof(float));
  fread(*kx, sizeof(float), numK, fid);
  *ky = (float *)calloc(16, numK * sizeof(float));
  fread(*ky, sizeof(float), numK, fid);
  *kz = (float *)calloc(16, numK * sizeof(float));
  fread(*kz, sizeof(float), numK, fid);
  *x = (float *)calloc(16, numX * sizeof(float));
  fread(*x, sizeof(float), numX, fid);
  *y = (float *)calloc(16, numX * sizeof(float));
  fread(*y, sizeof(float), numX, fid);
  *z = (float *)calloc(16, numX * sizeof(float));
  fread(*z, sizeof(float), numX, fid);
  *phiR = (float *)calloc(16, numK * sizeof(float));
  fread(*phiR, sizeof(float), numK, fid);
  *phiI = (float *)calloc(16, numK * sizeof(float));
  fread(*phiI, sizeof(float), numK, fid);
  fclose(fid);
}

void outputData(char *fName, float *outR, float *outI, int numX)
{
  FILE *fid = fopen(fName, "w");
  uint32_t tmp32;

  if (fid == NULL)
  {
    fprintf(stderr, "Cannot open output file\n");
    exit(-1);
  }

  /* Write the data size */
  tmp32 = numX;
  fwrite(&tmp32, sizeof(uint32_t), 1, fid);

  /* Write the reconstructed data */
  fwrite(outR, sizeof(float), numX, fid);
  fwrite(outI, sizeof(float), numX, fid);
  fclose(fid);
}
