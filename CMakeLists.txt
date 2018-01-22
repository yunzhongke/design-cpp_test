cmake_minimum_required(VERSION 3.5)
project(design_test)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")#当前操作系统

#编译版本
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    exec_program(g++ ARGS "--version|grep ^g++|awk '{print $4}'" OUTPUT_VARIABLE g++_version)
    message(STATUS "g++_version:" ${g++_version})
endif()

#判断编译器是否支持C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X) #2009
if(COMPILER_SUPPORTS_CXX11) 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  add_definitions(-DCOMPILEDWITHC11)
  message(STATUS "using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  add_definitions(-DCOMPILEDWITHC0X)
  message(STATUS "using flag -std=c++0x.")
else()
  message(FATAL_ERROR
    "the compiler ${CMAKE_CXX_COMPILER} has no C++11 support. "
    "please use a different C++ compiler.")
endif()

add_compile_options(-g)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} examples_srcs)

#根据传参生成可执行程序
function(get_same_file src_val)
    foreach(file ${examples_srcs})
        if (${file} MATCHES "${src_val}" AND ${file} MATCHES "main")
            add_executable(${src_val} ${src_val}.cpp ${file})
            if (${src_val} MATCHES "facade")
                target_link_libraries(${src_val} pthread)
            endif()
        endif()
    endforeach()
endfunction()

# 找到没有main函数的源文件
foreach(source_file ${examples_srcs})
    get_filename_component(name ${source_file} NAME_WE)
    get_filename_component(path ${source_file} PATH)
    
    if(NOT ${name} MATCHES "main")
        get_same_file(${name})
    endif()
    if (${name} MATCHES "singleton")
        add_executable(${name} ${source_file})
        target_link_libraries(${name} pthread)
    endif()
endforeach()


