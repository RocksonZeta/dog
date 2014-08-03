#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "../bone/nose.h"
#include "../bone/log.h"

typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
_declspec(dllexport) int get_system_bits()
{
	// Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	PGNSI pGNSI;
	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	pGNSI = (PGNSI)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if (NULL != pGNSI)
	{
		pGNSI(&si);
	}
	else
	{
		GetSystemInfo(&si);
	}

	if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 || si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
	{
		return 64;
	}
	return 32;
}


HHOOK h_hook = 0;

_declspec(dllexport) int watch32(){
	printf("dog watch32ing \n");
	h_hook = SetWindowsHookEx(WH_SHELL, smell, GetModuleHandle(_T("dog32.dll")), 0);
	if (!h_hook){
		log_error("failed to set up windows hook.");
		return 1;
	}
	return 0;
}


/**
tear up windows hook
*/
_declspec(dllexport) int unwatch32(){
	printf("dog unwatch32ed \n");
	if (UnhookWindowsHookEx(h_hook) == FALSE){
		log_error("failed to tear up windows hook.");
		return 3;
	}
	return 0;
}