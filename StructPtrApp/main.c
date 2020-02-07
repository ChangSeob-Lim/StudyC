/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 구조체 활용 학습
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

// 메인함수
int main(void) 
{
    /*struct score p1 = { 99,30,15 };
    struct score* ps = &p1;

    printf("국어 : %d\n", (*ps).kor);
    printf("영어 : %d\n", ps->eng);
    printf("수학 : %d\n", ps->math);*/

    struct address list[5] = {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순신", 35, "222-2222", "서울 건천동"},
        {"장보고", 19, "333-3333", "완도 청해진"},
        {"유관순", 19, "444-4444", "충남 천안"},
        {"안중근", 19, "555-5555", "황해도 해주"}
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
