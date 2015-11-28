#include "ProReversing.h"

/*
	Function Name:	EnableProReversing
	Parameters:		pszOption [-in-] - Represents list of ProReversing functions to be enabled.
					The ProReversing functionality list is spilited by comma
	Return Value:	STATUS_CODE
	Details:		Enabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias
*/
STATUS_CODE
EnableProReversing(
	__in PTSTR pszOption
)
{
	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	ppszArgument = CommandLineToArgvW(pszOption, pdwArgc);
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
	Parameters:		pszOption [-in-] - Represents list of ProReversing functions to be disabled
	Return Value:	STATUS_CODE
	Details:		Disabling ProReversing functionality
	Date:			28.11.15
	Author:			Dvir Atias	
*/
STATUS_CODE
DisableProReversing(
	__in PTSTR pszOption
)
{

	STATUS_CODE eStatus = STATUS_INVALID_VALUE;
	PTSTR * ppszArgument = NULL;
	PDWORD pdwArgc = 0;

	ppszArgument = CommandLineToArgvW(pszOption, pdwArgc);
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