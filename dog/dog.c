#include <windows.h>
#include <stdio.h>
#include "../bone/log.h"
#define MYAPI extern "C" __declspec(dllexport)
HHOOK hHook = NULL;
LRESULT WINAPI KeyboardProc(int code, WPARAM wParam, LPARAM lParam)
{
	char info[100] = { 0 };
	sprintf_s(info, 100, "code:%d,wp:%d,lp:%d\n", code, wParam, lParam);
	if (HSHELL_WINDOWACTIVATED == code){
		HWND hwnd = (HWND)wParam;
		wchar_t title[30];
		GetWindowText(hwnd, title, 30);
		wlog(title);
	}
	log(info);

	return CallNextHookEx(hHook, code, wParam, lParam);
}
_declspec(dllexport) int SetHook()
{
	printf("set %d hook yeah\n", sizeof(void*)* 8);
	log("set hook\n");
	hHook = SetWindowsHookEx(WH_SHELL, KeyboardProc, GetModuleHandleA("dog.dll"), 0);
	if (hHook == NULL)
	{
		printf("SetWindowsHookEx() error :%d\n", GetLastError());
		return -1;
	}
	else{
		printf("set hook okay \n");

	}
	return 0;
}
_declspec(dllexport) int StopHook()
{
	log("stop hook\n");
	if (UnhookWindowsHookEx(hHook) == FALSE)
	{
		printf("UnhookWindowsHookEx() error :%d\n", GetLastError());
		return -1;
	}
	return 0;
}

_declspec(dllexport) int add(int a, int b){
	//printf("get module a %d", GetModuleHandleA("KeyboardHookDLL.dll"));
	return a + b;
}