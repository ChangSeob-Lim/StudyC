/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    int rank = 2, m = 0;

    switch (rank)
    {
    case 1:
        m = 300;
        break;
    case 2:
        m = 200;
        break;
    case 3:
        m = 100;
        break;
    defalut:
        m = 10;
        break;
    }

    printf("m : %d\n", m);

	system("pause");
	return EXIT_SUCCESS;
}