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
    //int ary[5]; // 초기화 ary[100] = {0}; 으로 가능

    //ary[0] = 10;
    //ary[1] = 20;
    //ary[2] = ary[0] + ary[1];

    //scanf("%d\n", &ary[3]);

    //printf("%d\n", ary[2]);
    //printf("%d\n", ary[3]);
    //printf("%d\n", ary[4]);

    int score[5];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score) / sizeof(score[0]);

    for (i = 0; i < count; i++)
    {
        scanf("%d", &score[i]);
    }

    for (i = 0; i < count; i++)
    {
        total += score[i];
    }

    avg = total / (double)count;

    for (i = 0; i < count; i++)
    {
        printf("%5d", score[i]);
    }
    printf("\n");

    printf("평균 : %.1lf\n", avg);

	system("pause");
	return EXIT_SUCCESS;
}