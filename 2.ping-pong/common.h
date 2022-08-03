#include <Windows.h>

namespace common {
    union RealTime {
        ULARGE_INTEGER ui;
        FILETIME       ft;
    };

    inline UINT64 GetRealTime() {

        SYSTEMTIME st;
        SecureZeroMemory(&st, sizeof(st));
        GetSystemTime(&st);

        RealTime rt;
        SecureZeroMemory(&rt.ft, sizeof(rt.ft));
        SystemTimeToFileTime(&st, &rt.ft);

        return rt.ui.QuadPart;
    }

    inline SYSTEMTIME GetSystemTime(UINT64 real_time) {
        RealTime rt;
        SecureZeroMemory(&rt.ft, sizeof(rt.ft));
        rt.ui.QuadPart = real_time;

        SYSTEMTIME st;
        SecureZeroMemory(&st, sizeof(st));
        FileTimeToSystemTime(&rt.ft, &st);

        return st;
    }
}