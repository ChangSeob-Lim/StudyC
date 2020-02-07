/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ����� ���� �ڷ��� structure �н�
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
    //struct profile pf; // 3��° ������ �� Ǯ�� �ʱ�ȭ ����
    int id;
    char name[20];
    double grade;
};

// �����Լ�
int main(void) 
{
    /*struct student s1;

    s1.id = 11;
    s1.grade = 4.5;

    printf("�й� : %d\n", s1.id);
    printf("���� : %.1lf\n", s1.grade);*/

    /*struct profile p1;

    strcpy(p1.name, "��â��");
    p1.age = 25;
    p1.height = 175;

    p1.intro = (char*)malloc(80);
    printf("�ڱ�Ұ� : ");
    gets(p1.intro);

    printf("�̸� : %s\n", p1.name);
    printf("���� : %d\n", p1.age);
    printf("Ű : %.1lf\n", p1.height);
    printf("�ڱ�Ұ� : %s\n", p1.intro);

    free(p1.intro);*/

    /*struct student s1;

    s1.pf.age = 25;
    s1.pf.height = 175;
    s1.id = 71008049;
    s1.grade = 4;

    printf("���� : %d\n", s1.pf.age);
    printf("Ű : %.1lf\n", s1.pf.height);
    printf("�й� : %d\n", s1.id);
    printf("���� : %.1lf\n", s1.grade);*/

    struct student s1 = { 315, "ȫ�浿", 2.4 }, s2 = { 316, "�̼���", 3.7 }, s3 = { 317, "�������", 4.4 };

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

    printf("�й� : %d\n", max.id);
    printf("�̸� : %s\n", max.name);
    printf("���� : %.1lf\n", max.grade);

	system("pause");
	return EXIT_SUCCESS;
}
