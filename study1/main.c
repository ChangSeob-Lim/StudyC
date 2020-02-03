#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

struct _finddata_t fd;

// �ߺ� ���� Ȯ���� ���� ����ü 
struct usedName {
	char name[260];
};

int i; // �ݺ� ���� 
struct usedName used[10000]; // �ߺ� ���� Ȯ���� ���� ���� 
int count = 0; // ���� ���� Ȯ�ο� ���� 

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
	char file_path2[260]; // ������ �ּ�

	strcat(file_path, "\\"); // �迭 ���̱�
	strcpy(file_path2, file_path); // �迭 ����
	strcat(file_path, "*");


	if ((handle = _findfirst(file_path, &fd)) == -1) // _findfirst <- file_path�� �ּҿ� ���ؼ� ù��° �ν��Ͻ��� ���� ���� ����
	{
		//printf("No such file or directory\n");
		return;
	}

	while (_findnext(handle, &fd) == 0)
	{
		char file_pt[260];
		strcpy(file_pt, file_path2);
		strcat(file_pt, fd.name);

		check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

		if (check == 0 && fd.name[0] != '.')
		{
			FileSearch(file_pt);    //���� ���丮 �˻� ����Լ�
		}
		else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
		{//printf("���ϸ� : %s, ũ��:%d\n", file_pt, fd.size);
			int nameCheck = 0; // ���� �̸��� �ִ°� Ȯ���ϱ� ���� ����

			for (i = 0; i < count; i++) // üũ
			{
				if (strcmp(used[i].name, fd.name) == 0) // ������ 0 
				{
					nameCheck = 1;
					break;
				}
			}

			if (nameCheck == 1) // ������ �ִٸ� �н�
			{
				continue;
			}

			if (strstr(fd.name, ".txt")) // txt ������ �ִ°� Ȯ��
			{
				strcpy(used[count].name, fd.name); // �迭�� ������ �ֱ�
				count++; // ��������

				printf("���ϸ� : %s\n", fd.name);
				//printf("���ϸ� : %s, ũ��:%d\n", file_pt, fd.size);

				// ���� ���
				FILE* fp; 
				int ch;

				fp = fopen(file_pt, "r");
				if (fp == NULL)
				{
					printf("������ ������ �ʽ��ϴ�.\n");
					return;
				}

				printf("-------���� ����-------\n");
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
		char file_path[260] = "C:\\Users\\PKNU\\Documents";    //C:\ ��� Ž��
		FileSearch(file_path);
	}

	return 0;
}

// ��ü������ �ڵ� �ٽ� ���� �����ϱ�
// ���� �貸�� ����� 
// �ڵ庸�� �ٽ� �����ϱ�