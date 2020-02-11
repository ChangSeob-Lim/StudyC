/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, Pragma 지시자
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4101)
#pragma pack(push, 1)

typedef struct sample1
{
    char ch;
    int in;
}Sample1;

#pragma pack(pop)

typedef struct sample2
{
    char ch;
    int in;
}Sample2;

// 메인함수
int main(void) 
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	system("pause");
	return EXIT_SUCCESS;
}
