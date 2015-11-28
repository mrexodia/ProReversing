/*
	File:		ProReversing.h
	Date:		27.11.15
	Purpose:	This project gathers anti-anti-reversing techniques into an open library.
	The resulting DLL can be easily incorporated into all reverse engineering tools.
*/

#pragma once

/** Headers *****************************************************************/

#include <Windows.h>
#include <shellapi.h>
#include "../Common/Common.h"

/** Functions ****************************************************************/

/*
	Function Name:	EnableProReversing
	Parameters:		pszOption [-in-] - Represents list of ProReversing functions to be enabled
	Return Value:	STATUS_CODE
	Details:		Enabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATUS_CODE
EnableProReversing(
	__in PTSTR pszOption
);

/*
	Function Name:	DisableProReversing
	Parameters:		pszOption [-in-] - Represents list of ProReversing functions to be disabled
	Return Value:	STATUS_CODE
	Details:		Disabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATUS_CODE
DisableProReversing(
	__in PTSTR pszOption
);
