cmake_minimum_required(VERSION 3.5)

project(nstl)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

FILE(GLOB SOURCES "src/*.cpp")

add_library(nstl ${SOURCES} include/list.h include/allocator.h include/list.h include/size_t.h include/ptrdiff_t.h include/numeric_limits.h)

enable_testing()

FIND_PACKAGE( Boost COMPONENTS system filesystem unit_test_framework REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_definitions(-DBOOST_TEST_MAIN -DBOOST_TEST_DYN_LINK)

add_executable(reverse_test tests/test.cpp include/list.h include/allocator.h include/list.h include/size_t.h include/ptrdiff_t.h include/numeric_limits.h)
add_executable(linked_list src/linked_list.cpp include/allocator.h include/list.h include/size_t.h include/ptrdiff_t.h include/numeric_limits.h)

target_link_libraries(reverse_test nstl ${Boost_LIBRARIES})

add_test(reverse_test reverse_test)

