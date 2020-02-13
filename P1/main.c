/*
  filename - main.c
  version - 1.0
  description - 1부터 300사이의 숫자(정수) 중에서 3의 공배수(3,6,9,12,..)들의 총합을 출력하는 프로그램을 작성하시오. (for문 사용)
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    int sum = 0;

    for (int i = 1; i < 301; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        }
    }

    printf("1부터 300 사이의 3의 공배수들의 총합 = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
