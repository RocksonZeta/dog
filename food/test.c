#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>
#include "../bone/sqlite.h"
#include "../bone/log.h"
#include "../bone/str_trans.h"
#include "../bone/time.h"

void test_db(){
	init_db();
	message m = { 0 };
	//wcscpy_s(m.app_name, 5, L"��������");
	//wcscpy_s(m.win_name, 4, L"���μ�");
	//strcpy_s(m.app_name, 5, "app2");
	//strcpy_s(m.win_name, 5, "win2");
	m.at = get_gmt();
	save_message(L"��������", L"���μ�");
	get_messages('1');

	close_db();
}

void test_bark(){
	
}

void test_str_trans(){
	LPTSTR s = _T("���");
	char b[20] = { 0 };
	w2m(s, b, 20);
	printf("%s,l:%d\n", b, strlen(b));
}

int main(int argc, char *argv[])
{
	//test_bark();
	//setup_hook();
	//test_str_trans();
	test_db();
	system("pause");
		
	return 0;
}
