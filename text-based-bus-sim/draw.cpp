#include "draw.h"
#include "CustomFunctions.h"
#include <iostream>
#include <winhttp.h>
#include <unordered_map>

CustomFunctions cfD;


void Draw::Dest(const std::string& dest, const std::string& num)
{
    static std::unordered_map<std::string, std::string> cache;

    std::string key = num + "|" + dest;

    if (cache.find(key) != cache.end()) {
        std::cout << cache[key];
        return;
    }

    HINTERNET s = WinHttpOpen(L"c/1", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        0, 0, 0);
    if (!s) return;

    HINTERNET c = WinHttpConnect(s, L"ascii-api.pages.dev",
        INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!c) { WinHttpCloseHandle(s); return; }

    std::wstring path =
        L"/?num=" +
        std::wstring(num.begin(), num.end()) +
        L"&dest=" +
        std::wstring(dest.begin(), dest.end());

    HINTERNET r = WinHttpOpenRequest(c, L"GET", path.c_str(),
        0, 0, 0, WINHTTP_FLAG_SECURE);
    if (!r) { WinHttpCloseHandle(c); WinHttpCloseHandle(s); return; }

    if (!WinHttpSendRequest(r, 0, 0, 0, 0, 0, 0) ||
        !WinHttpReceiveResponse(r, 0)) {
        WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);
        return;
    }

    std::string json, chunk;
    DWORD size = 0, read = 0;

    do {
        if (!WinHttpQueryDataAvailable(r, &size) || size == 0) break;

        chunk.resize(size);
        WinHttpReadData(r, &chunk[0], size, &read);
        json.append(chunk.c_str(), read);

    } while (size > 0);

    WinHttpCloseHandle(r);
    WinHttpCloseHandle(c);
    WinHttpCloseHandle(s);

    std::string ascii;

    size_t start = json.find("\"ascii\":\"");
    if (start != std::string::npos) {
        start += 9;
        size_t end = json.find("\"", start);
        ascii = json.substr(start, end - start);

        for (size_t p; (p = ascii.find("\\n")) != std::string::npos;)
            ascii.replace(p, 2, "\n");
    }

    cache[key] = ascii;

    std::cout << ascii;
}


void Clear() {
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
    std::cout << "                                                                                                                                                         \n";
}

void Draw::RollDestination(string RollToNum, string RollFromNum, string RollToDest, string RollFromDest)
{
    for (int i = 0; i < 11; i++) {
        int a = 22 - i;
        int b = 22 + a;

        b = b - 33;

        cfD.gotoXY(0, a);

        cfD.gotoXY(0, b);
        Dest(RollFromDest, RollFromNum);
        cfD.gotoXY(0, a);
        Dest(RollToDest, RollToNum);
        cfD.gotoXY(0, 23);
        Clear();

        cfD.gotoXY(0, 1);
        Clear();
        sleep_for(100ms);
    }
}