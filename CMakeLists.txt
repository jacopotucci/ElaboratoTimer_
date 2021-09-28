cmake_minimum_required(VERSION 3.20)
project(ElaboratoTimer_)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Tests)

set(SOURCE_FILES main.cpp Data.cpp Data.h Ora.cpp Ora.h)
add_executable(ElaboratoTimer_ main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ElaboratoTimer_ core)


set(CURSES_NEED_NCURSES, TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries(ElaboratoTimer_ ${CURSES_LIBRARIES})