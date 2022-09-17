cmake_minimum_required(VERSION 3.10)

project(Calviz VERSION 0.0.2)

include_directories(include)

add_executable(Calviz
  src/Polynomial.cpp
  src/RSD.cpp
  src/Differrential.cpp
  src/Utility.cpp
  src/Processing.cpp
  src/calviz.cpp
  include/Polynomial.hpp
  include/RSD.hpp
  include/Differrential.hpp
  include/Utility.hpp
  include/Processing.hpp
  include/calviz.h
)

add_library(tinyexpr SHARED libs/tinyexpr.c)

target_link_libraries(Calviz tinyexpr)
