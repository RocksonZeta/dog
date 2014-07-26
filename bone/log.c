#include <stdio.h>
#include <string.h>

#include "log.h"

void log(char* s){
	FILE *pfile;
	fopen_s(&pfile,"c:\\hook.log", "a");//以写的方式打开C.txt文件。
	fwrite(s, 1, strlen(s), pfile);//将数据写入文件。
	fflush(pfile);//刷新缓冲区。将缓冲区数据写入文件
	fclose(pfile);//关闭文件
}

void wlog(const wchar_t* s){
	FILE *pfile;
	fopen_s(&pfile, "c:\\hook.log", "a");//以写的方式打开C.txt文件。
	fwprintf(pfile, s);
	//fwrite(s, 1, strlen(s), pfile);//将数据写入文件。
	fflush(pfile);//刷新缓冲区。将缓冲区数据写入文件
	fclose(pfile);//关闭文件
}