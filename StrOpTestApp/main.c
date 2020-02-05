/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    /*char str1[80] = "strawberry";
    char str2[80] = "apple";
    char* ps1 = "banana";
    char* ps2 = str2;

    printf("최초 문자열 : %s\n", str1);
    strcpy(str1, str2);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps1);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps2);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, "banana");
    printf("바뀐 문자열 : %s\n", str1);*/

    /*char str[20] = "mango tree";
    strncpy(str, "apple-pie", 5);
    printf("%s\n", str);*/

    /*char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);*/

    /*char str1[80], str2[80];
    char* resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);

    printf("과일명 : %s, %s\n", str1, str2);
    printf("길이 : %u, %u\n", strlen(str1), strlen(str2));

    if (strlen(str1) > strlen(str2))
    {
        resp = str1;
    }

    else
    {
        resp = str2;
    }

    printf("이름이 긴 과일은 : %s\n", resp);*/

    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 : ");
    
    if (strcmp(str1, str2) > 0)
    {
        printf("%s\n", str1);
    }

    else
    {
        printf("%s\n", str2);
    }

	system("pause");
	return EXIT_SUCCESS;
}
