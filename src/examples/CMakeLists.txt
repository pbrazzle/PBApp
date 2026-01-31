add_executable(DisplaySize DisplaySize.cpp)
target_include_directories(DisplaySize PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(DisplaySize PBApp user32 gdi32)

add_executable(WindowCloner WindowCloner.cpp)
target_include_directories(WindowCloner PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(WindowCloner PBApp user32 gdi32)