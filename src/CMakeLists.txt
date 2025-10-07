cmake_minimum_required(VERSION 3.27)
project(design-mode)

option(SIMPLE_FACTORY_PATTERN "简单工厂模式" ON)

add_library(${PROJECT_NAME} STATIC)

if(SIMPLE_FACTORY_PATTERN)
    add_subdirectory(SimpleFactoryPattern)
endif()