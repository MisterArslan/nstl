cmake_minimum_required(VERSION 3.5)

project(nstl)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS "-fsanitize=address -g")

include_directories(include)

enable_testing()

FIND_PACKAGE( Boost COMPONENTS system filesystem unit_test_framework REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_definitions(-DBOOST_TEST_MAIN -DBOOST_TEST_DYN_LINK)

add_executable(test_list tests/test_list.cpp)

target_link_libraries(test_list ${Boost_LIBRARIES})

add_test(test_list test_list)

add_executable(main tests/main.cpp)
