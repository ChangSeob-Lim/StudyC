/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 파일 버퍼 에러
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    /*FILE* fp;
    int age;
    char name[20];
    int i;

    fp = fopen("a.txt", "r");

    if (fp == NULL)
    {
        printf("파일을 읽을 수 없습니다.\n");
        return EXIT_FAILURE;
    }

    fscanf(fp, "%d", &age); fgetc(fp);
    fgets(name, sizeof(name), fp);

    for (i = 0; i < 20; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
        }
    }

    printf("이름 : %s, 나이 : %d\n", name, age);

    fclose(fp);*/

    FILE* afp, * bfp;
    int num = 213456;
    int res;

    afp = fopen("aa.txt", "wt");
    if (afp == NULL)
    {
        return EXIT_FAILURE;
    }
    fprintf(afp, "%d", num);

    bfp = fopen("bb.txt", "wb");
    if (bfp == NULL)
    {
        return EXIT_FAILURE;
    }
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("bb.txt", "rb");
    if (bfp == NULL)
    {
        return EXIT_FAILURE;
    }
    fread(&res, sizeof(res), 1, bfp);
    printf("%d\n", res);

    fclose(bfp);
    
	system("pause");
	return EXIT_SUCCESS;
}
