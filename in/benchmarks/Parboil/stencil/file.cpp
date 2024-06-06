/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <inttypes.h>

void outputData(char *fName, float *h_A0, int nx, int ny, int nz)
{
  FILE *fid = fopen(fName, "w");
  uint32_t tmp32;
  if (fid == NULL)
  {
    fprintf(stderr, "Cannot open output file\n");
    exit(-1);
  }
  tmp32 = nx * ny * nz;
  fwrite(&tmp32, sizeof(uint32_t), 1, fid);
  fwrite(h_A0, sizeof(float), tmp32, fid);

  fclose(fid);
}
