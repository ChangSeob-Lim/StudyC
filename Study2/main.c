/*
  filename - main.c
  version - 1.0
  description - SystemInfo ����ϱ�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>
#include <locale.h>
#include <sysinfoapi.h>

#define  ENV_VAR_STRING_COUNT  (sizeof(envVarStrings)/sizeof(TCHAR*))
#define INFO_BUFFER_SIZE 32767
#define DIV 1024
#define WIDTH 7

// �����Լ�
int main(void) 
{
    //system("systeminfo");

    _wsetlocale(LC_ALL, _T("korean"));

    DWORD i;
    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the name of the computer. ȣ��Ʈ �̸�
    bufCharCount = INFO_BUFFER_SIZE;
    GetComputerName(infoBuf, &bufCharCount);
    _tprintf(TEXT("\nȣ��Ʈ �̸�: \t\t%s"), infoBuf);

    // Get and display the user name. ��ϵ� ������
    bufCharCount = INFO_BUFFER_SIZE;
    GetUserName(infoBuf, &bufCharCount);
    _tprintf(TEXT("\n��ϵ� ������: \t\t%s"), infoBuf);

    // Get and display the system directory. �ý��� ���͸�
    GetSystemDirectory(infoBuf, INFO_BUFFER_SIZE);
    _tprintf(TEXT("\n�ý��� ���͸�: \t%s"), infoBuf);

    // Get and display the Windows directory. Windows ���͸�
    GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
    _tprintf(TEXT("\nWindows ���͸�: \t%s"), infoBuf);

    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;

    dwVersion = GetVersion();

    // Get the Windows version.

    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    // Get the build number.

    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    printf("\n������ ���� : Version is %d.%d (%d)",
        dwMajorVersion,
        dwMinorVersion,
        dwBuild);

    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    // �� ���� �޸�
    _tprintf(TEXT("\n�� ���� �޸�: \t\t%*I64d MB"),
        WIDTH, statex.ullTotalPhys / DIV / DIV);

    // ��� ������ ���� �޸�
    _tprintf(TEXT("\n��� ������ ���� �޸�: \t%*I64d MB"),
        WIDTH, statex.ullAvailPhys / DIV / DIV);

    // ���� �޸�: �ִ� ũ��
    _tprintf(TEXT("\n���� �޸�: �ִ� ũ��: \t%*I64d MB"),
        WIDTH, statex.ullTotalPageFile / DIV / DIV);

    // ���� �޸�: ��� ����
    _tprintf(TEXT("\n���� �޸�: ��� ����: \t%*I64d MB"),
        WIDTH, statex.ullAvailPageFile / DIV / DIV);

    // ���� �޸�: ��� ��
    _tprintf(TEXT("\n���� �޸�: ��� ��: \t\t%*I64d MB"),
        WIDTH, (statex.ullTotalPageFile / DIV / DIV) - (statex.ullAvailPageFile / DIV / DIV));
    
    printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}