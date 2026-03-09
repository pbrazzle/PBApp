#pragma once

#include <string_view>
#include <windows.h>

constexpr std::string_view getMessageName(const UINT msgNum) {
    switch (msgNum) {
        case WM_MOUSEMOVE:  return "WM_MOUSEMOVE";
        case WM_PAINT:      return "WM_PAINT";
        default:            return "UNKNOWN";
    }
}
