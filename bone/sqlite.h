
#include <stdlib.h>
#include <tchar.h>

typedef struct message_t {
	int id;
	TCHAR app_name[100];
	TCHAR win_name[100];
	long at;
} message, *pmessage;


void test_sqlite();

int init_db();
int close_db();
int init_schema();
int save_message(wchar_t app_name[], wchar_t win_name[]);
message* get_messages(char type);

