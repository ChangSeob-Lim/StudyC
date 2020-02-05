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

void auto_func(void);
void static_func(void);

// �����Լ�
int main(void) 
{
    /*printf("�Ϲ� �������� �Լ�...\n");
    for (int i = 0; i < 3; i++)
    {
        auto_func();
    }

    printf("���� �������� �Լ�...\n");
    for (int i = 0; i < 3; i++)
    {
        static_func();
    }*/

    register int i;
    int sum = 0;
    
    for (i = 0; i < 10000; i++)
    {
        sum += i;
    }
    printf("sum is %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

void auto_func(void)
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;

    a++;
    printf("%d\n", a);
}
