/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 문자 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);
    getchar();
    printf("학점 입력 : ");
    grade = getchar();

    printf("학번 : %d, 학점 : %c\n", num, grade);
        
	system("pause");
	return EXIT_SUCCESS;
}