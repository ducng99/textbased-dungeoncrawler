cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 17)
project(textbased_dungeoncrawler)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

if (EMSCRIPTEN)
    add_compile_options(-O3)
    add_link_options(--bind -lembind -lidbfs.js -sASYNCIFY -sMODULARIZE -sENVIRONMENT=web -sEXPORT_ES6 -sEXPORTED_RUNTIME_METHODS=ccall)
endif(EMSCRIPTEN)

add_executable(textbased_dungeoncrawler ${SOURCES})
