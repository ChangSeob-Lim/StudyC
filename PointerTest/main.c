/*
  filename - main.c
  version - 1.0
  description - Pointer
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    //char ch = 'A';
    //int in = 10;
    //double db = 10.4;

    //char* pc = &ch;
    //int* pi = &in;
    //double* pd = &db;

    //// 변수 크기
    //printf("ch size : %u\n", sizeof(ch));
    //printf("in size : %u\n", sizeof(in));
    //printf("db size : %u\n", sizeof(db));
    //printf("\n");

    //// 변수 주소 크기
    //printf("&ch size : %u\n", sizeof(&ch));
    //printf("&in size : %u\n", sizeof(&in));
    //printf("&db size : %u\n", sizeof(&db));
    //printf("\n");

    //// 포인터 크기
    //printf("pc size : %u\n", sizeof(pc));
    //printf("pi size : %u\n", sizeof(pi));
    //printf("pd size : %u\n", sizeof(pd));
    //printf("\n");

    //// 포인터 값 크기
    //printf("*pc size : %u\n", sizeof(*pc));
    //printf("*pi size : %u\n", sizeof(*pi));
    //printf("*pd size : %u\n", sizeof(*pd));
    //printf("\n");

    int a = 10;
    int* pa = &a;
    double* pd = pa;

    printf("a : %d\n", a);
    printf("pa : %d\n", *pa);
    printf("pd : %lf\n", *pd);

	system("pause");
	return EXIT_SUCCESS;
}