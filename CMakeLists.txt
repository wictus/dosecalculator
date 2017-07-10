project(dosecalculator)

add_definitions(-std=gnu++0x)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS Hist Gpad Graf MathCore) 
include(${ROOT_USE_FILE})

add_library(sources SHARED sources.cpp)
add_library(shieldings SHARED shieldings.cpp)
target_link_libraries(shieldings sources)
add_library(doseCalc SHARED doseCalculator.cpp)
target_link_libraries(doseCalc shieldings sources)
add_library(doseMap SHARED doseMap.cpp)
target_link_libraries(doseMap doseCalc ${ROOT_LIBRARIES})

add_executable(dosecalculator main.cpp)

target_link_libraries(dosecalculator sources shieldings doseCalc doseMap ${ROOT_LIBRARIES})