add_executable(DisplaySize DisplaySize.cpp)
target_include_directories(DisplaySize PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(DisplaySize PBApp user32 gdi32)

add_executable(WindowCloner WindowCloner.cpp)
target_include_directories(WindowCloner PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(WindowCloner PBApp user32 gdi32)

add_executable(Paint Paint.cpp)
target_include_directories(Paint PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Paint PBApp user32 gdi32)

add_executable(Controls Controls.cpp)
target_include_directories(Controls PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Controls PBApp user32 gdi32)