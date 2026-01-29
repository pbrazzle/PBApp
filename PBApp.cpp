#include "PBApp.h"

#include <windows.h>

int main() {
    PBApp* app = createApp();

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}