/*
  filename - main.c
  version - 1.0
  description - SystemInfo 출력하기
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

// 메인함수
int main(void) 
{
    //system("systeminfo");

    _wsetlocale(LC_ALL, _T("korean"));

    DWORD i;
    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the name of the computer. 호스트 이름
    bufCharCount = INFO_BUFFER_SIZE;
    GetComputerName(infoBuf, &bufCharCount);
    _tprintf(TEXT("\n호스트 이름: \t\t%s"), infoBuf);

    // Get and display the user name. 등록된 소유자
    bufCharCount = INFO_BUFFER_SIZE;
    GetUserName(infoBuf, &bufCharCount);
    _tprintf(TEXT("\n등록된 소유자: \t\t%s"), infoBuf);

    // Get and display the system directory. 시스템 디렉터리
    GetSystemDirectory(infoBuf, INFO_BUFFER_SIZE);
    _tprintf(TEXT("\n시스템 디렉터리: \t%s"), infoBuf);

    // Get and display the Windows directory. Windows 디렉터리
    GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
    _tprintf(TEXT("\nWindows 디렉터리: \t%s"), infoBuf);

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

    printf("\n윈도우 버전 : Version is %d.%d (%d)",
        dwMajorVersion,
        dwMinorVersion,
        dwBuild);

    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    // 총 실제 메모리
    _tprintf(TEXT("\n총 실제 메모리: \t\t%*I64d MB"),
        WIDTH, statex.ullTotalPhys / DIV / DIV);

    // 사용 가능한 실제 메모리
    _tprintf(TEXT("\n사용 가능한 실제 메모리: \t%*I64d MB"),
        WIDTH, statex.ullAvailPhys / DIV / DIV);

    // 가상 메모리: 최대 크기
    _tprintf(TEXT("\n가상 메모리: 최대 크기: \t%*I64d MB"),
        WIDTH, statex.ullTotalPageFile / DIV / DIV);

    // 가상 메모리: 사용 가능
    _tprintf(TEXT("\n가상 메모리: 사용 가능: \t%*I64d MB"),
        WIDTH, statex.ullAvailPageFile / DIV / DIV);

    // 가상 메모리: 사용 중
    _tprintf(TEXT("\n가상 메모리: 사용 중: \t\t%*I64d MB"),
        WIDTH, (statex.ullTotalPageFile / DIV / DIV) - (statex.ullAvailPageFile / DIV / DIV));
    
    printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}