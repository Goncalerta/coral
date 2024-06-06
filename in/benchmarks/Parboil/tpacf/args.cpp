/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "args.h"

extern char *optarg;

void usage(char *name)
{
  printf("Usage: %s <-d data_file_name> <-r rnd_file_name> "
         "<-m rnd_count> <-p count> <-o file_name>\n",
         name);
  exit(0);
}

char *optarg;
int optind = 1, opterr = 1, optopt, __optpos, optreset = 0;

#define optpos __optpos

static void __getopt_msg(const char *a, const char *b, const char *c, size_t l)
{
  FILE *f = stderr;
#if !defined(WIN32) && !defined(_WIN32)
  flockfile(f);
#endif
  fputs(a, f);
  fwrite(b, strlen(b), 1, f);
  fwrite(c, 1, l, f);
  fputc('\n', f);
#if !defined(WIN32) && !defined(_WIN32)
  funlockfile(f);
#endif
}

int getopt(int argc, char *const argv[], const char *optstring)
{
  int i, c, d;
  int k, l;
  char *optchar;

  if (!optind || optreset)
  {
    optreset = 0;
    __optpos = 0;
    optind = 1;
  }

  if (optind >= argc || !argv[optind])
    return -1;

  if (argv[optind][0] != '-')
  {
    if (optstring[0] == '-')
    {
      optarg = argv[optind++];
      return 1;
    }
    return -1;
  }

  if (!argv[optind][1])
    return -1;

  if (argv[optind][1] == '-' && !argv[optind][2])
    return optind++, -1;

  if (!optpos)
    optpos++;
  c = argv[optind][optpos], k = 1;
  optchar = argv[optind] + optpos;
  optopt = c;
  optpos += k;

  if (!argv[optind][optpos])
  {
    optind++;
    optpos = 0;
  }

  if (optstring[0] == '-' || optstring[0] == '+')
    optstring++;

  i = 0;
  d = 0;
  do
  {
    d = optstring[i], l = 1;
    if (l > 0)
      i += l;
    else
      i++;
  } while (l && d != c);

  if (d != c)
  {
    if (optstring[0] != ':' && opterr)
      __getopt_msg(argv[0], ": unrecognized option: ", optchar, k);
    return '?';
  }
  if (optstring[i] == ':')
  {
    if (optstring[i + 1] == ':')
      optarg = 0;
    else if (optind >= argc)
    {
      if (optstring[0] == ':')
        return ':';
      if (opterr)
        __getopt_msg(argv[0],
                     ": option requires an argument: ",
                     optchar, k);
      return '?';
    }
    if (optstring[i + 1] != ':' || optpos)
    {
      optarg = argv[optind++] + optpos;
      optpos = 0;
    }
  }
  return c;
}

void parse_args(int argc, char **argv, options *args)
{
  int c;

  args->data_name = NULL;
  args->random_name = NULL;
  args->random_count = 0;
  args->npoints = 0;
  args->output_name = NULL;

  while ((c = getopt(argc, argv, "d:n:r:p:o:")) != EOF)
  {
    switch (c)
    {
    case 'd':
      args->data_name = optarg;
      break;
    case 'r':
      args->random_name = optarg;
      break;
    case 'n':
      args->random_count = atoi(optarg);
      break;
    case 'o':
      args->output_name = optarg;
      break;
    case 'p':
      args->npoints = atol(optarg);
      break;
    default:
      usage(argv[0]);
    }
  }
}
