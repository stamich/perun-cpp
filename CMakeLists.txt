cmake_minimum_required(VERSION 3.14)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler main.cpp FileLoader.h FileLoader.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h)