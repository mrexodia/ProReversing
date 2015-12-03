/*
	File:		ProReversing.c
	Date:		27.11.15
	Purpose:	This project gathers anti-anti-reversing techniques into an open library.
				The resulting DLL can be easily incorporated into all reverse engineering tools.
*/

#include "ProReversing.h"

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
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	MessageBox(0, 0, 0, 0);

	ppszArgument = CommandLineToArgvW(lpszCmdLine, pdwArgc);
	if (NULL == ppszArgument)
	{
		DEBUG_PRINT("CommandLineToArgvW Failed with: %d", GetLastError());
		eStatus = STATUS_ENABLE_PROREVERSING_COMMANDLINE_TO_ARGV_FAILED;
		goto Cleanup;
	}

Cleanup:
	return eStatus;
}

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
)
{

	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	ppszArgument = CommandLineToArgvW(lpszCmdLine, pdwArgc);
	if (NULL == ppszArgument)
	{
		DEBUG_PRINT("CommandLineToArgvW Failed with: %d", GetLastError());
		eStatus = STATUS_DISABLE_PROREVERSING_COMMANDLINE_TO_ARGV_FAILED;
		goto Cleanup;
	}

Cleanup:
	return eStatus;
}

BOOL
WINAPI
DllMain(
	__in HINSTANCE hinstDLL,
	__in DWORD fdwReason,
	__in LPVOID lpReserved
)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}