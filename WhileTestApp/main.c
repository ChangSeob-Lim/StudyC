/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    while (1)
    {
        printf("���� 2���� �Է��ϼ���.\n(���� �Ͻ÷��� x�� �����ϴ� �ܾ �Է��ϼ���.)\n");

        char str1[80];
        char str2[80];

        scanf("%s%s", str1, str2);

        printf("������ ���� ������ �ܾ� : ");

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
