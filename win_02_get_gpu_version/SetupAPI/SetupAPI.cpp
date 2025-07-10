#include <windows.h>
#include <setupapi.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <locale>

#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "version.lib")

void PrintDriverVersionFromPath(const std::wstring& driverPath) {
    DWORD dummy;
    DWORD size = GetFileVersionInfoSizeW(driverPath.c_str(), &dummy);
    if (size == 0) {
        std::wcerr << L"Unable to get version info size for file: " << driverPath << std::endl;
        return;
    }

    std::vector<BYTE> buffer(size);
    if (!GetFileVersionInfoW(driverPath.c_str(), 0, size, buffer.data())) {
        std::wcerr << L"Failed to get version info for file: " << driverPath << std::endl;
        return;
    }

    VS_FIXEDFILEINFO* verInfo = nullptr;
    UINT len = 0;
    if (!VerQueryValueW(buffer.data(), L"\\", reinterpret_cast<LPVOID*>(&verInfo), &len)) {
        std::wcerr << L"Failed to query version info for file: " << driverPath << std::endl;
        return;
    }

    std::wcout << L"Driver File: " << driverPath << std::endl;
    std::wcout << L"Driver Version: "
        << HIWORD(verInfo->dwFileVersionMS) << L"."
        << LOWORD(verInfo->dwFileVersionMS) << L"."
        << HIWORD(verInfo->dwFileVersionLS) << L"."
        << LOWORD(verInfo->dwFileVersionLS) << std::endl;
    std::wcout << L"-----------------------------" << std::endl;
}

void EnumerateDevicesAndPrintVersions(const GUID& classGuid, const wchar_t* className) {
    HDEVINFO hDevInfo = SetupDiGetClassDevsW(&classGuid, NULL, NULL, DIGCF_PRESENT);
    if (hDevInfo == INVALID_HANDLE_VALUE) {
        std::wcerr << L"SetupDiGetClassDevsW failed for " << className << std::endl;
        return;
    }

    SP_DEVINFO_DATA devInfoData;
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    std::wcout << L"=== Enumerating devices for class: " << className << L" ===" << std::endl;

    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData); ++i) {
        WCHAR desc[1024];
        if (!SetupDiGetDeviceRegistryPropertyW(
            hDevInfo, &devInfoData, SPDRP_DEVICEDESC,
            NULL, (PBYTE)desc, sizeof(desc), NULL)) {
            continue;
        }

        std::wcout << L"Device: " << desc << std::endl;

        // ��ȡ������������Service Name��
        WCHAR serviceName[256] = { 0 };
        bool found = false;
        if (SetupDiGetDeviceRegistryPropertyW(hDevInfo, &devInfoData, SPDRP_SERVICE,
            NULL, (PBYTE)serviceName, sizeof(serviceName), NULL)) {
            found = true;
        }

        if (found) {
            WCHAR systemDir[MAX_PATH] = { 0 };
            if (GetSystemDirectoryW(systemDir, MAX_PATH) == 0) {
                std::wcerr << L"Failed to get system directory." << std::endl;
                continue;
            }
            std::wstring driverPath = systemDir;
            driverPath += L"\\drivers\\";
            driverPath += serviceName;
            driverPath += L".sys";

            PrintDriverVersionFromPath(driverPath);
        }
        else {
            std::wcerr << L"Failed to get driver service name for device: " << desc << std::endl;
        }
    }

    SetupDiDestroyDeviceInfoList(hDevInfo);
}



/*
SetupAPI ��ʽ��ȡ�������汾�������ļ���sys���ļ��İ汾�ţ���������������������汾�š�
WMI ��ȡ�İ汾���������ġ������汾�š����� INF �ж���İ汾���������ӽ��豸�������������������ʾ�İ汾�š�
*/

int wmain() {
    std::wcout.imbue(std::locale(""));

    // �Կ��豸 GUID
    GUID displayClassGuid;
    CLSIDFromString(L"{4d36e968-e325-11ce-bfc1-08002be10318}", &displayClassGuid);

    // �����豸 GUID
    GUID networkClassGuid;
    CLSIDFromString(L"{4d36e972-e325-11ce-bfc1-08002be10318}", &networkClassGuid);

    EnumerateDevicesAndPrintVersions(displayClassGuid, L"Display");
    EnumerateDevicesAndPrintVersions(networkClassGuid, L"Network");

    return 0;
}
