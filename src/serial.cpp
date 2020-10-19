#include "serial.hpp"

#include <windows.h>
#include <strsafe.h>

//Credit for serial_write: http://members.ee.net/brey/Serial.pdf

bool writeSerial(CString SerialPort, CString data) { 
    DCB dcb;        
    DWORD byteswritten;              
    
    HANDLE hPort = CreateFile(               
        SerialPort,                            
        GENERIC_WRITE,                     
        0,                     
        NULL,                     
        OPEN_EXISTING,                     
        0,                     
        NULL              
    );              
    
    if (!GetCommState(hPort, &dcb))
        return false;             
    
    dcb.BaudRate = CBR_9600;       
    dcb.ByteSize = 8;       
    dcb.Parity = NOPARITY;        
    dcb.StopBits = ONESTOPBIT;  
    
    if (!SetCommState(hPort, &dcb))
        return false;              
        
    bool retVal = WriteFile(hPort, data, 1, &byteswritten, NULL);        
    CloseHandle(hPort);             
    return retVal;       
}