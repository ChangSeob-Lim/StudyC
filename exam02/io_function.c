/*
  filename - io_function.c
  version - 1.0
  description - 명함관리 프로그램을 C언어로 작성하세요
환경: Windows 10 Professional, Visual Studio Community 2019
개요: C언어 사용, 윈도우 OS 에서 콘솔 명함관리 프로그램을 만듭니다. 명함정보(명함번호, 한글이름, 폰번호, 이메일)의 입력, 수정, 삭제할 수 있는 기능과 추가로 검색을 할 수 있는 기능도 만듭니다. 입출력에 대한 기능은 main 함수와 다른 소스에 만듭니다.

1번 문항 (30)
 - exam01로 프로젝트 생성. 콘솔에서 입출력 기능을 구현
 - 1번 입력, 2번 수정, 3번 삭제, 4번 전체출력, 5번 검색, 6번 종료로 메뉴 표현
 - 구조체 배열을 사용하여 데이터를 관리함. 배열의 크기는 상수로 정의(50)
 - 명함정보 입력 함수는 input_business_card()로 정의, 입력시는 한글이름, 폰번호, 이메일만 입력하고, 명함번호는 1에서부터 자동으로 증가

2번 문항 (30)
 - 전체 명함정보를 출력하는 함수는 show_all_cards()로 정의, 명함번호 / 한글이름 / 폰번호 / 이메일 순으로 한줄씩 출력
 - 검색 콘솔에서 명함번호 입력받아, 검색결과를 출력 후 키를 누르면 다시 메뉴를 출력, 함수는 search_business_card(int num)
 - 수정 기능은 edit_business_card()로 명함번호 입력으로 검색 후 폰번호, 이메일을 다시 입력받아 저장

여기까지 솔루션을 저장 깃허브에 프로젝트를 푸시하고 새로운 프로젝트를 exam02 생성 위의 소스를 복사

3번 문항 (10)
 - 이름이 동일하고, 전화번호가 같으면 정보 입력 하지 않음
 - 삭제 기능은 delete_business_card() 이며 명함번호를 입력 받아 삭제, 동명이인이 있을 수 있으므로 show_all_cards()로 전체 출력 후 삭제할 명함번호 입력으로 삭제

4번 문항 (20)
 - 종료시 card_data.txt에 프로그램 실행 후 입력한 저장 데이터를 저장하고 종료
 - 재실행 시 card_data.txt로 저장한 데이터를 로드

5번 문항(추가문항 : 10)
 - 구조체 배열을 자기참조 구조체로 변경하여 위의 동일한 기능을 수행

완료 후 깃허브에 올리고 종료
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

extern card business_card[50];
extern int index;
extern int count;

void input_business_card();
void show_all_cards();
void search_business_card(int num);
void edit_business_card();
void delete_business_card();

void input_business_card() //입력시는 한글이름, 폰번호, 이메일만 입력하고, 명함번호는 1에서부터 자동으로 증가 // 이름이 동일하고, 전화번호가 같으면 정보 입력 하지 않음
{
    char name[20];
    char phone[20];
    char e_mail[50];

    printf("명함 입력입니다.\n");
    printf("이름을 입력해주세요. : ");
    scanf("%s", &name);
    printf("폰번호를 입력해주세요. : ");
    scanf("%s", &phone);

    int check = 1;

    for (int i = 0; i < index; i++)
    {
        if (!strcmp(business_card[i].name, name))
        {
            if (!strcmp(business_card[i].phone, phone))
            {
                printf("중복된 명함입니다.\n");

                check = 0;
                break;
            }
        }
    }

    if (check)
    {
        printf("이메일을 입력해주세요. : ");
        scanf("%s", &e_mail);

        strcpy(business_card[index].name, name);
        strcpy(business_card[index].phone, phone);
        strcpy(business_card[index].e_mail, e_mail);
        business_card[index].card_num = count;
        count++;
        index++;
    }
}

void show_all_cards() //명함번호 / 한글이름 / 폰번호 / 이메일 순으로 한줄씩 출력
{
    if (index == 0)
    {
        printf("명함이 없습니다.\n");
    }

    else
    {
        printf("전체 명함정보입니다.\n");
        printf("명함번호 / 한글이름 / 폰번호 / 이메일\n");
        for (int i = 0; i < index; i++)
        {
            printf("%d / %s / %s / %s\n", business_card[i].card_num, business_card[i].name, business_card[i].phone, business_card[i].e_mail);
        }
    }
}

void search_business_card(int num) //검색 콘솔에서 명함번호 입력받아, 검색결과를 출력 후 키를 누르면 다시 메뉴를 출력
{
    int j = -1;
    
    for (int i = 0; i < index; i++)
    {
        if (num == business_card[i].card_num)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        printf("없는 명함번호입니다.\n");
    }

    else
    {
        printf("검색결과 : %d / %s / %s / %s\n", business_card[j].card_num, business_card[j].name, business_card[j].phone, business_card[j].e_mail);
    }
}

void edit_business_card() //명함번호 입력으로 검색 후 폰번호, 이메일을 다시 입력받아 저장
{
    int num;

    printf("명함번호를 입력해주세요. : ");
    scanf("%d", &num);

    if (num < count && num > 0)
    {
        search_business_card(num);

        printf("폰번호를 수정하세요. : ");
        scanf("%s", &business_card[num - 1].phone);
        printf("이메일을 수정하세요. : ");
        scanf("%s", &business_card[num - 1].e_mail);
    }

    else
    {
        printf("없는 명함번호입니다.\n");
    }
}

void delete_business_card() // 명함번호를 입력 받아 삭제, 동명이인이 있을 수 있으므로 show_all_cards()로 전체 출력 후 삭제할 명함번호 입력으로 삭제
{
    show_all_cards();

    int num;

    printf("명함번호를 입력해주세요. : ");
    scanf("%d", &num);

    if (num < count && num > 0)
    {
        int j;

        for (int i = 0; i < index; i++)
        {
            if (num == business_card[i].card_num)
            {
                j = i;
                break;
            }
        }

        for (int i = j; i < index - 1; i++)
        {
            business_card[i].card_num = business_card[i + 1].card_num;
            strcpy(business_card[i].name, business_card[i + 1].name);
            strcpy(business_card[i].phone, business_card[i + 1].phone);
            strcpy(business_card[i].e_mail, business_card[i + 1].e_mail);
        }

        index--;
    }

    else
    {
        printf("없는 명함번호입니다.\n");
    }
}