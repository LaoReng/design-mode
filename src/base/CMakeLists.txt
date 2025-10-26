cmake_minimum_required(VERSION 3.27)

set(
    ${PROJECT_NAME}_HeaderFile
    ${CMAKE_CURRENT_SOURCE_DIR}/function.h
    ${CMAKE_CURRENT_SOURCE_DIR}/binder.h
)
set(
    ${PROJECT_NAME}_SourceFile
)
target_sources(${PROJECT_NAME} PRIVATE
    ${${PROJECT_NAME}_HeaderFile}
    ${${PROJECT_NAME}_SourceFile}
)