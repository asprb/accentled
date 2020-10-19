cmake_minimum_required(VERSION 3.10)

project(server)


set(SOURCES src/main.cpp src/accent.cpp src/serial.cpp include/accent.hpp include/serial.hpp)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(WIN32_LIBS "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.19041.0\\um\\x64")

add_executable(server ${SOURCES})

target_include_directories(server PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_include_directories(server PRIVATE "C:\\wxWidgets-3.1.4\\include")
target_include_directories(server PRIVATE "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\cppwinrt")
target_include_directories(server PRIVATE "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.19041.0\\shared")

target_compile_options(server PRIVATE /std:c++17)

target_link_libraries(server PRIVATE ${WIN32_LIBS}/Ole32.lib ${WIN32_LIBS}/Oleaut32.lib ${WIN32_LIBS}/Kernel32.lib ${WIN32_LIBS}/WindowsApp.lib)