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

card business_card[50];
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

    FILE* fp = fopen("card_data.txt", "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%d %s%s%s", &card_num, &name, &phone, &e_mail) != EOF)
        {
            business_card[index].card_num = card_num;
            strcpy(business_card[index].name, name);
            strcpy(business_card[index].phone, phone);
            strcpy(business_card[index].e_mail, e_mail);

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
            input_business_card();
            break;

        case 2: // ����
            edit_business_card();
            break;

        case 3: // ����
            delete_business_card();
            break;

        case 4: // ��ü���
            show_all_cards();
            break;

        case 5: // �˻�
            printf("�˻�����Դϴ�. ���Թ�ȣ�� �Է����ּ���. : ");
            scanf("%d", &num);
            getchar();
            
            search_business_card(num);
            system("pause");

            break;

        case 6: // ����
            for (int i = 0; i < index; i++)
            {
                fprintf(fp, "%d %s %s %s", business_card[i].card_num, business_card[i].name, business_card[i].phone, business_card[i].e_mail);

                if (i != index - 1)
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


