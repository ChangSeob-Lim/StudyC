#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Be happy\n");
	printf("12345678901234567890\n");
	printf("My\tfriend\n");
	printf("Goot\bd\tchance\n");

	printf("Cow\rW\a\n");
	// \t - 탭 \b 커서를 한칸 앞으로 \r - 커서를 맨 앞으로 \a - 경고음
	system("pause");

	return 0;
}