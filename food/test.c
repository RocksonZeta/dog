#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bone/sqlite.h"
#include "../bone/log.h"
//����ָ�����ļ�
//#pragma comment(lib, "dog.lib")
//��ʽDLL��ִ��ģ����Ҳ��������DLL���뺯��

_declspec(dllexport) int add(int a, int b);
_declspec(dllimport) int SetHook();
_declspec(dllimport) int StopHook();

void setup_hook(){
	char YesNo;
	printf("%d,����һ������ȫ�ּ��̹��ӵĲ���...\n", sizeof(void*)* 8);
	printf("��װȫ�ּ��̹���...%d\n", add(1, 2));
	SetHook();
	printf("�Ƿ�ж�ؼ��̹���: ��Y or N)\n");
	YesNo = getchar();
	if (YesNo == 'Y' || YesNo == 'y')
	{
		printf("��ʼж�ع���...\n\n");
		StopHook();
		printf("�����Ѿ�ж��...\n");
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
