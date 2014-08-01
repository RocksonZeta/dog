/**
set up windows hook
*/
#include <windows.h>
#include "house.h"
#include "../bone/log.h"


HHOOK h_hook32 = 0;
HHOOK h_hook64 = 0;

LRESULT WINAPI dog(int code, WPARAM wParam, LPARAM lParam){
	if (HSHELL_WINDOWACTIVATED == code){
		HWND hwnd = (HWND)wParam;
		wchar_t title[100];
		GetWindowText(hwnd, title, 100);
		wlog(title);
	}
	else{
		char info[100] = { 0 };
		sprintf_s(info, 100, "code:%d,wp:%d,lp:%d\n", code, wParam, lParam);
		log(info);

	}
}



_declspec(dllexport) int unleash_dog(){
	h_hook32 = SetWindowsHookEx(WH_SHELL, dog, GetModuleHandle(_T("dog32.dll")), 0);
	if (!h_hook32)goto error32;
	if (8 <= sizeof(int*)){
		h_hook64 = SetWindowsHookEx(WH_SHELL, dog, GetModuleHandle(_T("dog64.dll")), 0);
		if (!h_hook64)goto error64;
	}
	return 0;

error32:
	log_error("failed to set up windows hook32.");
	return 1;

error64:
	log_error("failed to set up windows hook64.");
	return 2;
}


/**
tear up windows hook
*/
_declspec(dllexport) int leash_dog(){
	log("stop hook\n");
	if (UnhookWindowsHookEx(h_hook32) == FALSE){
		goto error32;
	}
	if (8 <= sizeof(int*)){
		if (UnhookWindowsHookEx(h_hook64) == FALSE){
			goto error64;
		}
	}
	return 0;
error32:
	log_error("failed to tear up windows hook32.");
	return 3;

error64:
	log_error("failed to tear up windows hook64.");
	return 4;
}