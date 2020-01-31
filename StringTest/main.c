#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char fruit[20] = "strawberry";

	printf("µþ±â : %s\n", fruit);
	printf("µþ±â Â´ : %s %s\n", fruit, "jam");
	strcpy(fruit, "water melons");
	printf("ÀÌ¹ø °úÀÏ : %s\n", fruit);

	system("pause");

	return 0;
}