cmake_minimum_required(VERSION 3.5)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ClockDataTest.cpp ClockDataFixture.cpp CountdownTest.cpp)
add_executable(runClockDataTests ${TEST_SOURCE_FILES})
target_link_libraries(runClockDataTests gtest gtest_main core)
target_link_libraries(runClockDataTests ${wxWidgets_LIBRARIES})