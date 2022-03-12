include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runTests main.cpp queue_tests.cpp)

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests data_structures)