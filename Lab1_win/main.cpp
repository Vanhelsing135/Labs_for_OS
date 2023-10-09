#include<Windows.h>
#include<stdio.h>

int main(VOID) {
    STARTUPINFO startInfo;
    PROCESS_INFORMATION processInfo;
    DWORD exitCode;
    ZeroMemory(&startInfo, sizeof(startInfo));
    ZeroMemory(&processInfo, sizeof(processInfo));
    if (!CreateProcess(L"C:\\Users\\vanbe\\source\\repos\\lab1_OS\\x64\\Debug\\process.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startInfo, &processInfo)) {
        printf("Creating process is failed\n" + GetLastError());
        return 1;
    }

    WaitForSingleObject(processInfo.hProcess, INFINITE);
    printf("Subprocess terminated with code:");
    fflush(stdout);
    GetExitCodeProcess(processInfo.hProcess, &exitCode);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
    return 0;
}

/*#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(
		L"C:\\Users\\vanbe\\source\\repos\\lab1_OS\\x64\\Debug\\process.exe",
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}*/