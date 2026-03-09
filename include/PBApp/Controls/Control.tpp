#include <windows.h>

#include <string>

class Control;

HWND createControlHandle(HWND parent, const std::string& className, DWORD style);

void registerControl(Control* control, HWND handle);

template <typename ControlBase, typename ControlDerived>
ControlBase* createControl(HWND parent, const std::string& className, DWORD style) {
    HWND handle = createControlHandle(parent, className, style);
    ControlBase* control = new ControlDerived(handle);
    registerControl(control, handle);  
    
    return control;
}