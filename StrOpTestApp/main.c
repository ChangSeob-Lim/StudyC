/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    /*char str1[80] = "strawberry";
    char str2[80] = "apple";
    char* ps1 = "banana";
    char* ps2 = str2;

    printf("���� ���ڿ� : %s\n", str1);
    strcpy(str1, str2);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, ps1);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, ps2);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, "banana");
    printf("�ٲ� ���ڿ� : %s\n", str1);*/

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

    printf("2���� ���� �̸� �Է� : ");
    scanf("%s%s", str1, str2);

    printf("���ϸ� : %s, %s\n", str1, str2);
    printf("���� : %u, %u\n", strlen(str1), strlen(str2));

    if (strlen(str1) > strlen(str2))
    {
        resp = str1;
    }

    else
    {
        resp = str2;
    }

    printf("�̸��� �� ������ : %s\n", resp);*/

    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("������ ���߿� ������ ���� �̸� : ");
    
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