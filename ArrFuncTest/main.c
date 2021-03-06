/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수 & 배열을 처리하는 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>

void print_ary(int* pa, int size);
//void print_ary(int ary[]);

// 메인함수
int main(void) 
{
    int ary1[5] = { 10,20,30,40,50 };
    int ary2[7] = { 10,20,30,40,50,60,70 };
    int size = 0;

    size = sizeof(ary1) / sizeof(ary1[0]);
    print_ary(ary1, size);
    //print_ary(&ary[0]);
    size = sizeof(ary2) / sizeof(ary2[0]);
    print_ary(ary2, size);

	system("pause");
	return EXIT_SUCCESS;
}

// 배열 출력함수
void print_ary(int* pa, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%5d", pa[i]);
    }
    printf("\n");
}