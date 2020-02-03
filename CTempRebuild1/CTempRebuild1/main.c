#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <conio.h>

struct _finddata_t fd;

struct usedName {
	char name[_MAX_PATH];
};

int i;
struct usedName used[100];
int count = 0;

int isFileOrDir()
{
	if (fd.attrib & _A_SUBDIR)
		return 0; // ���丮�� 0 ��ȯ
	else
		return 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

}

void FileSearch(char file_path[])
{//printf("file_path=%s\n", file_path);
	intptr_t handle;
	int check = 0;
	char file_path2[_MAX_PATH];

	strcat(file_path, "\\");
	strcpy(file_path2, file_path);
	strcat(file_path, "*");


	if ((handle = _findfirst(file_path, &fd)) == -1)
	{
		//printf("No such file or directory\n");
		return;
	}

	while (_findnext(handle, &fd) == 0)
	{
		char file_pt[_MAX_PATH];
		strcpy(file_pt, file_path2);
		strcat(file_pt, fd.name);

		check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

		if (check == 0 && fd.name[0] != '.')
		{
			FileSearch(file_pt);    //���� ���丮 �˻� ����Լ�
		}
		else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
		{
			if (strstr(fd.name, ".txt"))
			{
				printf("���ϸ� : %s\n", fd.name);
				//printf("���ϸ� : %s, ũ��:%d\n", file_pt, fd.size);

				FILE* fp;
				int ch;

				fp = fopen(file_pt, "r");
				if (fp == NULL)
				{
					printf("������ ������ �ʽ��ϴ�.\n");
					return;
				}

				while (1)
				{
					ch = fgetc(fp);
					if (ch == EOF)
					{
						break;
					}

					putchar(ch);
				}

				printf("\n");

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
		char file_path[_MAX_PATH] = "C:\\Users\\PKNU\\Documents";    //C:\ ��� Ž��
		FileSearch(file_path);
	}

	return 0;
}