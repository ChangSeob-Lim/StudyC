#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

struct _finddata_t fd;

// 중복 파일 확인을 위한 구조체 
struct usedName {
	char name[260];
};

int i; // 반복 변수 
struct usedName used[10000]; // 중복 파일 확인을 위한 변수 
int count = 0; // 파일 개수 확인용 변수 

int isFileOrDir()
{
	if (fd.attrib & _A_SUBDIR)
		return 0; // 디렉토리면 0 반환
	else
		return 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

}

void FileSearch(char file_path[])
{//printf("file_path=%s\n", file_path);
	intptr_t handle;
	int check = 0;
	char file_path2[260]; // 복사할 주소

	strcat(file_path, "\\"); // 배열 붙이기
	strcpy(file_path2, file_path); // 배열 복사
	strcat(file_path, "*");


	if ((handle = _findfirst(file_path, &fd)) == -1) // _findfirst <- file_path의 주소와 비교해서 첫번째 인스턴스에 대한 정보 제공
	{
		//printf("No such file or directory\n");
		return;
	}

	while (_findnext(handle, &fd) == 0)
	{
		char file_pt[260];
		strcpy(file_pt, file_path2);
		strcat(file_pt, fd.name);

		check = isFileOrDir();    //파일인지 디렉토리 인지 식별

		if (check == 0 && fd.name[0] != '.')
		{
			FileSearch(file_pt);    //하위 디렉토리 검색 재귀함수
		}
		else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
		{//printf("파일명 : %s, 크기:%d\n", file_pt, fd.size);
			int nameCheck = 0; // 같은 이름이 있는가 확인하기 위한 변수

			for (i = 0; i < count; i++) // 체크
			{
				if (strcmp(used[i].name, fd.name) == 0) // 같으면 0 
				{
					nameCheck = 1;
					break;
				}
			}

			if (nameCheck == 1) // 같은게 있다면 패스
			{
				continue;
			}

			if (strstr(fd.name, ".txt")) // txt 파일이 있는가 확인
			{
				strcpy(used[count].name, fd.name); // 배열에 복사해 넣기
				count++; // 증가시켜

				printf("파일명 : %s\n", fd.name);
				//printf("파일명 : %s, 크기:%d\n", file_pt, fd.size);

				// 파일 출력
				FILE* fp; 
				int ch;

				fp = fopen(file_pt, "r");
				if (fp == NULL)
				{
					printf("파일이 열리지 않습니다.\n");
					return;
				}

				printf("-------파일 내용-------\n");
				while (1)
				{
					ch = fgetc(fp);
					if (ch == EOF)
					{
						break;
					}

					putchar(ch);
				}

				printf("\n-----------------------\n");

				fclose(fp);
			}
		}
	}

	_findclose(handle);
}

int main()
{
	while (1)
	{
		char file_path[260] = "C:\\Users\\PKNU\\Documents";    //C:\ 경로 탐색
		FileSearch(file_path);
	}

	return 0;
}

// 전체적으로 코드 다시 보고 공부하기
// 보고 배껴서 만든거 
// 코드보고 다시 공부하기