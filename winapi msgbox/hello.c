#include <windows.h>

int main(void) {
    
    MessageBoxW(NULL,L"MESSAGE ONE",L"APP01",MB_YESNOCANCEL | MB_DEFAULT_DESKTOP_ONLY | MB_ICONEXCLAMATION );
    return EXIT_SUCCESS;
}
 