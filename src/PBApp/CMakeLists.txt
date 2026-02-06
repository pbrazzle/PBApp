set(SOURCES
    Bitmap.cpp
    Controls/Button.cpp
    Controls/Checkbox.cpp
    Controls/Control.cpp
    Graphics.cpp
    PBApp.cpp
    Window.cpp)

add_library(PBApp STATIC ${SOURCES})
target_include_directories(PBApp PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_SOURCE_DIR}/src)