#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bone/sqlite.h"
#include "../bone/log.h"
//链接指定库文件
//#pragma comment(lib, "dog.lib")
//隐式DLL可执行模块中也必须声明DLL导入函数

_declspec(dllexport) int add(int a, int b);
_declspec(dllimport) int SetHook();
_declspec(dllimport) int StopHook();

void setup_hook(){
	char YesNo;
	printf("%d,这是一个关于全局键盘钩子的测试...\n", sizeof(void*)* 8);
	printf("安装全局键盘钩子...%d\n", add(1, 2));
	SetHook();
	printf("是否卸载键盘钩子: （Y or N)\n");
	YesNo = getchar();
	if (YesNo == 'Y' || YesNo == 'y')
	{
		printf("开始卸载钩子...\n\n");
		StopHook();
		printf("钩子已经卸载...\n");
	}

}


int main(int argc, char *argv[])
{
	init_db();
	message m = { 0 };
	strcpy_s(m.app_name,5, "app2");
	strcpy_s(m.win_name,5, "win2");
	m.at = 10000;
	save_message(m);
	get_messages('1');
	
	close_db();
	system("pause");
		
	return 0;
}
