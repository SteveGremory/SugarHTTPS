cmake_minimum_required(VERSION 3.0.0)
project(SugarHTTPS VERSION 0.1.0)

set(CMAKE_PREFIX_PATH $CMAKE_PREFIX_PATH "~/vcpkg/installed/x64-osx/")
set(CMAKE_TOOLCHAIN_FILE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

enable_testing()

include_directories(
    "include/"
    "include/RestClient_Implementation/"
    "include/cURL_Implementation/"
)

add_executable(${PROJECT_NAME} 
    "include/RestClient_Implementation/SugarHTTPS_RestClient.cpp"
    "include/cURL_Implementation/SugarHTTPS_cURL.cpp"
    main.cpp
)

find_package(restclient-cpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE restclient-cpp)

find_package(CURL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)


find_package(unofficial-curlpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::curlpp::curlpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
