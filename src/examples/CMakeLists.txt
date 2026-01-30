add_executable(DisplaySize DisplaySize.cpp)
target_include_directories(DisplaySize PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(DisplaySize PBApp user32 gdi32)