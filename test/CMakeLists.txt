cmake_minimum_required(VERSION 3.5)

add_subdirectory( ./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(EXECUTABLE_NAME "runAllTests")
set(TEST_SOURCE_FILES HeroTests.cpp)
add_executable(${EXECUTABLE_NAME} runAllTests.cpp HeroTests.cpp MobTests.cpp NPCTest.cpp)
target_link_libraries(runAllTests gtest gtest_main core)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()