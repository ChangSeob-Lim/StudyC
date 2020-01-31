#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 형 변환 연산자
	//int a = 20, b = 3;
	//double res;
	//short sh;
	//int in = 2147483647;

	//res = (double)a / b; // (double)a / b; // 6.7 vs 6.0 원하는 로직에 맞춰서 만들기
	//printf("res = %.1lf\n", res);
	//
	//a = (int)res;
	//printf("(int) %.1lf 결과 = %d\n", res, a);

	//sh = in;
	//printf("%d, %d\n", sh, in);

	// 자료형의 크기 sizeof 연산자
	int a = 10;
	double b = 3.14;

	printf("int형 변수의 크기 : %d\n", sizeof(a));
	printf("double형 변수의 크기 : %d\n", sizeof(b));
	printf("정수형 변수의 크기 : %d\n", sizeof(10));
	printf("수식 결과의 크기 : %d\n", sizeof(3.14 + 1.56));
	printf("char 자료형의 크기 : %d\n", sizeof(char));
	printf("long double 자료형의 크기 : %d\n", sizeof(long double));

	system("pause");

	return 0;
}