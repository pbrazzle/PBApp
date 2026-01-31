set(SOURCES
    PBApp.cpp
    Window.cpp)

add_library(PBApp STATIC ${SOURCES})
target_include_directories(PBApp PUBLIC ${CMAKE_SOURCE_DIR}/include PRIVATE ${CMAKE_SOURCE_DIR}/src)