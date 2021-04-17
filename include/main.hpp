#include <iostream>
#include <curl/curl.h>

size_t got_data(char * buffer, size_t itemsize, size_t number_items, void* ignore) {
    size_t bytes = itemsize * number_items;
    int line_number = 1;
    std::cout << "Chunk Size: " << bytes << "\n";
    std::cout << line_number << ": \t";
    for (int i = 0; i < bytes; i++) {
        std::cout << buffer[i];
        if (buffer[i] == '\n')  {
            line_number++;
            std::cout << line_number << ": \t";
        }
    }
    std::cout << "\n\n";
    return bytes;
}



struct request {
    std::string url;
    std::string method;

    void printValues() {
        std::cout << "\n" << url << "\n";
        std::cout << method << "\n";
    }

    void get() {
        /* Init cURL */
        CURL *curl = curl_easy_init();

        /* Add Opts. */
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
        
        /* Make request */
        CURLcode response;
        if (response == CURLE_OK) {
            std::cout << "Request Succeded!\n";
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        } else if (response != CURLE_OK) {
            std::cout << "Request Failed: " <<  curl_easy_strerror(response) << "\n";;
        }
    }
};