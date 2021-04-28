/* For obvious reasons, include the header file */
#include "SugarHTTPS.hpp"


/* REQUESTS SECTION */
/* ===================================================================================================================================== */

/* POST REQUEST */
request &request::post() {
    /* Set Headers */
    for (int i = 0; i < headers.size(); i++) {
        list = curl_slist_append(list, headers.at(i));
    }

    /* Add the URL */
    curl_easy_setopt(handle, CURLOPT_URL, url);

    /* Print nothing to the terminal by default */
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, print_nothing);

    /* Headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, list);     /* Add Headers */
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);   /* Enable redirects */

    /* Data */
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data);     /* Add the data */
    curl_easy_setopt(handle, CURLOPT_POSTFIELDSIZE, -1L);   /* Set the post field's size */

    /* Same shit. */
    if (speed_over_security == true) {
        /* TODO: Read more in detail about all this */
        curl_easy_setopt(handle, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 1);
        curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(handle, CURLOPT_TCP_KEEPALIVE, 1L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 1L);
        /* Do the TODO */
        return *this;
    } else {
        /* end, return *this for chaining + */
        return *this;
    }
}

/* DOWNLOAD REQUEST */
request& request::download(char outfilename[FILENAME_MAX]) {
    /* Open the file to write the bytes to */
    fp = fopen(outfilename,"wb");
    /* Set opts */
    curl_easy_setopt(handle, CURLOPT_URL, url);  
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
    /* Tell libcURL about the writing functions */
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp);
    /* end, return *this for chaining */
    return *this;
}

/* GET REQUEST */
request& request::get() {
    
    /* Set URL and such */
    curl_easy_setopt(handle, CURLOPT_URL, url);

    /* Enable redirects */
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);

    /* Print nothing by default */
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, print_nothing);
    /* Check if Speed is needed more than security */
    if (speed_over_security == true) {
        /* Add Opts That make the request take less time. */
        curl_easy_setopt(handle, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 1);
        curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(handle, CURLOPT_TCP_KEEPALIVE, 1L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 1L);
        curl_easy_setopt(handle, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(handle, CURLOPT_COOKIE, "");
        /* TODO: UNDERSTAND WHAT ALL THOSE OPTS DO, DEEPLY. */
        return *this;
    } else {
        /* End, return your bitch */
        return *this;
    }
}

/* ===================================================================================================================================== */
/* REQUEST SECION ENDS */


/* FUNCTIONS SECTION */
/* ===================================================================================================================================== */

/* PUBLIC: Function to be added at the end of every request, this is the part where your request is actually executed. */
request& request::make_request() {
    /* Remove comment if you want it to be verbose */
    //curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);

    /* Store response in a variable. */
    CURLcode response = curl_easy_perform(handle);
    
    /* Check if request was successful */
    if (response == CURLE_OK) {
        /* Get the response code. */
        long response_code;
        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &response_code);
        /* Print the response code */
        std::cout << "\nRequest Succeded! Response Code: " << response_code << '\n';
        /* Cleanup */
        curl_easy_cleanup(handle);
        curl_slist_free_all(list);
        fclose(fp);
        /* end. */
        return *this;
    } else if (response != CURLE_OK) {
        /* If the request fucked up, Just print why it fucked up */
        std::cout << "Request Failed: " <<  curl_easy_strerror(response) << '\n';
        /* Cleanup */
        curl_easy_cleanup(handle);
        curl_slist_free_all(list);
        fclose(fp);
        /* end. */
        return *this;
        
    }
    return *this;
}

/* PUBLIC: Function To Print The HTTP response text to the terminal. */
request& request::text() {
    /* Letting libcURL know what to do with the acquired data */
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, print_to_terminal);
    return *this;
}

/* PRIVATE: Function to print the response to the terminal, Has to be a function because libcurl demands so. */
size_t request::print_to_terminal(char * buffer, size_t itemsize, size_t number_items, void* ignore) {
    /* Get the size of the response in bytes */
    size_t bytes = itemsize * number_items;
    /* Print the number of lines with the response. */
    int line_number = 1;
    std::cout << "Chunk Size: " << bytes << "\n";
    std::cout << line_number << ": \t";
    /* Print the actual response with the line numbering. */
    for (int i = 0; i < bytes; i++) {
        std::cout << buffer[i];
        if (buffer[i] == '\n')  {
            line_number++;
            std::cout << line_number << ": \t";
        }
    }
    std::cout << "\n\n";
    /* Return the data acquired in bytes. */
    return bytes;
}

/* PRIVATE: Function to write to a file when downloading it. */
size_t request::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream); /* Write the actual data */
    return written; /* Return the response of the fwrite() function */
}

size_t request::print_nothing(char * buffer, size_t itemsize, size_t number_items, void* ignore) {
    size_t bytes = itemsize * number_items;
    return bytes;
}
/* ===================================================================================================================================== */
/* FUNCTIONS SECTION ENDS */