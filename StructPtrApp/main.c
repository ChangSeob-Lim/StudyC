/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ����ü Ȱ�� �н�
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct score
{
    int kor;
    int eng;
    int math;
};

struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

void print_list(struct address *list);

// �����Լ�
int main(void) 
{
    /*struct score p1 = { 99,30,15 };
    struct score* ps = &p1;

    printf("���� : %d\n", (*ps).kor);
    printf("���� : %d\n", ps->eng);
    printf("���� : %d\n", ps->math);*/

    struct address list[5] = {
        {"ȫ�浿", 23, "111-1111", "�︪�� ����"},
        {"�̼���", 35, "222-2222", "���� ��õ��"},
        {"�庸��", 19, "333-3333", "�ϵ� û����"},
        {"������", 19, "444-4444", "�泲 õ��"},
        {"���߱�", 19, "555-5555", "Ȳ�ص� ����"}
    };

    /*int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }*/

    print_list(list);
    
	system("pause");
	return EXIT_SUCCESS;
}

void print_list(struct address *list)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n", (list + i)->name, (list + i)->age, (list + i)->tel, (list + i)->addr);
        //printf("%10s%5d%15s%20s\n", (*(list + i)).name, (*(list + i)).age, (*(list + i)).tel, (*(list + i)).addr);
    }
}
