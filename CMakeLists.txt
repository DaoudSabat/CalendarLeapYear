cmake_minimum_required(VERSION 3.14)
project(CalendarLeapYear CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(calendar src/main.cpp src/calendar.cpp)
target_include_directories(calendar PRIVATE include)

add_executable(test_calendar tests/test_calendar.cpp src/calendar.cpp)
target_include_directories(test_calendar PRIVATE include)
