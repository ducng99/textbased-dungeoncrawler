cmake_minimum_required(VERSION 3.10.2)
set (CMAKE_CXX_STANDARD 17)
project(textbased_dungeoncrawler)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

if (EMSCRIPTEN)
    add_compile_options(-O3)
    add_link_options(--bind -lembind -sASYNCIFY -sMODULARIZE -sEXPORT_NAME=create_dungeoncrawler_module -sEXIT_RUNTIME -sENVIRONMENT=web -sEXPORTED_RUNTIME_METHODS=addOnExit)
endif(EMSCRIPTEN)

add_executable(textbased_dungeoncrawler ${SOURCES})
