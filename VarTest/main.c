#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	short sh = 32767;
	int in = 21478367;
	long ln = 2147483647;
	long long lln = 12345678912345;
	unsigned int ui = 4294967294;

	printf("short �ִ밪 %d\n", sh);
	printf("int �ִ밪 %d\n", in);
	printf("long �ִ밪 %ld\n", ln);
	printf("longlong �ִ밪 %lld\n", lln);

	printf("unsigned int �ִ밪 %u\n", ui);
	ui = -1;
	printf("unsigned int ���簪 %u\n", ui);

	system("pause");

	return 0;
}