cmake_minimum_required(VERSION 3.21)
project(Self_Test_CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Self_Test_CXX Person.cpp Person.h Student.cpp Student.h Professor.cpp Professor.h main.cpp)

add_executable(TestNewDelete Person.cpp Person.h Student.cpp Student.h Professor.cpp Professor.h TestNewDelete.cpp)

add_executable(TestMemLeak Person.cpp Person.h Student.cpp Student.h Professor.cpp Professor.h TestMemLeak.cpp)