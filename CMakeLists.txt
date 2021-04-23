cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SOLID_time_and_zone_converter)

set(HEADERS 
    include/ConsoleParser.hpp
    include/Time.hpp
    include/TimeZone.hpp
    include/TimeZoneConverter.hpp     
    include/TimeZoneConverterUtils.hpp     
)

set(SRC 
    main.cpp
    src/ConsoleParser.cpp
    src/Time.cpp
    src/TimeZone.cpp
    src/TimeZoneConverter.cpp     
)

enable_testing()

# running ctest or make test does not display failing tests
# the run_tests target is a walkaround (make run)
add_custom_target(run_tests COMMAND ${CMAKE_CTEST_COMMAND}
    --output-on-failure
)

add_subdirectory(googletest)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} ${SRC}) 

add_library(${PROJECT_NAME}_LIB STATIC ${SRC} ${HEADERS})
