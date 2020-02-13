/*
  filename - main.c
  version - 1.0
  description - ������ �������� ��ȯ�ϴ� �Լ��� �ۼ��Ͻÿ�. 
                �Լ� �Է� : 0-100 ������ ���� (����)
                �Լ� ��ȯ�� : ����
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

// �����Լ�
int main(void) 
{
    int score;
    char grade;
    
    while (1)
    {
        printf("0~100 ������ ������ �Է��ϼ��� : ");
        scanf("%d", &score);

        if (score >= 0 && score <= 100)
        {
            break;
        }
    }

    grade = func(score);

    printf("������ %c �Դϴ�.\n", grade);
    
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