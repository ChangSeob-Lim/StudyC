#pragma once

typedef struct card //��������(���Թ�ȣ, �ѱ��̸�, ����ȣ, �̸���)
{
    int card_num;
    char name[20];
    char phone[20];
    char e_mail[50];
    struct card* next;
} card;