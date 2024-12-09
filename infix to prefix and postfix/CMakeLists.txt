cmake_minimum_required(VERSION 3.28)
project(infix)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/VSCode/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(infix main.cpp
)
target_link_libraries(infix sfml-graphics sfml-window sfml-system)
