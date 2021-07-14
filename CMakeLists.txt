cmake_minimum_required(VERSION 3.17)
project(ClockTimer)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(ClockTimer ClockTimerFrame.cpp ClockTimerFrame.h Application.cpp Application.h ClockData.cpp ClockData.h)

target_link_libraries(ClockTimer ${wxWidgets_LIBRARIES})