#include <stdio.h>
#include <string.h>

#include "log.h"

void log(char* s){
	FILE *pfile;
	fopen_s(&pfile,"c:\\hook.log", "a");//��д�ķ�ʽ��C.txt�ļ���
	fwrite(s, 1, strlen(s), pfile);//������д���ļ���
	fflush(pfile);//ˢ�»�������������������д���ļ�
	fclose(pfile);//�ر��ļ�
}

void wlog(const wchar_t* s){
	FILE *pfile;
	fopen_s(&pfile, "c:\\hook.log", "a");//��д�ķ�ʽ��C.txt�ļ���
	fwprintf(pfile, s);
	//fwrite(s, 1, strlen(s), pfile);//������д���ļ���
	fflush(pfile);//ˢ�»�������������������д���ļ�
	fclose(pfile);//�ر��ļ�
}