#include "pch.h"
#include<Windows.h>
#include <iostream>

#define EC_W32(fnx) \
	[&]() -> LSTATUS { \
		const auto _lresult = (fnx); \
		if (_lresult != ERROR_SUCCESS) wprintf(L"lResult = 0x%08X from %hs\r\n", _lresult, #fnx); \
		return _lresult; \
	}()

int main()
{
	HKEY hKey{};
	const auto lResult = EC_W32(RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft", 0, KEY_READ | KEY_WOW64_64KEY, &hKey));
	if (lResult == ERROR_SUCCESS)
	{
		wprintf(L"hKey = 0x%08p\r\n", hKey);
		EC_W32(RegCloseKey(hKey));
	}
}