#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>


void terminate() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pEntry;
    const wchar_t* process = L"agent.x64.equ8.exe";
    pEntry.dwSize = sizeof(pEntry);

    if (Process32First(snapshot, &pEntry))
    {
        do
        {
            if (!_wcsicmp(pEntry.szExeFile, process))
            {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)pEntry.th32ProcessID);
                TerminateProcess(hProcess, 0);
                std::cout << "Terminated Equ8" << std::endl;
            }
            
        } while (Process32Next(snapshot, &pEntry));
    
        std::cout << "Equ8 process not detected" << std::endl;
    }
}

int main() {
Terminate();
return 0;
}
