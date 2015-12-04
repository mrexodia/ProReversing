/*
	File:		ProReversing.c
	Date:		27.11.15
	Purpose:	This project gathers anti-anti-reversing techniques into an open library.
				The resulting DLL can be easily incorporated into all reverse engineering tools.
*/

#include <Common.h>
#include "ProReversing.h"

/*
	Function Name:	enable_proreversing
	Parameters:		pszOption		-		IN		- The anti anti reversing options
	Return Value:	STATUS_CODE
	Details:		Enabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATIC
STATUS_CODE
enable_proreversing(
	__in PTSTR pszOptions
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	ppszArgument = CommandLineToArgvW(pszOptions, pdwArgc);
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
	Function Name:	disable_proreversing
	Parameters:		pszOption		-		IN		- The anti anti reversing options
	Return Value:	STATUS_CODE
	Details:		Disabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATIC
STATUS_CODE
disable_proreversing(
	__in PTSTR pszOptions
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	ppszArgument = CommandLineToArgvW(pszOptions, pdwArgc);
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
	Function Name:	SafeEnableProReversing
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
SafeEnableProReversing(
	__in HWND hwnd,
	__in HINSTANCE hinst,
	__in PTSTR lpszCmdLine,
	__in int nCmdShow
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	
	//	 SEH is required to prevent process crashing when the code have bugs
	__try
	{
		eStatus = enable_proreversing(lpszCmdLine);
		if (STATUS_SUCCESS != eStatus)
		{
			DEBUG_PRINT("EnableProReversing failed with: %d", eStatus);
		}
		else
		{
			DEBUG_PRINT("EnableProReversing successed");
		}
	}

	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		DEBUG_PRINT("EnableProReversing throws an exception");
	}

	return eStatus;
}

/*
	Function Name:	SafeDisableProReversing
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
SafeDisableProReversing(
	__in HWND hwnd,
	__in HINSTANCE hinst,
	__in PTSTR lpszCmdLine,
	__in int nCmdShow
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;

	//	 SEH is required to prevent process crashing when the code have bugs
	__try
	{
		eStatus = disable_proreversing(lpszCmdLine);
		if (STATUS_SUCCESS != eStatus)
		{
			DEBUG_PRINT("EnableProReversing failed with: %d", eStatus);
		}
		else
		{
			DEBUG_PRINT("EnableProReversing successed");
		}
	}

	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		DEBUG_PRINT("EnableProReversing throws an exception");
	}

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