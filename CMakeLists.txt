cmake_minimum_required(VERSION 3.5.0)

project(PhotoInExcel)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(PhotoInExcel src/main.cpp)

target_link_libraries(PhotoInExcel ${OpenCV_LIBS})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
