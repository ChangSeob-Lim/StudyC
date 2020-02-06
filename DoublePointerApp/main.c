/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    int a = 10;
    int* pi;
    int** ppi;

    pi = &a;
    ppi = &pi;

    printf("-------------------------------------------\n");
    printf("변수   변숫값     &연산     *연산    **연산\n");
    printf("-------------------------------------------\n");
    printf("  a%10d%10p\n", a, &a);
    printf(" pi%10p%10p%10d\n", pi, &pi, *pi);
    printf("ppi%10p%10p%10p%10d\n", ppi, &ppi, *ppi, **ppi);
    
	system("pause");
	return EXIT_SUCCESS;
}
