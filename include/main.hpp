#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <cstring>

int some() {
    /* Init CURL */
    CURL * curl = curl_easy_init();
    char outfilename[FILENAME_MAX] = "page1.htm";
    FILE *fp = fopen(outfilename,"wb");

    /* Check If CURL failed to init */
    if (!curl) {
        std::cout << "Init Failed.\n";
        return EXIT_FAILURE;
    }

    /* Set Options */
    curl_easy_setopt(curl, CURLOPT_URL, "https://duckduckgo.com");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    /* Perform the action */
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        std::cout << "Download Problem: " <<  curl_easy_strerror(result) << "\n";
    } else if (result == CURLE_OK) {
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        std::cout << "Request Succeded\n" << response_code;
    }
    
    /* Cleanup the memory after stuff is done. */
    fclose(fp);
    curl_easy_cleanup(curl);
}


struct request {
    CURL *handle = curl_easy_init();
    std::string url;
    std::vector<std::string> headers;
    const char * data;

    request& post() {
        
        /* Make a curl list, get every value from the headers vector, put it in the curl list. */
        struct curl_slist *list = NULL;
        for (auto& item : headers) {
            list = curl_slist_append(list, item.c_str());
        }
        /* Add Post Data */
        long length = (long)strlen(data);
        /* size of the POST data */
        curl_easy_setopt(handle, CURLOPT_POSTFIELDSIZE, length);
        
        /* pass in a pointer to the data - libcurl will not copy */
        curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data);
        
        /* Set Headers */
        curl_easy_setopt(handle, CURLOPT_HTTPHEADER, list);
        return *this;
    
    }

    request& download(char outfilename[FILENAME_MAX]) {
        FILE *fp = fopen(outfilename,"wb");
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp);
        fclose(fp);
    }

    request& get() {
        /* Add Opts. */
        curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, NULL);
        return *this;
    }

    request& make_request() {
        CURLcode response = curl_easy_perform(handle);
        if (response == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &response_code);
            std::cout << "Request Succeded! Response Code: " << response_code << "\n";
            curl_easy_cleanup(handle);
            return *this;
        } else if (response != CURLE_OK) {
            std::cout << "Request Failed: " <<  curl_easy_strerror(response) << "\n";
            curl_easy_cleanup(handle);
            return *this;
        }
    }
    request& text() {
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, store_text);
        return *this;
    }
private:
    static size_t store_text(char * buffer, size_t itemsize, size_t number_items, void* ignore) {
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
};