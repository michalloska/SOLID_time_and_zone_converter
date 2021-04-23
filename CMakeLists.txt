cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SOLID_time_and_zone_converter)

set(SRC 
    main.cpp
    src/ConsoleParser.cpp
    src/Time.cpp
    src/TimeZone.cpp
    src/TimeZoneConverter.cpp     
)

add_executable(${PROJECT_NAME} ${SRC}) 

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)