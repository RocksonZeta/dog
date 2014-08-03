#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "nose.h"
#include "log.h"
#include "time.h"
#include "sqlite.h"
#include "str_trans.h"
extern HHOOK h_hook;

LRESULT WINAPI smell(int code, WPARAM wParam, LPARAM lParam){
	if (HSHELL_WINDOWACTIVATED == code){
		HWND hwnd = (HWND)wParam;
		LPTSTR cmd = GetCommandLine();
		TCHAR title[100];
		TCHAR record[300];
		GetWindowText(hwnd, title, 100);
		_stprintf_s(record, 300, _T("win:%s,cmd:%s, gmt:%I64d\n"), title, cmd,get_gmt());
		save_message(cmd , title);
	}
	else{
		char info[100] = { 0 };
		sprintf_s(info, 100, "code:%d,wp:%d,lp:%d\n", code, wParam, lParam);
		log(info);
	}
	return CallNextHookEx(h_hook, code, wParam, lParam);
}
