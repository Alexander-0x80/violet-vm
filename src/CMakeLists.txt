cmake_minimum_required(VERSION 2.8.4)
project(viloet)


include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(VM_FILES
    vm/vm.cpp
    vm/vm.h
    vm/main.cpp
    vm/vtypes.h
    etc/utils.cpp
    etc/utils.h)

set(ASM_FILES
    asm/main.cpp
    asm/vlasm.cpp
    asm/vlasm.h)

add_executable(violet ${VM_FILES})
add_executable(vlasm ${ASM_FILES})