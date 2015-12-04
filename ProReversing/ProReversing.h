/*
	File:		ProReversing.h
	Date:		27.11.15
	Purpose:	This project gathers anti-anti-reversing techniques into an open library.
				The resulting DLL can be easily incorporated into all reverse engineering tools.
*/

#pragma once

/** Headers *****************************************************************/

/** Functions ****************************************************************/

/*
	Function Name:	EnableProReversing
	Parameters:		RunDll interface.
					hwnd		-		IN		- Window handle
					hinst		-		IN		- DLL's instance handle
					lpszCmdLine -		IN		- ASCIIZ command line your DLL should parse
					nCmdShow	-		IN		- Describes how your DLL's windows should be displayed
	Return Value:	STATUS_CODE
	Details:		Enabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATUS_CODE
WINAPI
EnableProReversing(
	__in HWND hwnd,
	__in HINSTANCE hinst,
	__in PTSTR lpszCmdLine,
	__in int nCmdShow
);

/*
	Function Name:	DisableProReversing
	Parameters:		RunDll interface.
					hwnd		-		IN		- Window handle
					hinst		-		IN		- DLL's instance handle
					lpszCmdLine -		IN		- ASCIIZ command line your DLL should parse
					nCmdShow	-		IN		- Describes how your DLL's windows should be displayed
	Return Value:	STATUS_CODE
	Details:		Enabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATUS_CODE
WINAPI
DisableProReversing(
	__in HWND hwnd,
	__in HINSTANCE hinst,
	__in PTSTR lpszCmdLine,
	__in int nCmdShow
);