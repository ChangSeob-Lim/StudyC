/*
  filename - main.c
  version - 1.0
  description - �л� 3���� �б޿��� ���� ���� ���� ������ ���� ������ �Է� ���� ��,  �� ���� ���հ� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ����, ����, ���� ������ ����� �ϴ� ����ü student_t �� �����Ѵ�. �л��� 3���̹Ƿ� student_t Ÿ���� ���� 3��, Ȥ�� �迭�� �����Ͽ�, �ش� ������ ������ �Է¹޴´�. �� ������ ������ ���ϴ� �Լ��� ���� �ۼ��Ͽ� ���հ� ����� ���� �� �̸� ����Ѵ�.

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

// �����Լ�
int main(void) 
{
    student_t s[3];
    
    printf("3���� �л��� ����, ����, ������ ���� ������ �Է��ϼ���\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d��° �л��� ����, ����, ������ ���� ���� : ", i);

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

    printf("��������� ����, ��� : %d, %.2lf\n", sumK, avg(sumK));
    printf("��������� ����, ��� : %d, %.2lf\n", sumE, avg(sumE));
    printf("���а����� ����, ��� : %d, %.2lf\n", sumM, avg(sumM));
}

double avg(int sum)
{
    return sum / 3.0;
}
