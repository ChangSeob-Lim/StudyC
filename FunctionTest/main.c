/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y);

// 메인함수
int main(void) 
{
    int a = 10, b = 20;
    int result;

    result = sum(a, b);
    printf("result : %d\n", result);

	system("pause");
	return EXIT_SUCCESS;
}

int sum(int x, int y)
{
    int temp;

    temp = x + y;

    return temp;
}