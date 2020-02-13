/*
  filename - main.c
  version - 1.0
  description - �ڱ����� ����ü (��Ī NODE) �� ���ؼ� ���� ����Ʈ�� �����, �����ʹ� �Ǽ��� ���� �� �ֵ��� �Ѵ�. ���⼭ insertNode() �Լ��� ���ϸ������� �� NODE �� �߰�, deleteNode(int index)�� ���ϴ� ��ġ�� ���� �����ϰ� �Ѵ�.
�� �۾� �� ����� ������ŭ �����͸� ����ϴ� �Լ� printNode()�� �����Ѵ�.

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

NODE* head; // ���Ḯ��Ʈ
int count = 0; // ����� ������ ���� ���� ����, ���� ���� ����

void insertNode();
void deleteNode(int index);
void printNode();

// �����Լ�
int main(void)
{
    int menu, index;

    head = NULL;

    while (1)
    {
        printf("1.����\t2.����\t3.���\t0.����\n");
        scanf("%d", &menu);

        if (menu == 1) // ����
        {
            insertNode();
        }

        else if (menu == 2) // ����
        {
            printf("������ ���ϴ� ��ġ�� �Է��ϼ��� : ");
            scanf("%d", &index);

            deleteNode(index);
        }

        else if (menu == 3) // ���
        {
            printNode();
        }

        else if (menu == 0) // ����
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

    printf("�Ǽ��� �Է��ϼ��� : ");
    scanf("%lf", &data);

    node->data = data;
    node->link = NULL;

    if (head == NULL) // ���Ḯ��Ʈ�� �ƹ��͵� ������
    {
        head = node;
    }

    else // ������
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
    
    if (count <= index || index < 0 || count == 0) // index �� �������� ���� ��
    {
        printf("������ �� ���� ��ġ�Դϴ�.\n");
        return;
    }

    if (index == 0) // ù��° ��� ����
    {
        d = head;
        head = head->link;
    }

    else if (index == count - 1) // ������ ��� ����
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

    else // �߰��� �ִ� ��� ����
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

    printf("��� ���\n");

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
