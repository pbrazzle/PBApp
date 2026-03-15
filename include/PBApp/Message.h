#pragma once

#include <string_view>
#include <windows.h>
#include <winuser.h>


constexpr std::string_view getMessageName(const UINT msgNum) {
    switch (msgNum) {
        case WM_MOUSEMOVE:      return "WM_MOUSEMOVE";
        case WM_PAINT:          return "WM_PAINT";
        case WM_NULL:           return "WM_NULL";
        case WM_CREATE:         return "WM_CREATE";
        case WM_DESTROY:        return "WM_DESTROY";           
        case WM_MOVE:           return "WM_MOVE";
        case WM_SIZE:           return "WM_SIZE";
        case WM_SETCURSOR:      return "WM_SETCURSOR";
        case WM_LBUTTONDOWN:    return "WM_LBUTTONDOWN";
        case WM_LBUTTONUP:      return "WM_LBUTTONUP";
        case WM_IME_SETCONTEXT: return "WM_IME_SETCONTEXT";
        case WM_SETFOCUS:       return "WM_SETFOCUS";
        case BM_SETSTATE:       return "BM_SETSTATE";
        case BM_SETCHECK:       return "BM_SETCHECK";
        case WM_GETDLGCODE:     return "WM_GETDLGCODE";
        case WM_CAPTURECHANGED: return "WM_CAPTURECHANGED";
        default:                return "UNKNOWN";
    }
}

