/*
  filename - main.c
  version - 1.0
  description - 점수를 학점으로 변환하는 함수를 작성하시오. 
                함수 입력 : 0-100 사이의 점수 (정수)
                함수 반환값 : 학점
                A : 90-100
                B : 70-89
                C : 60-69
                D : 50-59
                F : 0-39

  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char func(int score);

// 메인함수
int main(void) 
{
    int score;
    char grade;
    
    while (1)
    {
        printf("0~100 사이의 점수를 입력하세요 : ");
        scanf("%d", &score);

        if (score >= 0 && score <= 100)
        {
            break;
        }
    }

    grade = func(score);

    printf("학점은 %c 입니다.\n", grade);
    
	system("pause");
	return EXIT_SUCCESS;
}

char func(int score)
{
    int temp = score / 10;
    char res;

    switch (temp)
    {
    case 10:
        res = 'A';
        break;
    case 9:
        res = 'A';
        break;
    case 8:
        res = 'B';
        break;
    case 7:
        res = 'B';
        break;
    case 6:
        res = 'C';
        break;
    case 5:
        res = 'D';
        break;
    default:
        res = 'F';
        break;
    }

    return res;
}