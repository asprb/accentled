#include <windows.h>
#include <tchar.h>
#include <tuple>

using namespace std;

tuple<HANDLE, HANDLE, bool> daemonize(int argc, TCHAR *argv[]) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    HANDLE hParentProc = GetCurrentProcess();
    HANDLE hChildProc;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL,
        argv[1],
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
        return make_tuple(nullptr, nullptr, false);

    hChildProc = OpenProcess(NULL, FALSE, pi.dwProcessId);
    
    return make_tuple(hParentProc, hChildProc, true);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

bool isParent(HANDLE hProc) {
    return false;
}

bool killCurrentProc() {
    return TerminateProcess(GetCurrentProcess(), 0);
}