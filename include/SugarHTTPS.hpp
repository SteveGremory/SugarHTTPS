#pragma once
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <cstring>

class request {
public:
    const char * url;
    std::vector<const char *> headers;
    const char * data;
    curl_slist* list = NULL;
    bool speed_over_security = false;

    request& post();

    request& download(char outfilename[FILENAME_MAX]);

    request& get();

    request& make_request();

    void make_multiple_requests(std::vector<request> reqs);

    request& text();
    
    CURL *handle = curl_easy_init();

    FILE *fp;

private:

    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

    static size_t print_to_terminal(char * buffer, size_t itemsize, size_t number_items, void* ignore);

    static size_t print_nothing(char * buffer, size_t itemsize, size_t number_items, void* ignore);

};