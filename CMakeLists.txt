cmake_minimum_required(VERSION 3.5)

project(nstl)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_CXX_FLAGS "-fsanitize=address -g")

include_directories(include)

enable_testing()

add_executable(test_list tests/test_list.cpp)
add_executable(test_vector tests/test_vector.cpp)

target_link_libraries(test_list ${Boost_LIBRARIES})
target_link_libraries(test_vector ${Boost_LIBRARIES})

add_test(test_list test_list)
add_test(test_vector test_vector)
