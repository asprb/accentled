//Our Headers
#include "accent.hpp"
#include "serial.hpp"

//Standard headers
#include <tuple>
#include <string>
#include <iostream>

//Windows headers
#include <windows.h>
#include <atlstr.h>

using namespace std;

int main(int argc, char *argv[]) {
    while (true) { //Consider rewrite of main loop later
        auto tRGBAccent = getAccentColor();
        CString r, g, b;

        r.Format("%d", get<0>(tRGBAccent));
        g.Format("%d", get<1>(tRGBAccent));
        b.Format("%d", get<2>(tRGBAccent));

        CString rgb = r+","+g+","+b;
        CString arudinoSerialPort = _T("\\\\.\\COM3"); //This is probably always gonna be COM3 for my use case but I plan to add auto detection eventually

        if(!writeSerial(arudinoSerialPort, rgb))
            return 1;

        Sleep(500);
    }

    return 0;
}