cmake_minimum_required(VERSION 4.2)

project(PBApp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if (${PROJECT_IS_TOP_LEVEL})
    add_subdirectory(examples)
    add_subdirectory(tests)
endif()