include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TESTS_SOURCE *.cpp)
add_executable(runTests ${TESTS_SOURCE})

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests data_structures)