cmake_minimum_required(VERSION 3.25)
project(CPPLearn)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(CPPLearn main_C++11.cpp Sort.cpp Sort.h AddressBook.cpp AddressBook.h Cube.cpp Cube.h Test.cpp Test.h  ThreadPool.cpp ThreadPool.h)

target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)