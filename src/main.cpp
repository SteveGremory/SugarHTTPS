#include "main.hpp"

int main() {

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

    auto r = request {
        .url = "https://google.com",
        .method = "GET"
    };
    r.printValues();

}
