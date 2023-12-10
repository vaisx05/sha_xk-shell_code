#include <stdio.h>
#include <windows.h>

int main(void) {
    
  /* BOOL CreateProcessW(
  [in, optional]      LPCWSTR               lpApplicationName,
  [in, out, optional] LPWSTR                lpCommandLine,
  [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
  [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
  [in]                BOOL                  bInheritHandles,
  [in]                DWORD                 dwCreationFlags,
  [in, optional]      LPVOID                lpEnvironment,
  [in, optional]      LPCWSTR               lpCurrentDirectory,
  [in]                LPSTARTUPINFOW        lpStartupInfo,
  [out]               LPPROCESS_INFORMATION lpProcessInformation
);*/ 

STARTUPINFOW si = {0}; // initialize startup info
PROCESS_INFORMATION pi = {0}; // initialize process info

    if ( !CreateProcessW(
        L"C:\\Windows\\System32\\notepad.exe", // application name
        NULL,
        NULL,
        NULL,
        FALSE,
        BELOW_NORMAL_PRIORITY_CLASS, //process priority
        NULL,
        NULL,
        &si, // process startup info
        &pi // process information
    )) // if CreateProcessW returns 0, it failed
    {
    printf("(-) failed to create process, error: %ld", GetLastError()); // print error code
    return EXIT_FAILURE;
    }

    printf("(+) process created, pid: %ld", pi.dwProcessId); // print process id 
    return EXIT_SUCCESS;
}