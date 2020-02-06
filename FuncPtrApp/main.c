/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, �Լ� ������, void ������
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int big(int a, int b);

// �����Լ�
int main(void) 
{
    /*int (*fp)(int, int);
    int res;
    
    fp = sum;
    res = fp(10, 20);
    printf("result : %d\n", res);*/

    /*int sel;

    printf("01 �� ������ ��\n");
    printf("02 �� ������ ��\n");
    printf("03 �� ���� �߿��� ū �� ���\n");
    printf("���ϴ� ������ �����ϼ��� : ");
    scanf("%d", &sel);

    switch (sel)
    {
    case 1:
        func(sum);
        break;
    case 2:
        func(mul);
        break;
    case 3:
        func(big);
        break;
    }*/
    
    int a = 10;
    double b = 3.5;
    void* vp;

    vp = &a;
    printf("a : %d\n", *(int*)vp);

    vp = &b;
    printf("b : %.1lf\n", *(double*)vp);

	system("pause");
	return EXIT_SUCCESS;
}

// ��ȯ���� ������ �͸� ������
void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("�� ������ ���� �Է��ϼ��� : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("������� : %d\n", res);
}

int sum(int a, int b)
{
    int res = (a + b);
    return res;
}

int mul(int a, int b)
{
    int res = (a * b);
    return res;
}

int big(int a, int b)
{
    int res;

    if (a > b)
    {
        res = a;
    }

    else
    {
        res = b;
    }
    return res;
}