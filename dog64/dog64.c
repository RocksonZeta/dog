#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "../bone/nose.h"
#include "../bone/sqlite.h"
#include "../bone/log.h"

HHOOK h_hook = 0;

_declspec(dllexport) int watch64(){
	printf("dog watch64ing\n");
	h_hook = SetWindowsHookEx(WH_SHELL, smell, GetModuleHandle(_T("dog64.dll")), 0);
	if (!h_hook){
		log_error("failed to set up windows hook.");
		return 1;
	}
	return 0;
}


/**
tear up windows hook
*/
_declspec(dllexport) int unwatch64(){
	printf("dog unwatch64ed\n");
	if (UnhookWindowsHookEx(h_hook) == FALSE){
		log_error("failed to tear up windows hook.");
		return 3;
	}
	return 0;
}


_declspec(dllexport) int init64(){
	return init_db();
}

_declspec(dllexport) int kill(){
	return close_db();
}
