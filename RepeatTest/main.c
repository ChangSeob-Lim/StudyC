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

// 메인함수
int main(void) 
{
    /*int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("*");
        }
        printf("\n");
    }*/

    int i;
    int sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum += i;
        if (sum > 30)
        {
            break;
        }
    }

    printf("누적한 값 : %d\n", sum);
    printf("마지막으로 더한 값 : %d\n", i);

	system("pause");
	return EXIT_SUCCESS;
}