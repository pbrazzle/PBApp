#pragma once

#include <stdexcept>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class PBApp {};

PBApp* createApp();

int main();