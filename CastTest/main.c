#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// �� ��ȯ ������
	//int a = 20, b = 3;
	//double res;
	//short sh;
	//int in = 2147483647;

	//res = (double)a / b; // (double)a / b; // 6.7 vs 6.0 ���ϴ� ������ ���缭 �����
	//printf("res = %.1lf\n", res);
	//
	//a = (int)res;
	//printf("(int) %.1lf ��� = %d\n", res, a);

	//sh = in;
	//printf("%d, %d\n", sh, in);

	// �ڷ����� ũ�� sizeof ������
	int a = 10;
	double b = 3.14;

	printf("int�� ������ ũ�� : %d\n", sizeof(a));
	printf("double�� ������ ũ�� : %d\n", sizeof(b));
	printf("������ ������ ũ�� : %d\n", sizeof(10));
	printf("���� ����� ũ�� : %d\n", sizeof(3.14 + 1.56));
	printf("char �ڷ����� ũ�� : %d\n", sizeof(char));
	printf("long double �ڷ����� ũ�� : %d\n", sizeof(long double));

	system("pause");

	return 0;
}