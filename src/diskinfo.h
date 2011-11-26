#ifndef DISKINFO_H
#define DISKINFO_H
#include <windows.h>
#include <wtypes.h>
#include <initguid.h>
#include <QString>
extern "C"
{
 // This file is in the Windows DDK available from Microsoft.
 #include <setupapi.h>
 #pragma comment(lib,"setupapi.lib")
}

class USB
{
public:
    USB();
    static void GetHostControllers();
};

class USBPort{
};

class USBDevice{
};

class USBHub{
};

class USBController{
public:
    USBController();
    int ControllerIndex;
    BYTE ControllerDriverKeyName[200], ControllerDevicePath[200], ControllerDeviceDesc[200];
};
#endif // DISKINFO_H
