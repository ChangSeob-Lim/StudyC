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

extern card business_card[50];
extern int index;
extern int count;

void input_business_card();
void show_all_cards();
void search_business_card(int num);
void edit_business_card();
void delete_business_card();

void input_business_card() //�Է½ô� �ѱ��̸�, ����ȣ, �̸��ϸ� �Է��ϰ�, ���Թ�ȣ�� 1�������� �ڵ����� ���� // �̸��� �����ϰ�, ��ȭ��ȣ�� ������ ���� �Է� ���� ����
{
    char name[20];
    char phone[20];
    char e_mail[50];

    printf("���� �Է��Դϴ�.\n");
    printf("�̸��� �Է����ּ���. : ");
    scanf("%s", &name);
    printf("����ȣ�� �Է����ּ���. : ");
    scanf("%s", &phone);

    int check = 1;

    for (int i = 0; i < index; i++)
    {
        if (!strcmp(business_card[i].name, name))
        {
            if (!strcmp(business_card[i].phone, phone))
            {
                printf("�ߺ��� �����Դϴ�.\n");

                check = 0;
                break;
            }
        }
    }

    if (check)
    {
        printf("�̸����� �Է����ּ���. : ");
        scanf("%s", &e_mail);

        strcpy(business_card[index].name, name);
        strcpy(business_card[index].phone, phone);
        strcpy(business_card[index].e_mail, e_mail);
        business_card[index].card_num = count;
        count++;
        index++;
    }
}

void show_all_cards() //���Թ�ȣ / �ѱ��̸� / ����ȣ / �̸��� ������ ���پ� ���
{
    if (index == 0)
    {
        printf("������ �����ϴ�.\n");
    }

    else
    {
        printf("��ü ���������Դϴ�.\n");
        printf("���Թ�ȣ / �ѱ��̸� / ����ȣ / �̸���\n");
        for (int i = 0; i < index; i++)
        {
            printf("%d / %s / %s / %s\n", business_card[i].card_num, business_card[i].name, business_card[i].phone, business_card[i].e_mail);
        }
    }
}

void search_business_card(int num) //�˻� �ֿܼ��� ���Թ�ȣ �Է¹޾�, �˻������ ��� �� Ű�� ������ �ٽ� �޴��� ���
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
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }

    else
    {
        printf("�˻���� : %d / %s / %s / %s\n", business_card[j].card_num, business_card[j].name, business_card[j].phone, business_card[j].e_mail);
    }
}

void edit_business_card() //���Թ�ȣ �Է����� �˻� �� ����ȣ, �̸����� �ٽ� �Է¹޾� ����
{
    int num;

    printf("���Թ�ȣ�� �Է����ּ���. : ");
    scanf("%d", &num);

    if (num < count && num > 0)
    {
        search_business_card(num);

        printf("����ȣ�� �����ϼ���. : ");
        scanf("%s", &business_card[num - 1].phone);
        printf("�̸����� �����ϼ���. : ");
        scanf("%s", &business_card[num - 1].e_mail);
    }

    else
    {
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }
}

void delete_business_card() // ���Թ�ȣ�� �Է� �޾� ����, ���������� ���� �� �����Ƿ� show_all_cards()�� ��ü ��� �� ������ ���Թ�ȣ �Է����� ����
{
    show_all_cards();

    int num;

    printf("���Թ�ȣ�� �Է����ּ���. : ");
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
        printf("���� ���Թ�ȣ�Դϴ�.\n");
    }
}