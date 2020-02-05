/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 문자열 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// 메인함수
int main(void) 
{
    /*char fruit[80] = "apple";

    printf("apple의 시작주소 %p\n", "apple");
    printf("apple의 두번째 시작주소 %p\n", "apple" + 1);
    printf("apple의 첫번째 문자 %c\n", *"apple");
    printf("apple의 두번째 문자 %c\n", *("apple" + 1));
    printf("apple의 세번째 문자 %c\n", "apple"[3]);
    printf("fruit의 시작주소 %p\n", fruit);*/

    /*char* dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert);*/

    /*char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("첫 번째 단어 : %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아있는 두 번째 단어 : %s\n", str);*/

    //char str[80];

    /*printf("문자열 입력 : ");
    gets(str);
    printf("입력된 문자 : %s\n", str);*/

    /*printf("문자열 입력 : ");
    fgets(str, sizeof(str), stdin);
    printf("입력된 문자 : %s\n", str);*/

    /*int age;
    char name[20];

    printf("나이입력 : ");
    scanf("%d", &age);
    getchar();
    printf("이름입력 : ");
    gets(name);
    printf("나이 : %d, 이름 : %s\n", age, name);*/

    char str[80] = "apple juice";
    char* ps = "banana";

    puts(str);
    fputs(ps, stdout);
    puts(" milk");

	system("pause");
	return EXIT_SUCCESS;
}