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

// 메인함수
int main(void) 
{
    /*int score[3][4];
    int total;
    double avg;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        printf("4과목의 점수 입력 : ");
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &score[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;

        for (j = 0; j < 4; j++)
        {
            total += score[i][j];
        }
        avg = total / 4.0;
        printf("총점 : %d, 평균 : %.2lf\n", total, avg);
    }*/

    int score[3][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%5d", score[i][j]);
        }

        printf("\n");
    }

	system("pause");
	return EXIT_SUCCESS;
}
