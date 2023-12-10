#include <stdio.h>
#include <windows.h>

int main(void){

STARTUPINFOW si = {0}; 
PROCESS_INFORMATION pi = {0};

    if (!CreateProcessW( L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){
    printf("(-) failed to create process, error: %ld", GetLastError());
    return EXIT_FAILURE;
    }
    DWORD TID = pi.dwThreadId; // thread id
    DWORD PID = pi.dwProcessId; // process id
    HANDLE hTheard = pi.hThread;  // thread handle
    HANDLE hProcess = pi.hProcess; //  process handle

    printf("(+) got handle to process\n");
    printf("(+) process started, pid: %ld\n", PID);
    printf("(+) pid: %ld, handle: %ld\n", PID, hProcess);
    printf("(+) tid: %ld, handle: %ld\n", TID, hTheard);

    WaitForSingleObject(hProcess, INFINITE); // wait for process to finish
    printf("(+) process finished\n");

    CloseHandle(hTheard); // close thread handle
    CloseHandle(hProcess); // close process handle
    return EXIT_SUCCESS;
    } 