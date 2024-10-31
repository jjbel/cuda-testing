cmake_minimum_required(VERSION 3.20)

project(cuda_hello LANGUAGES CXX CUDA)

add_executable(hello_cpp hello_cpp.cpp)
target_compile_features(hello_cpp PUBLIC cxx_std_20)

add_executable(hello_cu hello_cu.cu)
target_compile_features(hello_cu PUBLIC cxx_std_20)
set(CMAKE_CUDA_FLAGS "-arch=sm_50")
