/**
set up windows hook
*/
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "house.h"
#include "../bone/log.h"

_declspec(dllexport) int watch64();
_declspec(dllexport) int unwatch64();
_declspec(dllexport) int init64();



int main(int argc, char** argv){
	wchar_t home_dir[100] = { 0 };
	GetEnvironmentVariable(L"APPDATA", home_dir, sizeof(home_dir)/sizeof(home_dir[0]));
	wprintf(L"use dir:%s\n",home_dir );
	printf("init dog64 status:%d\n",init64());
	watch64();
	int cmd =-1;
	while (1){
		cmd = getchar();
		if ('y' ==  cmd){
			unwatch64();
			break;
		}
		
	}
	system("pause");
	return 0;
}



