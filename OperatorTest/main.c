#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ���� ������
	/*int a = 5, b = 5;
	int pre, post;

	printf("�ʱⰪ a: %d, b: %d\n", a, b);

	pre = (++a) * 4;
	post = (b++) * 4;

	printf("pre ����� : (++a) * 4 = %d\n", pre);
	printf("post ����� : (b++) * 4 = %d\n", post);
	printf("��ȭ�� a: %d, b: %d\n", a, b);*/


	// ����, �� ������
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