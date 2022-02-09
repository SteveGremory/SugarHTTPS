#pragma once
#include <cstring>
#include <curl/curl.h>
#include <iostream>
#include <vector>

class request {
public:
    const char* url;
    std::vector<const char*> headers;
    const char* data;
    int success = 0;
    long response_code = 0;

    CURL* handle = curl_easy_init();
    curl_slist* list = NULL;
    FILE* fp = NULL;

    ~request();

    request& post();

    request& download(std::string outfilename);

    request& get();

    request& make_request();

    request& text();

private:
    static size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream);

    static size_t print_to_terminal(char* buffer, size_t itemsize, size_t number_items, void* ignore);

    static size_t print_nothing(char* buffer, size_t itemsize, size_t number_items, void* ignore);
};