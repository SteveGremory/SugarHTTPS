cmake_minimum_required(VERSION 3.14)

project("SugarHTTPS")

file(GLOB SUGARHTTPS_SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cc"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(SUGARHTTPS_STATIC ON)
option(SUGARHTTPS_INSTALL OFF)

set(BUILD_CURL_EXE OFF)

add_subdirectory("${CMAKE_SOURCE_DIR}/deps/curl")


if (SUGARHTTPS_STATIC)
    message("Compiling static libraries for SugarHTTPS")
    add_library(SugarHTTPS-static STATIC ${SUGARHTTPS_SOURCES})
    set(CURL_STATICLIB ON)
else()
    message("Compiling shared libraries for SugarHTTPS")
    add_library(SugarHTTPS SHARED ${SUGARHTTPS_SOURCES})
endif(SUGARHTTPS_STATIC)

target_include_directories(SugarHTTPS PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/deps/curl/include")

unset(SUGARHTTPS_STATIC CACHE) 

target_link_libraries(SugarHTTPS libcurl)

