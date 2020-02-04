/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

int get_num(void);
void print_char(char ch, int count);
void print_line(void);

// 메인함수
int main(void) 
{
    int result;

    result = get_num;
    printf("반환값 : %d\n", result);

    print_char('@', 5);

    print_line();
    printf("학번\t이름\t전공\t학점\n");
    print_line();

	system("pause");
	return EXIT_SUCCESS;
}

int get_num(void)
{
    int num;

    printf("양수 입력 : ");
    scanf("%d", &num);

    return num;
}

void print_char(char ch, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%c", ch);
    }

    printf("\n");
}

void print_line(void)
{
    int i; 

    for (i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}