/*
  filename - main.c
  version - 1.0
  description - 1���� 300������ ����(����) �߿��� 3�� �����(3,6,9,12,..)���� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. (for�� ���)
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    int sum = 0;

    for (int i = 1; i < 301; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        }
    }

    printf("1���� 300 ������ 3�� ��������� ���� = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
