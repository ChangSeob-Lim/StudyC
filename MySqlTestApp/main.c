/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, MySQL 연결 테스트
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")

#define MYSQLUSER "root" // if
#define MYSQLPASSWORD "mysql_p@ssw0rd" // password
#define MYSQLIP "localhost"

void loadmysql(char mysqlip[], MYSQL* cons);

// 메인함수
int main(void) 
{
    //printf("MySQL info is %s\n", mysql_get_client_info());
    
    MYSQL* cons = mysql_init(NULL); // MYSQL 연결 초기화
    MYSQL_RES* res;
    MYSQL_ROW row;
    int fields;

    loadmysql(MYSQLIP, cons);
    printf("\n");

    mysql_query(cons, "use shopdb;");
    mysql_query(cons, "SELECT * FROM membertbl;");
    res = mysql_store_result(cons);
    fields = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        for (int i = 0; i < fields; i++)
        {
            printf("%s", row[i]);

            if (i < fields)
            {
                printf("\t");
            }
        }

        printf("\n");
    }

    mysql_free_result(res);
    mysql_close(cons);

	system("pause");
	return EXIT_SUCCESS;
}

void loadmysql(char mysqlip[], MYSQL* cons)
{
    if (cons == NULL) // cons가 초기화를 못했으면
    {
        fprintf(stderr, "%s\n", mysql_error(cons));
        Sleep(1000);
        exit(EXIT_FAILURE);
    }
    
    if (mysql_real_connect(cons, mysqlip, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) != NULL) // mysql서버로 연결 성공하면 0 아니면 다른수 반환
    {
        printf("성공\n");
        mysql_set_character_set(cons, "euckr"); // MySQL 문자를 한글로 지정
    }

    else
    {
        fprintf(stderr, "연결 오류 : %s\n", mysql_error(cons));
        getchar();
    }
}
