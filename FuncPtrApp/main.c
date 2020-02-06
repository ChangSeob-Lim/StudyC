/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 함수 포인터, void 포인터
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

// 메인함수
int main(void) 
{
    /*int (*fp)(int, int);
    int res;
    
    fp = sum;
    res = fp(10, 20);
    printf("result : %d\n", res);*/

    /*int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
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

// 반환형이 동일한 것만 가능함
void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결과값은 : %d\n", res);
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