cmake_minimum_required(VERSION 2.8.4)
project(viloet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
    vm/vm.cpp
    vm/vm.h
    main.cpp
    utils.cpp
    utils.h
    vm/vtypes.h)

add_executable(viloet ${SOURCE_FILES})