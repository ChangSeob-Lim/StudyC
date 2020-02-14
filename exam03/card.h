#pragma once

typedef struct card //명함정보(명함번호, 한글이름, 폰번호, 이메일)
{
    int card_num;
    char name[20];
    char phone[20];
    char e_mail[50];
    struct card* next;
} card;