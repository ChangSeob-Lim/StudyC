/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ����ü �н�
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

// �����Լ�
int main(void) 
{
    union student s1 = { 315 };

    printf("�й� : %d\n", s1.num); // 315
    printf("���� : %d\n", s1.grade); // 315
    printf("���� : %.1lf\n", s1.grade); // 0.0
    s1.grade = 4.4;
    printf("���� : %.1lf\n", s1.grade); // 4.4
    printf("�й� : %d\n", s1.num); // -1717986918
    
	system("pause");
	return EXIT_SUCCESS;
}
