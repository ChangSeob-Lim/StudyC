/*
  filename - main.c
  version - 1.0
  description - 학생 3명의 학급에서 각각 국어 영어 수학의 시험 성적을 입력 받은 후,  각 과목 총합과 평균을 출력하는 프로그램을 작성하시오. 먼저 국어, 영어, 수학 성적을 멤버로 하는 구조체 student_t 를 정의한다. 학생이 3명이므로 student_t 타입의 변수 3개, 혹은 배열을 정의하여, 해당 변수에 성적을 입력받는다. 각 과목의 총합을 구하는 함수를 각각 작성하여 총합과 평균을 구한 후 이를 출력한다.

  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int kor;
    int eng;
    int math;
}student_t;

void sum(student_t* s);
double avg(int sum);

// 메인함수
int main(void) 
{
    student_t s[3];
    
    printf("3명의 학생의 국어, 영어, 수학의 시험 성적을 입력하세요\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d번째 학생의 국어, 영어, 수학의 시험 성적 : ", i);

        scanf("%d%d%d", &s[i].kor, &s[i].eng, &s[i].math);
    }

    sum(s);
    
	system("pause");
	return EXIT_SUCCESS;
}

void sum(student_t* s)
{
    int sumK = 0, sumE = 0, sumM = 0;
    
    for (int i = 0; i < 3; i++)
    {
        sumK += s[i].kor;
        sumE += s[i].eng;
        sumM += s[i].math;
    }

    printf("국어과목의 총합, 평균 : %d, %.2lf\n", sumK, avg(sumK));
    printf("영어과목의 총합, 평균 : %d, %.2lf\n", sumE, avg(sumE));
    printf("수학과목의 총합, 평균 : %d, %.2lf\n", sumM, avg(sumM));
}

double avg(int sum)
{
    return sum / 3.0;
}
