/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, typedef를 이용한 재정의
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int num;
    double grade;
};

typedef struct student Student;
void print_data(Student* ps);

// 메인함수
int main(void)
{
    Student s1 = { 315, 4.2 };

    print_data(&s1);

    system("pause");
    return EXIT_SUCCESS;
}

void print_data(Student* ps)
{
    printf("학번 : %d\n", ps->num);
    printf("학점 : %.1lf\n", ps->grade);
}
