/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ� // ���ù� �۾�
  --------------------------------------------------------------------------------
  first created - 2020.02.03
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    int a = 0, b = 0;

    if (a > 0)
    {
        b = 1;
    }

    else if (a == 0)
    {
        b = 2;
    }
    
    else
    {
        b = 3;
    }

    printf("b : %d\n", b);

	system("pause");
	return EXIT_SUCCESS;
}