// ����� ���� ��� ���� - student.h

#pragma once

#define PI 3.141592
#define LIMIT 100.0
#define MSG "passed!"
#define Err_PRN printf("ȣ�� ������ ������ϴ�.\n") // #define�� �����ݷ��� ����

#define SUM(a, b) ((a)+(b))
#define MUL(a, b) (a * b) // ��ȣ �� �־ �켱 ���� �� ����ϱ�

#define PRINT_EXPR(x) printf(#x " = %d\n", x) // #x�� x��� ���� ����
#define NAME_CAT(x, y) (x ## y) // x�� y ��ħ like strcat ���ڿ� ���̱�

#define VER 7
#define BIT16

struct student
{
	int num;
	char name[20];
};

typedef struct student Student;

void my_print(void)
{
	printf("�ӽ� ��� �Լ�\n");
	// ... ����
}