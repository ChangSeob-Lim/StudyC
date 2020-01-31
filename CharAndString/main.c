#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%c\n", 'A');
	printf("%s\n", "ABC");
	printf("%c is sub of %s\n", 'a', "abc");
	printf("A=%d & Z=%d\n", 'A', 'Z'); // A 65 Z 90
	printf("a=%d & z=%d\n", 'a', 'z'); // a 97 z 122
	
	system("pause");

	return 0;
}