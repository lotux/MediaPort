#include "diskinfo.h"
#include <QList>
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")
#include <QDebug>


#define GUID_DEVINTERFACE_HUBCONTROLLER  "3abf6f2d-71c4-462a-8a92-1e6861e6af27";
#define BUFFER_SIZE  2048;

USB::USB(){

}
void USB::GetHostControllers()
{
    QList<USBController> HostList;
    UUID HostGUID;
    ::ZeroMemory(&HostGUID, sizeof(UUID));

    // Create uuid or load from a string by UuidFromString() function
    //::UuidCreate(&uuid);
    TCHAR *hub_guid_str = NULL;
    //const char *hub_guid_str = GUID_DEVINTERFACE_HUBCONTROLLER;
    hub_guid_str = TEXT(GUID_DEVINTERFACE_HUBCONTROLLER);

    ::UuidFromString((RPC_WSTR)hub_guid_str,&HostGUID);
    HDEVINFO m_hDevInfo;

    m_hDevInfo = SetupDiGetClassDevs(&HostGUID,0,NULL,DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if(INVALID_HANDLE_VALUE != m_hDevInfo)
    {

        int i = 0;
        bool Success;
        do{
            USBController host;
            host.ControllerIndex = i;



            SP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
            ::ZeroMemory(&DeviceInterfaceData,sizeof(SP_DEVICE_INTERFACE_DATA));
            DeviceInterfaceData.cbSize=sizeof(SP_DEVICE_INTERFACE_DATA);

            Success = SetupDiEnumDeviceInterfaces(m_hDevInfo, NULL, &HostGUID, 0, &DeviceInterfaceData);
            if (Success)
            {
                SP_DEVINFO_DATA DeviceInfoData;
                ::ZeroMemory(&DeviceInfoData,sizeof(SP_DEVINFO_DATA));
                DeviceInfoData.cbSize=sizeof(SP_DEVINFO_DATA);



                DWORD needed;
                SetupDiGetInterfaceDeviceDetail(m_hDevInfo, &DeviceInterfaceData, NULL, 0,
                                                &needed, NULL);
                PSP_INTERFACE_DEVICE_DETAIL_DATA detail =
                    (PSP_INTERFACE_DEVICE_DETAIL_DATA) malloc(needed);
                detail->cbSize = sizeof(PSP_INTERFACE_DEVICE_DETAIL_DATA);
                SetupDiGetInterfaceDeviceDetail(m_hDevInfo, &DeviceInterfaceData, detail,
                                                needed, NULL, NULL);






//                DWORD DetailDataSize = 300;
//                char * DetailDataBuffer = new char [DetailDataSize];
//                SP_DEVICE_INTERFACE_DETAIL_DATA DeviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA) DetailDataBuffer;
//                DeviceInterfaceDetailData.cbSize=sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

//                ULONG nRequiredSize = 300;
//                if(SetupDiGetDeviceInterfaceDetail(m_hDevInfo,
//                                                   &DeviceInterfaceData,
//                                                   DeviceInterfaceDetailData,
//                                                   DetailDataSize,
//                                                   NULL,
//                                                   NULL))
//                {
                    qDebug() << "PATH : "<< detail->DevicePath;
                    BYTE Buffer[200];
                    DWORD BufferSize = 0;
                    DWORD RegType;

                    if (SetupDiGetDeviceRegistryProperty(m_hDevInfo,
                                                         &DeviceInfoData,
                                                         SPDRP_DEVICEDESC,
                                                         &RegType,
                                                         Buffer,
                                                         sizeof(Buffer),
                                                         &BufferSize))
                    {
                        qDebug() << Buffer;
                    }
                    if (SetupDiGetDeviceRegistryProperty(m_hDevInfo,
                                                         &DeviceInfoData,
                                                         SPDRP_DRIVER,
                                                         &RegType,
                                                         Buffer,
                                                         sizeof(Buffer),
                                                         &BufferSize))
                    {
                        qDebug() << Buffer;
                    }


                }
                HostList << host;

         //}
         i++;
        }while(Success);
    }
}

USBController::USBController(){}
