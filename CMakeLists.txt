project(dosecalculator)

add_definitions(-std=gnu++0x)

add_library(sources SHARED sources.cpp)
add_library(shieldings SHARED shieldings.cpp)
add_library(doseCalc SHARED doseCalculator.cpp)
add_executable(dosecalculator main.cpp)

target_link_libraries(dosecalculator sources shieldings doseCalc)