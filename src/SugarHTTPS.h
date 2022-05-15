#pragma once
#include <cstring>
#include <curl/curl.h>
#include <iostream>
#include <vector>

namespace SugarHTTPS
{
        class Request
        {
        public:
            const char* Url;

            std::vector<const char*> Headers;

            const char* Data;

            int Success = 0;

            long ResponseCode = 0;

            CURL* Handle;

            curl_slist* List;

            FILE* fp;

            Request& Post();

            Request& Download(std::string outfilename);

            Request& Get();

            Request& MakeRequest();

            Request& Text();

            Request();
            ~Request();

        private:
            static size_t WriteData(void* ptr, size_t size, size_t nmemb, FILE* stream);

            static size_t PrintToTerminal(char* buffer, size_t itemsize, size_t number_items, void* ignore);

            static size_t PrintNothing(char* buffer, size_t itemsize, size_t number_items, void* ignore);
        };
}
