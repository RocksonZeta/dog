#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>
#include "sqlite.h"


sqlite3* db = 0;

void init_db(){
	int r = 0;
	char *e = 0;
	r = sqlite3_open("./ququ.db", &db);
	if (r != SQLITE_OK){
		//fprintf(stderr, "Cannot open db: %s\n", sqlite3_e(db));
		return ;
	}
	printf("Open database success \n");


}

void close_db(){
	printf("Close database\n");
	char *e = 0;
	sqlite3_free(e);
	sqlite3_close(db);
}



void init_schema(){
	const char* table_message = "drop table if exists messages;create table messages(id int primary key  auto_increment, app_name varchar(100),win_name varchar(100),`at` bigint );";
	char *e = 0;
	int r = 0;
	printf("%s\n", table_message);
	
	r = sqlite3_exec(db, table_message, NULL, NULL, &e);
	if (r != SQLITE_OK){
		fprintf(stderr, "create table fail: %s\n", e);
	}
}

void save_message(message m){
	int r = 0;
	char *e = 0;
	char* sql_tpl = "insert messages (app_name,win_name,`at`) values (%s,%s,%l)";
	char sql[sizeof(message) + 58] = { 0 };
	sprintf_s(sql, sizeof(message)+58, sql_tpl, m.app_name, m.win_name, m.at);
	r = sqlite3_exec(db, sql, NULL, NULL, &e);

	#ifdef DEBUG
	printf("sql %s\n", r == SQLITE_OK ? "OK" : "FAIL");
	#endif // DEBUG
}

message* get_messages(char type){
	char * sql_tpl = "select * from messages where ";
	if (0 == type){
		return NULL;
	}


	return NULL;

}

void test_sqlite(){
	const char *sql_create_table = "create table t(id int primary key,msg varchar(128))";
	char *e = 0;
	int r = 0;

	sqlite3 *db = 0;
	r = sqlite3_open("./sqlite3-demo.db", &db);
	if (r != SQLITE_OK){
		//fprintf(stderr, "Cannot open db: %s\n", sqlite3_e(db));
		return;
	}
	printf("Open database\n");

	r = sqlite3_exec(db, sql_create_table, NULL, NULL, &e);
	if (r != SQLITE_OK){
		fprintf(stderr, "create table fail: %s\n", e);
	}
	sqlite3_free(e);
	sqlite3_close(db);

	printf("Close database\n");
	return;
}