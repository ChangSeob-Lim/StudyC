/*
  filename - main.c
  version - 1.0
  description - PointerTest
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    // ������ ����
    //int a = 0;
    //int *pa;

    //pa = &a;
    ////*pa = 10;

    ////scanf("%d", &a);
    //scanf("%d", pa);
    //printf("%d\n", a);

    int a = 10, b = 20, total;
    double avg;
    int* pa, * pb;
    int* pt = &total;
    double* pg = &avg;

    pa = &a;
    pb = &b;

    *pt = *pa + *pb;
    *pg = *pt / 2.0;

    printf("�� ������ : %d, %d\n", *pa, *pb);
    printf("�� : %d\n", *pt);
    printf("��� : %.1lf\n", *pg);

	system("pause");
	return EXIT_SUCCESS;
}