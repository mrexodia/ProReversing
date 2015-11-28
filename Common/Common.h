/*
	File:		Common.h
	Date:		27.11.15
	Purpose:	Contain common use functions and configurations within the project
*/

#pragma once

/** Headers **************************************************************/

#include <Windows.h>
#include <stdarg.h>
#include <tchar.h>

/** Enums **************************************************************/

typedef enum _STATUS_CODE
{
	STATUS_INVALID_VALUE = -1,
	STATUS_SUCCESS,

	/* EnableProReversing*/
	STATUS_ENABLE_PROREVERSING_COMMANDLINE_TO_ARGV_FAILED,

	/* DisableProReversing*/
	STATUS_DISABLE_PROREVERSING_COMMANDLINE_TO_ARGV_FAILED,

} STATUS_CODE, *PSTATUS_CODE;

/** Macros **************************************************************/

#define DEBUG_PRINT(...) _tprintf(##_T(__VA_ARGS__));

/***********************************************************************/
