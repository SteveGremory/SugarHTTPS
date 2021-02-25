#include <curl/curl.h>
#include <iostream>
#include <exception>

size_t callBack(char* buffer, size_t itemSize, size_t nitems, void* ignoreThis) {

}

int get(std::string url, size_t callBackFunction) {
    CURL *curl = curl_easy_init();
    if(!curl) {
        std::cout << "Curl wasn't initialised.\n";
        return EXIT_FAILURE;
    }
    if(callBackFunction == NULL) {

    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBack);

    CURLcode result = curl_easy_perform(curl);
    if(result != CURLE_OK) {
        std::cout << "Curl Failed to get webpage.\n";
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}

int post() {
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: text/xml");
    
    /* post binary data */
    curl_easy_setopt(easyhandle, CURLOPT_POSTFIELDS, binaryptr);
    
    /* set the size of the postfields data */
    curl_easy_setopt(easyhandle, CURLOPT_POSTFIELDSIZE, 23L);
    
    /* pass our list of custom made headers */
    curl_easy_setopt(easyhandle, CURLOPT_HTTPHEADER, headers);
    
    curl_easy_perform(easyhandle); /* post away! */
    
    curl_slist_free_all(headers); /* free the header list */
}

int main() {
    get("www.google.com", NULL);
}