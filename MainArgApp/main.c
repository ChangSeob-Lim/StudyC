/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 콘솔 매개변수 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(int argc, char **argv) 
{
    if (argc <= 1)
    {
        printf("명령 구문이 올바르지 않습니다.\n");
        exit(1);
    }

    char* inparg[2];
    int j = 0;

    for (int i = 0; i < argc; i++)
    {
        if (i == 0)
        {
            continue;
        }

        inparg[j] = (char*)malloc(strlen(argv[i]) + 1);
        strcpy(inparg[j], argv[i]);
        j++;

        //printf("%s\n", argv[i]);
    }

    printf("첫번째 명령인수 : %s\n", inparg[0]);
    printf("두번째 명령인수 : %s\n", inparg[1]);

    for (int i = 0; i < j; i++)
    {
        free(inparg[i]);
    }
    
	system("pause");
	return EXIT_SUCCESS;
}
