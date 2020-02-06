/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 포인터 스왑
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_ptr(char** ppa, char** ppb);
void print_str(char** src, int count);
void print_ary(int(*)[4]);

// 메인함수
int main(void) 
{
    /*char* pa = "success";
    char* pb = "failure";
    
    printf("pa = %s, pb = %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa = %s, pb = %s\n", pa, pb);*/

    /*char *ptr_arr[4] = { "eagle", "tiger", "lion", "squirrel" };
    int count = sizeof(ptr_arr) / sizeof(ptr_arr[0]);

    print_str(ptr_arr, count);*/

    /*int ary[5] = { 1,2,3,4,5 };

    printf("arr %d\n", *ary);
    printf("&arr %p\n", *&ary);
    printf("arr[1]의 값, %p\n", ary+1);
    printf("arr[1]의 값, 주소값 %p\n", &ary + 1);
    printf("%d\n", *(ary + 1));
    printf("%p\n", ary + 1);*/

    /*int ary[3][4] = { { 1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    int(*pa)[4];
    pa = ary;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }*/

    int ary[3][4] = { { 1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    print_ary(ary);

    system("pause");
    return EXIT_SUCCESS;
}

void swap_ptr(char** ppa, char** ppb) 
{
    char *temp;

    temp = *ppa;
    *ppa = *ppb;
    *ppb = temp;
}

void print_str(char** src, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", src[i]);
    }
}

void print_ary(int(*pa)[4])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}