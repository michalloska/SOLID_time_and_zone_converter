cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${CMAKE_PROJECT_NAME}_UT)

set(SRC_UT
    ConsoleParserTestSuite.cpp
    TimeTestSuite.cpp
    TimeZoneConverterTestSuite.cpp
    TimeZoneTestSuite.cpp
    TimeZoneTestsUtils.hpp
)

add_executable(${PROJECT_NAME} ${SRC_UT}) 

target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    ${CMAKE_PROJECT_NAME}_LIB
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME} 
)