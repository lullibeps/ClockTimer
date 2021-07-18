cmake_minimum_required(VERSION 3.17)
project(ClockTimer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES ClockData.h ClockData.cpp ClockTimerFrame.cpp ClockTimerFrame.h Countdown.h Countdown.cpp)
add_executable(ClockTimer Application.h Application.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ClockTimer core)

target_link_libraries(ClockTimer ${wxWidgets_LIBRARIES})