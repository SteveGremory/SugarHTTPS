#pragma once
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <cstring>

struct request {
    
    const char * url;
    std::vector<const char *> headers;
    const char * data;
    curl_slist* list = NULL;

    request& post();

    request& download(char outfilename[FILENAME_MAX]);

    request& get();

    request& make_request();

    request& text();
    
    CURL *handle = curl_easy_init();

private:

    static size_t store_text(char * buffer, size_t itemsize, size_t number_items, void* ignore);

};