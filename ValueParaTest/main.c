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

void add_ten2(int *pa);
int add_ten(int a);

int* sum(int a, int b);

// 메인함수
int main(void) 
{
    /*int a = 10;

    add_ten2(&a);
    printf("a : %d\n", a);

    int res = add_ten(a);
    printf("res : %d\n", res);*/

    int a = 10, b = 20;
    int* res = sum(a, b);
    printf("합 = %d\n", *res);

	system("pause");
	return EXIT_SUCCESS;
}

void add_ten2(int* pa)
{
    *pa = *pa + 10;
}

int add_ten(int a)
{
    return a + 10;
}

int* sum(int a, int b)
{
    static int res;
    res = a + b;
    return &res;
}