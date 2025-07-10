// Get VGA (graphics) and Ethernet driver version info on Windows 11
// Using WMI - Win32_PnPSignedDriver

#include <iostream>
#include <Windows.h>
#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

void PrintDriverVersion(const std::wstring& filterKeyword) {
    HRESULT hres;

    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cerr << "Failed to initialize COM." << std::endl;
        return;
    }

    hres = CoInitializeSecurity(NULL, -1, NULL, NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL, EOAC_NONE, NULL);
    if (FAILED(hres)) {
        std::cerr << "Failed to initialize security." << std::endl;
        CoUninitialize();
        return;
    }

    IWbemLocator* pLoc = nullptr;
    hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&pLoc);
    if (FAILED(hres)) {
        std::cerr << "Failed to create IWbemLocator." << std::endl;
        CoUninitialize();
        return;
    }

    IWbemServices* pSvc = nullptr;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pSvc);
    if (FAILED(hres)) {
        std::cerr << "Failed to connect to WMI." << std::endl;
        pLoc->Release();
        CoUninitialize();
        return;
    }

    hres = CoSetProxyBlanket(pSvc,
        RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL,
        RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL, EOAC_NONE);

    IEnumWbemClassObject* pEnumerator = nullptr;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT DeviceName, DriverVersion, Manufacturer FROM Win32_PnPSignedDriver"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL, &pEnumerator);

    if (FAILED(hres)) {
        std::cerr << "WMI query failed." << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return;
    }

    IWbemClassObject* pclsObj = nullptr;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if (uReturn == 0) break;

        VARIANT vtDeviceName, vtDriverVersion, vtManufacturer;
        VariantInit(&vtDeviceName);
        VariantInit(&vtDriverVersion);
        VariantInit(&vtManufacturer);

        pclsObj->Get(L"DeviceName", 0, &vtDeviceName, 0, 0);
        pclsObj->Get(L"DriverVersion", 0, &vtDriverVersion, 0, 0);
        pclsObj->Get(L"Manufacturer", 0, &vtManufacturer, 0, 0);

        std::wstring name = vtDeviceName.bstrVal ? vtDeviceName.bstrVal : L"";
        if (name.find(filterKeyword) != std::wstring::npos) {
            std::wcout << L"Device Name:  " << vtDeviceName.bstrVal << std::endl;
            std::wcout << L"Manufacturer: " << vtManufacturer.bstrVal << std::endl;
            std::wcout << L"Driver Ver.:  " << vtDriverVersion.bstrVal << std::endl;
            std::wcout << L"-----------------------------" << std::endl;
        }

        VariantClear(&vtDeviceName);
        VariantClear(&vtDriverVersion);
        VariantClear(&vtManufacturer);
        pclsObj->Release();
    }

    pSvc->Release();
    pLoc->Release();
    pEnumerator->Release();
    CoUninitialize();
}


// WMI 是 Windows 官方公开接口，不依赖任何厂商 SDK，也无版权风险，非常适合嵌入商用产品中。
int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::wcout.imbue(std::locale(""));

    std::wcout << L"--- VGA Driver Info ---" << std::endl;
    PrintDriverVersion(L"Graphics");

    std::wcout << L"\n--- Ethernet / WiFi Driver Info ---" << std::endl;
    PrintDriverVersion(L"Ethernet");
    PrintDriverVersion(L"Wi-Fi");

    return 0;
}