/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, �ܼ� �Ű����� �н�
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(int argc, char **argv) 
{
    if (argc <= 1)
    {
        printf("��� ������ �ùٸ��� �ʽ��ϴ�.\n");
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

    printf("ù��° ����μ� : %s\n", inparg[0]);
    printf("�ι�° ����μ� : %s\n", inparg[1]);

    for (int i = 0; i < j; i++)
    {
        free(inparg[i]);
    }
    
	system("pause");
	return EXIT_SUCCESS;
}
