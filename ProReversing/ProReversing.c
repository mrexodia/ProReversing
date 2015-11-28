#include "ProReversing.h"

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
)
{
	STATUS_CODE tStatus = STATUS_INVALID_VALUE;
	return tStatus;
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
	STATUS_CODE tStatus = STATUS_INVALID_VALUE;
	return tStatus;
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