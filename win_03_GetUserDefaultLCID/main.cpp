#include <windows.h>
#include <iostream>

int main() {
    // 获取用户默认的区域标识符
    LCID userLCID = GetUserDefaultLCID();
    std::cout << "User Default LCID: " << userLCID << std::endl;

    // 获取系统默认的区域标识符
    LCID systemLCID = GetSystemDefaultLCID();
    std::cout << "System Default LCID: " << systemLCID << std::endl;

    // 获取用户默认的区域名称
    WCHAR userLocaleName[LOCALE_NAME_MAX_LENGTH];
    int userLocaleNameLength = GetUserDefaultLocaleName(userLocaleName, LOCALE_NAME_MAX_LENGTH);
    if (userLocaleNameLength > 0) {
        std::wcout << L"User Default Locale Name: " << userLocaleName << std::endl;
    }
    else {
        std::cerr << "Failed to get user default locale name." << std::endl;
    }

    // 获取系统默认的区域名称
    WCHAR systemLocaleName[LOCALE_NAME_MAX_LENGTH];
    int systemLocaleNameLength = GetSystemDefaultLocaleName(systemLocaleName, LOCALE_NAME_MAX_LENGTH);
    if (systemLocaleNameLength > 0) {
        std::wcout << L"System Default Locale Name: " << systemLocaleName << std::endl;
    }
    else {
        std::cerr << "Failed to get system default locale name." << std::endl;
    }

    return 0;
}
