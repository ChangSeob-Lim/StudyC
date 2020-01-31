#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 증감 연산자
	/*int a = 5, b = 5;
	int pre, post;

	printf("초기값 a: %d, b: %d\n", a, b);

	pre = (++a) * 4;
	post = (b++) * 4;

	printf("pre 결과값 : (++a) * 4 = %d\n", pre);
	printf("post 결과값 : (b++) * 4 = %d\n", post);
	printf("변화값 a: %d, b: %d\n", a, b);*/


	// 관계, 논리 연산자
	int a = 30;
	int res;

	res = (a > 10) && (a < 20);
	printf("(a > 10) && (a < 20) : %d\n", res);
	res = (a > 10) || (a < 20);
	printf("(a > 10) || (a < 20) : %d\n", res);
	res = !(a >= 30);
	printf("!(a >= 30) : %d\n", res);
	
	system("pause");

	return 0;
}