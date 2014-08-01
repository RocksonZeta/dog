#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "log.h"

BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
	if (dwSize < dwMinSize)
	{
		return FALSE;
	}
	WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwSize, NULL, FALSE);
	return TRUE;
}


void log(char* s){
	FILE *pfile;
	fopen_s(&pfile,"c:\\hook.log", "a");//以写的方式打开C.txt文件。
	fwrite(s, sizeof(char), strlen(s), pfile);//将数据写入文件。
	fflush(pfile);//刷新缓冲区。将缓冲区数据写入文件
	fclose(pfile);//关闭文件
}
void wlog( LPCWSTR s){
	if (!s){
		return;
	}
	setlocale(LC_CTYPE, "chs");
	//char sText[100] = { 0 };
	//WCharToMByte(s,sText, sizeof(sText) / sizeof(sText[0]));
	FILE *pfile;
	fopen_s(&pfile, "c:\\hook1.log", "a");//以写的方式打开C.txt文件。
	fwprintf_s(pfile, s);
	//fwprintf(pfile, s);
	//fwrite(s, sizeof(char), strlen(sText), pfile);
	fwrite("\n", 1, 1, pfile);
	//fwrite(s, 1, strlen(s), pfile);//将数据写入文件。
	fflush(pfile);//刷新缓冲区。将缓冲区数据写入文件
	fclose(pfile);//关闭文件
}

void log_error(char* s){
	FILE *pfile;
	fopen_s(&pfile, "./error.log", "a");
	fwrite(s, sizeof(char), strlen(s), pfile);
	fflush(pfile);
	fclose(pfile);
}