project(dosecalculator)

add_definitions(-std=gnu++0x)

add_library(sources SHARED sources.cpp)

add_executable(dosecalculator main.cpp)

target_link_libraries(dosecalculator sources)