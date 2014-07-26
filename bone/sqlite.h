
#include <stdlib.h>

typedef struct message_t {
	int id;
	char app_name[100];
	char win_name[100];
	long at;
} message, *pmessage;


void test_sqlite();

void init_db();
void close_db();
void init_schema();
void save_message(message m);
message* get_messages(char type);

