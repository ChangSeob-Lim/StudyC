/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ���� ���� ����
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    /*FILE* fp;
    int age;
    char name[20];
    int i;

    fp = fopen("a.txt", "r");

    if (fp == NULL)
    {
        printf("������ ���� �� �����ϴ�.\n");
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

    printf("�̸� : %s, ���� : %d\n", name, age);

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
