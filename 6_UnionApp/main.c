/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 공용체 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union student {
    int num;
    double grade;
};

// 메인함수
int main(void) 
{
    union student s1 = { 315 };

    printf("학번 : %d\n", s1.num); // 315
    printf("학점 : %d\n", s1.grade); // 315
    printf("학점 : %.1lf\n", s1.grade); // 0.0
    s1.grade = 4.4;
    printf("학점 : %.1lf\n", s1.grade); // 4.4
    printf("학번 : %d\n", s1.num); // -1717986918
    
	system("pause");
	return EXIT_SUCCESS;
}
