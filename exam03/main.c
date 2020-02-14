/*
  filename - main.c
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

card* head;
int index = 0;
int count = 1;

// 메인함수
int main(void)
{
    int menu;
    int num;
    int card_num = 0;
    char name[20];
    char phone[20];
    char e_mail[50];

    head = NULL;
    card* temp;
    card* node = (card*)malloc(sizeof(card));

    FILE* fp = fopen("card_data.txt", "r");

    if (fp != NULL)
    {
        temp = head;
        
        while (fscanf(fp, "%d %s%s%s", &card_num, &name, &phone, &e_mail) != EOF)
        {
            node->card_num = card_num;
            strcpy(node->name, name);
            strcpy(node->phone, phone);
            strcpy(node->e_mail, e_mail);
            node->next = NULL;

            temp = node;
            temp = temp->next;

            index++;
            count = card_num + 1;
        }
    }

    fp = fopen("card_data.txt", "w");

    printf("명함관리 프로그램\n");
    while (1)
    {
        printf("1번 입력, 2번 수정, 3번 삭제, 4번 전체출력, 5번 검색, 6번 종료\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1: // 입력
            head = input_business_card(head);
            break;

        case 2: // 수정
            head = edit_business_card(head);
            break;

        case 3: // 삭제
            head = delete_business_card(head);
            break;

        case 4: // 전체출력
            head = show_all_cards(head);
            break;

        case 5: // 검색
            printf("검색기능입니다. 명함번호를 입력해주세요. : ");
            scanf("%d", &num);
            getchar();

            head = search_business_card(num, head);
            system("pause");

            break;

        case 6: // 종료
            temp = head;

            while (temp->next != NULL)
            {
                fprintf(fp, "%d %s %s %s", temp->card_num, temp->name, temp->phone, temp->e_mail);

                temp = temp->next;

                if (temp->next != NULL)
                {
                    fprintf(fp, "\n");
                }
            }

            return 0;

        default:
            printf("올바르지 않은 메뉴입니다.\n");
            break;
        }
    }

    fclose(fp);

    system("pause");
    return EXIT_SUCCESS;
}