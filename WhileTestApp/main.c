/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    while (1)
    {
        printf("글자 2개를 입력하세요.\n(종료 하시려면 x로 시작하는 단어를 입력하세요.)\n");

        char str1[80];
        char str2[80];

        scanf("%s%s", str1, str2);

        printf("사전에 먼저 나오는 단어 : ");

        if (strcmp(str1, str2) < 0)
        {
            printf("%s\n", str1);
        }

        else
        {
            printf("%s\n", str2);
        }

        if (str1[0] == 'x' || str1[0] == 'X' || str2[0] == 'x' || str2[0] == 'X')
        {
            break;
        }
    }

	system("pause");
	return EXIT_SUCCESS;
}
