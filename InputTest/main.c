#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int age;
	double height;
	char grade;
	char name[20];

	printf("���̿� Ű�� �Է��ϼ��� : ");
	scanf("%d%lf", &age, &height);
	printf("���̴� %d�� Ű�� %.1lfcm�Դϴ�.\n", age, height);

	printf("������ �Է��ϼ��� : ");
	scanf(" %c", &grade);
	printf("�̸��� �Է��ϼ��� : ");
	scanf("%s", &name);

	printf("%s �� ���� : %c\n", name, grade);

	system("pause");

	return 0;
}