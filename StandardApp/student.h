// 사용자 정의 헤더 파일 - student.h

#pragma once

#define PI 3.141592
#define LIMIT 100.0
#define MSG "passed!"
#define Err_PRN printf("호용 범위를 벗어났습니다.\n") // #define에 세미콜론은 빼기

#define SUM(a, b) ((a)+(b))
#define MUL(a, b) (a * b) // 괄호 꼭 넣어서 우선 순위 잘 계산하기

#define PRINT_EXPR(x) printf(#x " = %d\n", x) // #x에 x라는 문자 대입
#define NAME_CAT(x, y) (x ## y) // x와 y 합침 like strcat 문자열 붙이기

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
	printf("임시 출력 함수\n");
	// ... 내용
}