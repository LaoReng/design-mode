cmake_minimum_required(VERSION 3.27)
project(design-mode)

add_compile_options("/source-charset:utf-8")

option(SIMPLE_FACTORY_PATTERN "简单工厂模式" ON)
option(STRATEGY "策略模式" ON)
option(DECORATOR "装饰模式" ON)

set(BUILD_TYPE "Debug" CACHE STRING "构建类型")

set(CMAKE_BUILD_TYPE ${BUILD_TYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 如果当前是DEBUG则生成可执行程序，RELEASE则生成库文件
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(
        ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )
else()
    add_library(${PROJECT_NAME} STATIC)
endif()

if(SIMPLE_FACTORY_PATTERN)
    add_subdirectory(SimpleFactoryPattern)
endif()
if(STRATEGY)
    add_subdirectory(Strategy)
endif()
if(DECORATOR)
    add_subdirectory(Decorator)
endif()