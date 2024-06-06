/* $Id: main.h,v 1.1 2008/03/04 17:30:03 stratton Exp $ */

/*############################################################################*/

#pragma once

/*############################################################################*/

#include <stdio.h>
#include <chrono>
#include "config.h"
#include "parboil.h"

/*############################################################################*/

typedef struct
{
	
std::chrono::steady_clock::time_point begin;
std::chrono::steady_clock::time_point end;

} MAIN_Time;

typedef enum
{
	NOTHING = 0,
	COMPARE,
	STORE
} MAIN_Action;
typedef enum
{
	LDC = 0,
	CHANNEL
} MAIN_SimType;

typedef struct
{
	int nTimeSteps;
	char *resultFilename;
	MAIN_Action action;
	MAIN_SimType simType;
	char *obstacleFilename;
} MAIN_Param;

/*############################################################################*/

void MAIN_parseCommandLine(int nArgs, char *arg[], MAIN_Param *param, struct pb_Parameters *);
void MAIN_printInfo(const MAIN_Param *param);
void MAIN_initialize(const MAIN_Param *param);
void MAIN_finalize(const MAIN_Param *param);

#if !defined(SPEC_CPU)
void MAIN_startClock(MAIN_Time *time);
void MAIN_stopClock(MAIN_Time *time, const MAIN_Param *param);
#endif

/*############################################################################*/

