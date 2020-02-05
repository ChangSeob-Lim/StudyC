/*
  filename - main.c
  version - 1.0
  description - SystemInfo 출력하기
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lim Chang Seob.
*/

#include <stdlib.h>
#include <tchar.h>
#include <WinSock2.h>
#include <Windows.h>
#include <locale.h>
#include <sysinfoapi.h>
#include <stdio.h>

#define  ENV_VAR_STRING_COUNT  (sizeof(envVarStrings)/sizeof(TCHAR*))
#define INFO_BUFFER_SIZE 32767
#define DIV 1024
#define WIDTH 7
#pragma comment(lib,"ws2_32")

typedef BOOL(WINAPI* MYPROC)(LPTSTR, LPDWORD);
IN_ADDR GetDefaultMyIP();

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

    // ip 주소 얻는 소스코드
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    IN_ADDR addr;

    addr = GetDefaultMyIP();//디폴트 IPv4 주소 얻어오기
    printf("\t\t\t [01]: %s\n", inet_ntoa(addr));//IPv4 주소를 문자열로 출력

    WSACleanup();
    // 여기까지

    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure. 

    GetSystemInfo(&siSysInfo);

    // Display the contents of the SYSTEM_INFO structure. 

    printf("Hardware information: \n");
    printf("  OEM ID: %u\n", siSysInfo.dwOemId);
    printf("  Number of processors: %u\n",
        siSysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", siSysInfo.dwPageSize);
    printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
    printf("  Minimum application address: %lx\n",
        siSysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n",
        siSysInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n",
        siSysInfo.dwActiveProcessorMask);

	system("pause");
	return EXIT_SUCCESS;
}

IN_ADDR GetDefaultMyIP() // 네트워크 카드 ip
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
    {
        return addr;
    }

    HOSTENT* ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기

    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
        {
            memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//메모리 복사
            break;//반복문 탈출
        }

        ptr++;
    }

    return addr;
}