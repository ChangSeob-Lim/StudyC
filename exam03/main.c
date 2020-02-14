/*
  filename - main.c
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

card* head;
int index = 0;
int count = 1;

// �����Լ�
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

    printf("���԰��� ���α׷�\n");
    while (1)
    {
        printf("1�� �Է�, 2�� ����, 3�� ����, 4�� ��ü���, 5�� �˻�, 6�� ����\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1: // �Է�
            head = input_business_card(head);
            break;

        case 2: // ����
            head = edit_business_card(head);
            break;

        case 3: // ����
            head = delete_business_card(head);
            break;

        case 4: // ��ü���
            head = show_all_cards(head);
            break;

        case 5: // �˻�
            printf("�˻�����Դϴ�. ���Թ�ȣ�� �Է����ּ���. : ");
            scanf("%d", &num);
            getchar();

            head = search_business_card(num, head);
            system("pause");

            break;

        case 6: // ����
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
            printf("�ùٸ��� ���� �޴��Դϴ�.\n");
            break;
        }
    }

    fclose(fp);

    system("pause");
    return EXIT_SUCCESS;
}