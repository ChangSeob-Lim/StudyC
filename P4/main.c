/*
  filename - main.c
  version - 1.0
  description - 자기참조 구조체 (명칭 NODE) 를 통해서 연결 리스트를 만들고, 데이터는 실수를 담을 수 있도록 한다. 여기서 insertNode() 함수로 제일마지막에 새 NODE 를 추가, deleteNode(int index)로 원하는 위치의 값을 삭제하게 한다.
각 작업 후 노드의 갯수만큼 데이터를 출력하는 함수 printNode()를 구현한다.

  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    double data;
    struct NODE* link;
} NODE;

NODE* head; // 연결리스트
int count = 0; // 노드의 개수를 세기 위한 변수, 삭제 에러 방지

void insertNode();
void deleteNode(int index);
void printNode();

// 메인함수
int main(void)
{
    int menu, index;

    head = NULL;

    while (1)
    {
        printf("1.삽입\t2.삭제\t3.출력\t0.종료\n");
        scanf("%d", &menu);

        if (menu == 1) // 삽입
        {
            insertNode();
        }

        else if (menu == 2) // 삭제
        {
            printf("삭제를 원하는 위치를 입력하세요 : ");
            scanf("%d", &index);

            deleteNode(index);
        }

        else if (menu == 3) // 출력
        {
            printNode();
        }

        else if (menu == 0) // 종료
        {
            NODE* temp;

            if (count != NULL)
            {
                while (1)
                {
                    temp = head->link;

                    free(head);

                    if (temp == NULL)
                    {
                        break;
                    }

                    head = temp;
                }
            }

            break;
        }
    }

    system("pause");
    return EXIT_SUCCESS;
}

void insertNode()
{
    double data;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    NODE* temp;

    printf("실수를 입력하세요 : ");
    scanf("%lf", &data);

    node->data = data;
    node->link = NULL;

    if (head == NULL) // 연결리스트에 아무것도 없을때
    {
        head = node;
    }

    else // 나머지
    {
        temp = head;

        while (1)
        {
            if (temp->link == NULL)
            {
                break;
            }

            temp = temp->link;
        }

        temp->link = node;
    }

    count++;
}

void deleteNode(int index)
{
    NODE* temp, *d;
    int i = 0;

    temp = head;
    
    if (count <= index || index < 0 || count == 0) // index 가 존재하지 않을 때
    {
        printf("삭제할 수 없는 위치입니다.\n");
        return;
    }

    if (index == 0) // 첫번째 노드 삭제
    {
        d = head;
        head = head->link;
    }

    else if (index == count - 1) // 마지막 노드 삭제
    {
        while (1)
        {
            if (temp->link->link == NULL)
            {
                d = temp->link;
                break;
            }

            temp = temp->link;
        }

        temp->link = NULL;
    }

    else // 중간에 있는 노드 삭제
    {
        while (1)
        {
            if (i == index - 1)
            {
                d = temp->link;
                break;
            }

            temp = temp->link;
            i++;
        }

        temp->link = temp->link->link;
    }

    free(d);

    count--;
}

void printNode()
{
    NODE* temp = head;

    printf("출력 결과\n");

    while (1)
    {
        if (temp == NULL)
        {
            break;
        }

        printf("%.2lf\t", temp->data);

        temp = temp->link;
    }

    printf("\n");
}
