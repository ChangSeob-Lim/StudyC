/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ���� ���� �н�
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
    int ch, i = 0;
    char str[] = "banana";

    fp = fopen("b.txt", "w");

    if (fp == NULL)
    {
        printf("������ �������� �ʾҽ��ϴ�.\n");
        return EXIT_FAILURE;
    }

    printf("������ ���Ƚ��ϴ�.\n");

    while(str[i]!='\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);

    fclose(fp);*/

    /*int ch;

    while (1)
    {
        ch = fgetc(stdin);

        if (ch == EOF)
        {
            break;
        }

        fputc(ch, stdout);
    }*/

    /*FILE* fp;
    int ary[10] = { 65,66,67,68,26,69,70,71,72,73 };
    int i, res;

    fp = fopen("a.txt", "wb");

    for (i = 0; i < 10; i++)
    {
        fputc(ary[i], fp);
    }

    fclose(fp);

    fp = fopen("a.txt", "rt");

    while (1)
    {
        res = fgetc(fp);
        if (res == EOF)
        {
            break;
        }

        printf("%4d", res);
    }
    printf("\n");

    fclose(fp);*/

    FILE* fp;
    char str[20];
       
    fp = fopen("d.txt", "a+");
    if (fp == NULL)
    {
        printf("FILE Open Error\n");
        return EXIT_FAILURE;
    }

    while (1)
    {
        printf("���� �̸� : ");
        scanf("%s", str);
        
        if (strcmp(str, "end") == 0)
        {
            break;
        }

        else if (strcmp(str, "list") == 0)
        {
            rewind(fp);//fseek(fp, 0, SEEK_SET);

            while (1)
            {
                fgets(str, sizeof(str), fp);

                if (feof(fp))
                {
                    break;
                }

                printf("%s", str);
            }
        }

        else
        {
            fprintf(fp, "%s\n", str);
        }
    }

    fclose(fp);
    
	system("pause");
	return EXIT_SUCCESS;
}
