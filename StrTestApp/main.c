/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ���ڿ� �н�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// �����Լ�
int main(void) 
{
    /*char fruit[80] = "apple";

    printf("apple�� �����ּ� %p\n", "apple");
    printf("apple�� �ι�° �����ּ� %p\n", "apple" + 1);
    printf("apple�� ù��° ���� %c\n", *"apple");
    printf("apple�� �ι�° ���� %c\n", *("apple" + 1));
    printf("apple�� ����° ���� %c\n", "apple"[3]);
    printf("fruit�� �����ּ� %p\n", fruit);*/

    /*char* dessert = "apple";

    printf("���� �Ľ��� %s�Դϴ�.\n", dessert);
    dessert = "banana";
    printf("���� �Ľ��� %s�Դϴ�.\n", dessert);*/

    /*char str[80];

    printf("���ڿ� �Է� : ");
    scanf("%s", str);
    printf("ù ��° �ܾ� : %s\n", str);
    scanf("%s", str);
    printf("���ۿ� �����ִ� �� ��° �ܾ� : %s\n", str);*/

    //char str[80];

    /*printf("���ڿ� �Է� : ");
    gets(str);
    printf("�Էµ� ���� : %s\n", str);*/

    /*printf("���ڿ� �Է� : ");
    fgets(str, sizeof(str), stdin);
    printf("�Էµ� ���� : %s\n", str);*/

    /*int age;
    char name[20];

    printf("�����Է� : ");
    scanf("%d", &age);
    getchar();
    printf("�̸��Է� : ");
    gets(name);
    printf("���� : %d, �̸� : %s\n", age, name);*/

    char str[80] = "apple juice";
    char* ps = "banana";

    puts(str);
    fputs(ps, stdout);
    puts(" milk");

	system("pause");
	return EXIT_SUCCESS;
}