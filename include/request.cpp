#include "request.hpp"

request &request::post() {
    /* Set Headers */
    
    for (int i = 0; i < headers.size(); i++) {
        // curl_easy_setopt(handle, CURLOPT_POSTFIELDS, headers.at(i));
        list = curl_slist_append(list, headers.at(i));
    }
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, list);


    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(handle, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 1);
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(handle, CURLOPT_TCP_KEEPALIVE, 1L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 1L);
    
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(handle, CURLOPT_POSTFIELDSIZE, -1L);
    curl_easy_setopt(handle, CURLOPT_URL, url);


    return *this;
}

request& request::download(char outfilename[FILENAME_MAX]) {
    FILE *fp = fopen(outfilename,"wb");
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp);
    fclose(fp);
}

request& request::get() {
    /* Add Opts. */
    curl_easy_setopt(handle, CURLOPT_URL, url);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(handle, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 1);
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(handle, CURLOPT_TCP_KEEPALIVE, 1L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 1L);
    

    curl_easy_setopt(handle, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(handle, CURLOPT_COOKIE, "");
    return *this;
}

request& request::make_request() {
    /* Remove comment if you want it to be verbose */
    //curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
    CURLcode response = curl_easy_perform(handle);
    
    if (response == CURLE_OK) {
        long response_code;
        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &response_code);
        std::cout << "\nRequest Succeded! Response Code: " << response_code << '\n';
        curl_easy_cleanup(handle);
        curl_slist_free_all(list);
        return *this;
    } else if (response != CURLE_OK) {
        std::cout << "Request Failed: " <<  curl_easy_strerror(response) << '\n';
        curl_easy_cleanup(handle);
        curl_slist_free_all(list);
        return *this;
        
    }
}

request& request::text() {
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, store_text);
    return *this;
}

size_t request::store_text(char * buffer, size_t itemsize, size_t number_items, void* ignore) {
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
