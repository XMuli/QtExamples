cmake_minimum_required(VERSION 3.7)
project(DbSigSlot)

set(CMAKE_CXX_STANDARD 14)

add_executable(DbSigSlot main.cpp object.cpp object.h db_object.cpp)
