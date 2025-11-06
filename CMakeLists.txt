cmake_minimum_required(VERSION 3.14)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_library(${PROJECT_NAME}_lib
    src/array.cpp
    src/pentagon.cpp
    src/hexagon.cpp
    src/octagon.cpp
)

target_include_directories(${PROJECT_NAME}_lib PUBLIC includes)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

if(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE m)
    target_link_libraries(${PROJECT_NAME}_lib PUBLIC m)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)