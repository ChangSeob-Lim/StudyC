/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ���� ���� ������ ���� �׽�Ʈ
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assign10(void);
void assign20(void);

int a;

// �����Լ�
int main(void) 
{
    /*int a = 10, b = 20;
    printf("��ȯ�� : %d, %d\n", a, b);
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    printf("��ȯ�� : %d, %d\n", a, b);*/

    printf("a�� �� : %d\n", a);
    assign10();
    assign20();
    printf("a�� �� : %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

void assign10(void)
{
    a = 10;
    
    printf("assign a�� �� : %d\n", a);

    return;
}

void assign20(void)
{
    int a = 0;
    a = 20;

    printf("assign a�� �� : %d\n", a);

    return;
}