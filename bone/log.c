#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
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
=======

#include "log.h"
>>>>>>> 97ebee3adff2d15b113f4e4413d090d027908078

void log(char* s){
	FILE *pfile;
	fopen_s(&pfile,"c:\\hook.log", "a");//��д�ķ�ʽ��C.txt�ļ���
<<<<<<< HEAD
	fwrite(s, sizeof(char), strlen(s), pfile);//������д���ļ���
=======
	fwrite(s, 1, strlen(s), pfile);//������д���ļ���
>>>>>>> 97ebee3adff2d15b113f4e4413d090d027908078
	fflush(pfile);//ˢ�»�������������������д���ļ�
	fclose(pfile);//�ر��ļ�
}

<<<<<<< HEAD
void wlog( LPCWSTR s){
	setlocale(LC_CTYPE, "chs");
	//char sText[100] = { 0 };
	//WCharToMByte(s,sText, sizeof(sText) / sizeof(sText[0]));
	FILE *pfile;
	fopen_s(&pfile, "c:\\hook1.log", "a");//��д�ķ�ʽ��C.txt�ļ���
	fwprintf(pfile, s);
	//fwrite(s, sizeof(char), strlen(sText), pfile);
	fwrite("\n", 1, 1, pfile);
=======
void wlog(const wchar_t* s){
	FILE *pfile;
	fopen_s(&pfile, "c:\\hook.log", "a");//��д�ķ�ʽ��C.txt�ļ���
	fwprintf(pfile, s);
>>>>>>> 97ebee3adff2d15b113f4e4413d090d027908078
	//fwrite(s, 1, strlen(s), pfile);//������д���ļ���
	fflush(pfile);//ˢ�»�������������������д���ļ�
	fclose(pfile);//�ر��ļ�
}