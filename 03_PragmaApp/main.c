/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, Pragma ������
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

// �����Լ�
int main(void) 
{
    printf("Sample1 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample1));
    printf("Sample2 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample2));

	system("pause");
	return EXIT_SUCCESS;
}
