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
	init_schema();

}

void close_db(){
	printf("Close database\n");
	char *e = 0;
	sqlite3_free(e);
	sqlite3_close(db);
}



void init_schema(){
	const char* table_message = "create table if not exists messages(id integer primary key  autoincrement, app_name varchar(100),win_name varchar(100),`at` bigint );";
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
	char sql_tpl[] = "insert into messages (app_name,win_name,`at`) values ('%s','%s',%d)";
	char sql[sizeof(message)+sizeof(sql_tpl) / sizeof(sql_tpl[0])] = { 0 };
	sprintf_s(sql, sizeof(message)+sizeof(sql_tpl) / sizeof(sql_tpl[0]), sql_tpl, m.app_name, m.win_name, m.at);
	r = sqlite3_exec(db, sql, NULL, NULL, &e);
	if (e){
		printf("exec sql error,sql:%s error:%s\n",sql, e);
	}
	else{
		printf("%s\n", sql);
	}

}

message* get_messages(char type){
	char * sql = "select * from messages";
	char** result = 0;		//二维数组存放结果 
	int nrow, ncol;
	int i = 0,j=0;
	char* e = 0;
	sqlite3_get_table(db, sql, &result, &nrow, &ncol,&e);
	printf("row:%d column=%d \n", nrow, ncol);
	for (i = 0; i < (nrow + 1) * ncol; i++){
		printf("%-10s", result[i]);
		if (0 == (i+1)%(ncol)){
			printf("\n");
		}
	}
	sqlite3_free_table(result);
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