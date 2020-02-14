/*
  filename - io_function.c
  version - 1.0
  description - ���԰��� ���α׷��� C���� �ۼ��ϼ���
ȯ��: Windows 10 Professional, Visual Studio Community 2019
����: C��� ���, ������ OS ���� �ܼ� ���԰��� ���α׷��� ����ϴ�. ��������(���Թ�ȣ, �ѱ��̸�, ����ȣ, �̸���)�� �Է�, ����, ������ �� �ִ� ��ɰ� �߰��� �˻��� �� �� �ִ� ��ɵ� ����ϴ�. ����¿� ���� ����� main �Լ��� �ٸ� �ҽ��� ����ϴ�.

1�� ���� (30)
 - exam01�� ������Ʈ ����. �ֿܼ��� ����� ����� ����
 - 1�� �Է�, 2�� ����, 3�� ����, 4�� ��ü���, 5�� �˻�, 6�� ����� �޴� ǥ��
 - ����ü �迭�� ����Ͽ� �����͸� ������. �迭�� ũ��� ����� ����(50)
 - �������� �Է� �Լ��� input_business_card()�� ����, �Է½ô� �ѱ��̸�, ����ȣ, �̸��ϸ� �Է��ϰ�, ���Թ�ȣ�� 1�������� �ڵ����� ����

2�� ���� (30)
 - ��ü ���������� ����ϴ� �Լ��� show_all_cards()�� ����, ���Թ�ȣ / �ѱ��̸� / ����ȣ / �̸��� ������ ���پ� ���
 - �˻� �ֿܼ��� ���Թ�ȣ �Է¹޾�, �˻������ ��� �� Ű�� ������ �ٽ� �޴��� ���, �Լ��� search_business_card(int num)
 - ���� ����� edit_business_card()�� ���Թ�ȣ �Է����� �˻� �� ����ȣ, �̸����� �ٽ� �Է¹޾� ����

������� �ַ���� ���� ����꿡 ������Ʈ�� Ǫ���ϰ� ���ο� ������Ʈ�� exam02 ���� ���� �ҽ��� ����

3�� ���� (10)
 - �̸��� �����ϰ�, ��ȭ��ȣ�� ������ ���� �Է� ���� ����
 - ���� ����� delete_business_card() �̸� ���Թ�ȣ�� �Է� �޾� ����, ���������� ���� �� �����Ƿ� show_all_cards()�� ��ü ��� �� ������ ���Թ�ȣ �Է����� ����

4�� ���� (20)
 - ����� card_data.txt�� ���α׷� ���� �� �Է��� ���� �����͸� �����ϰ� ����
 - ����� �� card_data.txt�� ������ �����͸� �ε�

5�� ����(�߰����� : 10)
 - ����ü �迭�� �ڱ����� ����ü�� �����Ͽ� ���� ������ ����� ����

�Ϸ� �� ����꿡 �ø��� ����
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

card* temp;
extern int index;
extern int count;

card* input_business_card(card *head);
card* show_all_cards(card* head);
card* search_business_card(int num, card* head);
card* edit_business_card(card* head);
card* delete_business_card(card* head);

card* input_business_card(card* head) //�Է½ô� �ѱ��̸�, ����ȣ, �̸��ϸ� �Է��ϰ�, ���Թ�ȣ�� 1�������� �ڵ����� ���� // �̸��� �����ϰ�, ��ȭ��ȣ�� ������ ���� �Է� ���� ����
{
    char name[20];
    char phone[20];
    char e_mail[50];

    card* node = (card*)malloc(sizeof(card));

    printf("���� �Է��Դϴ�.\n");
    printf("�̸��� �Է����ּ���. : ");
    scanf("%s", &name);
    printf("����ȣ�� �Է����ּ���. : ");
    scanf("%s", &phone);

    int check = 1;

    temp = head;

    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            if (strcmp(temp->name, name))
            {
                if (strcmp(temp->phone, phone))
                {
                    check = 0;
                    break;
                }
            }

            temp = temp->next;
        }
    }

    if (check)
    {
        printf("�̸����� �Է����ּ���. : ");
        scanf("%s", &e_mail);

        node->card_num = count;
        strcpy(node->name, name);
        strcpy(node->phone, phone);
        strcpy(node->e_mail, e_mail);
        node->next = NULL;

        temp = head;

        if (temp == NULL)
        {
            temp = node;
        }

        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = node;
        }
        
        count++;
        index++;

        return temp;
    }
}

card* show_all_cards(card* head) //���Թ�ȣ / �ѱ��̸� / ����ȣ / �̸��� ������ ���پ� ���
{
    temp = head;

    if (temp == NULL)
    {
        printf("������ �����ϴ�.\n");
    }

    else
    {
        printf("��ü ���������Դϴ�.\n");
        printf("���Թ�ȣ / �ѱ��̸� / ����ȣ / �̸���\n");

        while (temp != NULL)
        {
            printf("%d / %s / %s / %s\n", temp->card_num, temp->name, temp->phone, temp->e_mail);

            temp = temp->next;
        }
    }

    return temp;
}

card* search_business_card(int num, card* head) //�˻� �ֿܼ��� ���Թ�ȣ �Է¹޾�, �˻������ ��� �� Ű�� ������ �ٽ� �޴��� ���
{
    int j = 0;
    temp = head;

    while (temp != NULL)
    {
        if (num == temp->card_num)
        {
            j = 1;
            break;
        }

        temp = temp->next;
    }

    if (j)
    {
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }

    else
    {
        printf("%d / %s / %s / %s\n", temp->card_num, temp->name, temp->phone, temp->e_mail);
    }

    return temp;
}

card* edit_business_card(card* head) //���Թ�ȣ �Է����� �˻� �� ����ȣ, �̸����� �ٽ� �Է¹޾� ����
{
    int num;
    temp = head;

    printf("���Թ�ȣ�� �Է����ּ���. : ");
    scanf("%d", &num);

    if (num < count && num > 0)
    {
        int check = 0;

        while (temp != NULL)
        {
            if (num == temp->card_num)
            {
                break;
            }

            temp = temp->next;
        }

        if (check)
        {
            search_business_card(num, head);

            printf("����ȣ�� �����ϼ���. : ");
            scanf("%s", &temp->phone);
            printf("�̸����� �����ϼ���. : ");
            scanf("%s", &temp->e_mail);
        }

        else
        {
            printf("�ش� ������ �����ϴ�.\n");
        }
    }

    else
    {
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }

    return temp;
}

card* delete_business_card(card* head) // ���Թ�ȣ�� �Է� �޾� ����, ���������� ���� �� �����Ƿ� show_all_cards()�� ��ü ��� �� ������ ���Թ�ȣ �Է����� ����
{
    show_all_cards(head);

    int num;
    temp = head;

    printf("���Թ�ȣ�� �Է����ּ���. : ");
    scanf("%d", &num);

    if (num < count && num > 0)
    {
        while (temp->next->next != NULL)
        {
            if (num == temp->next->card_num)
            {
                break;
            }

            temp = temp->next;
        }

        temp->next = temp->next->next;

        index--;
    }

    else
    {
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }

    return temp;
}