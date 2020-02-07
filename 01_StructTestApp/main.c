/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 사용자 정의 자료형 structure 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

struct profile
{
    char name[20];
    int age;
    double height;
    char* intro;
};

struct student
{
    //struct profile pf; // 3번째 예제할 때 풀기 초기화 문제
    int id;
    char name[20];
    double grade;
};

// 메인함수
int main(void) 
{
    /*struct student s1;

    s1.id = 11;
    s1.grade = 4.5;

    printf("학번 : %d\n", s1.id);
    printf("학점 : %.1lf\n", s1.grade);*/

    /*struct profile p1;

    strcpy(p1.name, "임창섭");
    p1.age = 25;
    p1.height = 175;

    p1.intro = (char*)malloc(80);
    printf("자기소개 : ");
    gets(p1.intro);

    printf("이름 : %s\n", p1.name);
    printf("나이 : %d\n", p1.age);
    printf("키 : %.1lf\n", p1.height);
    printf("자기소개 : %s\n", p1.intro);

    free(p1.intro);*/

    /*struct student s1;

    s1.pf.age = 25;
    s1.pf.height = 175;
    s1.id = 71008049;
    s1.grade = 4;

    printf("나이 : %d\n", s1.pf.age);
    printf("키 : %.1lf\n", s1.pf.height);
    printf("학번 : %d\n", s1.id);
    printf("학점 : %.1lf\n", s1.grade);*/

    struct student s1 = { 315, "홍길동", 2.4 }, s2 = { 316, "이순신", 3.7 }, s3 = { 317, "세종대왕", 4.4 };

    struct student max;

    max = s1;

    if (s2.grade > max.grade)
    {
        max = s2;
    }

    if (s3.grade > max.grade)
    {
        max = s3;
    }

    printf("학번 : %d\n", max.id);
    printf("이름 : %s\n", max.name);
    printf("학점 : %.1lf\n", max.grade);

	system("pause");
	return EXIT_SUCCESS;
}
