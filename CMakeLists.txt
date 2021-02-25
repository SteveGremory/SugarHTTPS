cmake_minimum_required(VERSION 3.0.0)
project(SugarHTTPS VERSION 0.1.0)

set(CMAKE_PREFIX_PATH $CMAKE_PREFIX_PATH "~/vcpkg/installed/x64-osx/")
set(CMAKE_TOOLCHAIN_FILE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(CTest)
enable_testing()

include_directories(
    "include/"
)

add_executable(${PROJECT_NAME} 
    "include/SugarHTTPS.cpp"
    main.cpp
)

find_package(restclient-cpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE restclient-cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
