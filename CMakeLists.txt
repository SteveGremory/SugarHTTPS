cmake_minimum_required(VERSION 3.14)
project("SugarHTTPS")

# Get the CC files
file(GLOB SUGARHTTPS_SOURCES 
    "src/*.cpp"
)

# Set C++ options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Set options for library compilation
option(SUGARHTTPS_STATIC ON)
option(SUGARHTTPS_INSTALL OFF)
# Tell curl to not build the executable
set(BUILD_CURL_EXE OFF)

# add curl
add_subdirectory("deps/curl")

# Build static if static libs and vice-versa
if (SUGARHTTPS_STATIC)
    message("Compiling static libraries for SugarHTTPS")
    add_library(SugarHTTPS-static STATIC ${SUGARHTTPS_SOURCES})
    set(CURL_STATICLIB ON)
else()
    message("Compiling shared libraries for SugarHTTPS")
    add_library(SugarHTTPS SHARED ${SUGARHTTPS_SOURCES})
endif(SUGARHTTPS_STATIC)

# Add include dirs
target_include_directories(SugarHTTPS PUBLIC "include" "deps/curl/include")

# static libs magik
unset(SUGARHTTPS_STATIC CACHE) 

# Link cURL to SugarHTTPS
target_link_libraries(SugarHTTPS libcurl)

# Testing
add_executable(test testing/MakeRequest.cc)
target_include_directories(test PUBLIC src/)
target_link_libraries(test SugarHTTPS)
