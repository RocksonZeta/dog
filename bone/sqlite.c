#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "log.h"
#include "sqlite.h"
#include "str_trans.h"
#include "time.h"

static int db_inited = 0;
sqlite3* db = 0;



int init_db(){
	if (!db_inited){
		db_inited = 1;
	}
	int r = 0;
	char *e = 0;
	char db_file[100] = { 0 };
	GetEnvironmentVariableA("APPDATA", db_file, sizeof(db_file) / sizeof(db_file[0]));
	strcat_s(db_file, 100, "\\ququ");
	CreateDirectoryA(db_file, 0);
	strcat_s(db_file, 100, "\\dog.sqlite");
	r = sqlite3_open(db_file, &db);
	if (r != SQLITE_OK){
		//fprintf(stderr, "Cannot open db: %s\n", sqlite3_e(db));
		return r;
	}
	printf("Open database success \n");
	log("init db");
	return init_schema();

}

int close_db(){
	printf("Close database\n");
	char *e = 0;
	sqlite3_free(e);
	return sqlite3_close(db);
}



static int init_schema(){
	const char* table_message = "create table if not exists messages(id integer primary key  autoincrement, app_name varchar(100),win_name varchar(100),`at` bigint );";
	char *e = 0;
	int r = 0;
	printf("%s\n", table_message);
	
	r = sqlite3_exec(db, table_message, NULL, NULL, &e);
	if (r != SQLITE_OK){
		fprintf(stderr, "create table fail: %s\n", e);
	}
	return r;
}

int save_message(wchar_t w_app_name[], wchar_t w_win_name[]){
	init_db();
	int r = 0;
	char *e = 0;
	char sql_tpl[] = "insert into messages (app_name,win_name,`at`) values ('%s','%s',%I64d)";
	char app_name[100] = { 0 };
	char win_name[100] = { 0 };
	w2m(w_app_name, app_name, 100);
	w2m(w_win_name, win_name, 100);
	//WideCharToMultiByte()
	char sql[213+sizeof(sql_tpl) / sizeof(sql_tpl[0])] = { 0 };
	sprintf_s(sql, 213 + sizeof(sql_tpl) / sizeof(sql_tpl[0]), sql_tpl, app_name, win_name, get_gmt());
	r = sqlite3_exec(db, sql, NULL, NULL, &e);
	if (e){
		printf("exec sql error,sql:%s error:%s\n",sql, e);
	}
	else{
		printf("%s\n", sql);
	}
	return r;

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