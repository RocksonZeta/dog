#include <stdio.h>
#include <stdlib.h>
#include "../bone/sqlite.h"
#include "../bone/log.h"
//����ָ�����ļ�
#pragma comment(lib, "dog.lib")
//��ʽDLL��ִ��ģ����Ҳ��������DLL���뺯��

#ifdef __cplusplus
extern "C" {
#endif 
	_declspec(dllexport) int add(int a, int b);
	_declspec(dllimport) int SetHook();
	_declspec(dllimport) int StopHook();
	int main(int argc, char *argv[])
	{
		test_sqlite();
		wlog(L"����");
		
		char YesNo;
		printf("%d,����һ������ȫ�ּ��̹��ӵĲ���...\n", sizeof(void*)* 8);
		printf("��װȫ�ּ��̹���...%d\n",add(1,2));
		SetHook();
		printf("�Ƿ�ж�ؼ��̹���: ��Y or N)\n");
		YesNo = getchar();
		if (YesNo == 'Y' || YesNo == 'y')
		{
			printf("��ʼж�ع���...\n\n");
			StopHook();
			printf("�����Ѿ�ж��...\n");
		}
		
		system("pause");
		
		return 0;
	}

#ifdef __cplusplus
}
#endif 