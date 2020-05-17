cmake_minimum_required(VERSION 3.0)

project(calculator)

add_executable(calculator_test test.cpp calculator.cpp)
target_compile_options(calculator_test PRIVATE -Wall -Wextra -pedantic -O2)
