/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ���� �н�
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    int num, grade;

    printf("�й� �Է� : ");
    scanf("%d", &num);
    getchar();
    printf("���� �Է� : ");
    grade = getchar();

    printf("�й� : %d, ���� : %c\n", num, grade);
        
	system("pause");
	return EXIT_SUCCESS;
}