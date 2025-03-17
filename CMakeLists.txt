cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(test_unimore_racing)

find_package(OpenCV REQUIRED)

set(SRC_FILES
    demo/demo.cpp
    src/imageEditing.cpp
    src/Specs.cpp
    src/utils.cpp
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include  
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(demo ${SRC_FILES})

target_link_libraries(demo PRIVATE ${OpenCV_LIBS})
