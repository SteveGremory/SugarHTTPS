#include "SugarHTTPS.h"

namespace SugarHTTPS
{
    Request::Request() : Url(nullptr),
                         Data(nullptr),
                         Headers(std::vector<const char*>()),
                         List(nullptr),
                         File(nullptr),
                         Status(RequestStatus::Unknown),
                         ResponseCode(0)
    {
        this->Handle = curl_easy_init();
    }

    Request::Request(Request& request) : Url(request.Url),
                                         Data(request.Data),
                                         Headers(request.Headers),
                                         List(request.List),
                                         Handle(request.Handle),
                                         File(request.File),
                                         Status(request.Status),
                                         ResponseCode(request.ResponseCode)
    {
    }

    Request::~Request()
    {
        /* Cleanup */
        if (this->List)
        {
            curl_slist_free_all(this->List);

            this->List = nullptr;
        }

        if (this->File)
        {
            fclose(File);

            this->File = nullptr;
        }

        // if (this->Handle != nullptr)
        // {
            // curl_easy_cleanup(this->Handle);

            this->Handle = nullptr;
        // }
    }

    /* REQUESTS SECTION */
    /* ===================================================================================================================================== */

    /* POST REQUEST */
    Request& Request::Post()
    {
        /* Set Headers */
        for (int i = 0; i < this->Headers.size(); i++)
           this->List = curl_slist_append(this->List, this->Headers.at(i));

        /* Add the URL */
        curl_easy_setopt(this->Handle, CURLOPT_URL, this->Url);

        /* Print nothing to the terminal by default */
        curl_easy_setopt(this->Handle, CURLOPT_WRITEFUNCTION, this->PrintNothing);

        /* Headers */
        curl_easy_setopt(this->Handle, CURLOPT_HTTPHEADER, this->List); /* Add Headers */
        curl_easy_setopt(this->Handle, CURLOPT_FOLLOWLOCATION, 1L); /* Enable redirects */

        /* Data */
        curl_easy_setopt(this->Handle, CURLOPT_POSTFIELDS, this->Data); /* Add the data */
        curl_easy_setopt(this->Handle, CURLOPT_POSTFIELDSIZE, -1L); /* Set the post field's size */

        /* end, return *this for chaining + */
        return *this;
    }

    /* DOWNLOAD REQUEST */
    Request& Request::Download(std::string outfilename)
    {
        /* Open the file to write the bytes to */
        File = fopen(outfilename.c_str(), "wb");
        /* Set opts */
        curl_easy_setopt(this->Handle, CURLOPT_URL, this->Url);
        curl_easy_setopt(this->Handle, CURLOPT_FOLLOWLOCATION, 1L);
        /* Tell libcURL about the writing functions */
        curl_easy_setopt(this->Handle, CURLOPT_WRITEFUNCTION, this->WriteData);
        curl_easy_setopt(this->Handle, CURLOPT_WRITEDATA, File);
        /* end, return *this for chaining */
        return *this;
    }

    /* GET REQUEST */
    Request& Request::Get()
    {
        /* Set URL and such */
        curl_easy_setopt(this->Handle, CURLOPT_URL, this->Url);

        /* Enable redirects */
        curl_easy_setopt(this->Handle, CURLOPT_FOLLOWLOCATION, 1L);

        /* Print nothing by default */
        curl_easy_setopt(this->Handle, CURLOPT_WRITEFUNCTION, this->PrintNothing);

        /* End, return your bitch */
        return *this;
    }

    /* ===================================================================================================================================== */
    /* REQUEST SECION ENDS */

    /* FUNCTIONS SECTION */
    /* ===================================================================================================================================== */

    /* PUBLIC: Function to be added at the end of every Request, this is the part where your Request is actually executed. */
    Request& Request::MakeRequest()
    {
        /* Remove comment if you want it to be verbose */
        curl_easy_setopt(this->Handle, CURLOPT_VERBOSE, 1L);

        /* Store response in a variable. */
        CURLcode response = curl_easy_perform(this->Handle);

        /* Check if Request was successful */
        if (response == CURLE_OK) {
            /* Get the response code. */
            long response_code;
            curl_easy_getinfo(this->Handle, CURLINFO_RESPONSE_CODE, &response_code);
            response_code = response;
            /* Print the response code */
            std::cout << "\nRequest Succeded! Response Code: " << response_code << '\n';
            /* end. */
            this->Status = RequestStatus::Success;
            return *this;
        } else if (response != CURLE_OK) {
            /* If the Request fucked up, Just print why it fucked up */
            std::cout << "Request Failed: " << curl_easy_strerror(response) << '\n';
            /* end. */
            this->Status = RequestStatus::Failure;
            return *this;
        }
    }

    /* PUBLIC: Function To Print The HTTP response text to the terminal. */
    Request& Request::Text()
    {
        /* Letting libcURL know what to do with the acquired data */
        curl_easy_setopt(this->Handle, CURLOPT_WRITEFUNCTION, this->PrintToTerminal);
        return *this;
    }

    /* Sets the Request URL to the provided one.  */
    Request& Request::SetUrl(char* url)
    {
        this->Url = url;

        return *this;
    }

    /* Clears the Handle object of the previous request. */
    Request& Request::Flush()
    {
        if (!this->Handle)
            return *this;

        curl_easy_cleanup(this->Handle);

        return *this;
    }

    /* Returns the status of execution of the current request. */
    RequestStatus Request::GetStatus()
    {
        return this->Status;
    }


    /* PRIVATE: Function to print the response to the terminal, Has to be a function because libcurl demands so. */
    size_t Request::PrintToTerminal(char* buffer, size_t itemsize, size_t number_items, void* ignore)
    {
        /* Get the size of the response in bytes */
        size_t bytes = itemsize * number_items;
        /* Print the number of lines with the response. */
        int line_number = 1;
        std::cout << "Chunk Size: " << bytes << "\n";
        std::cout << line_number << ": \t";
        /* Print the actual response with the line numbering. */
        for (int i = 0; i < bytes; i++)
        {
            std::cout << buffer[i];

            if (buffer[i] == '\n')
                std::cout << line_number++ << ": \t";
        }
        std::cout << "\n\n";
        /* Return the data acquired in bytes. */
        return bytes;
    }

    /* PRIVATE: Function to write to a file when downloading it. */
    size_t Request::WriteData(void* ptr, size_t size, size_t nmemb, FILE* stream)
    {
        return fwrite(ptr, size, nmemb, stream); /* Write the actual data */
    }

    size_t Request::PrintNothing(char* buffer, size_t itemsize, size_t number_items, void* ignore)
    {
        return (itemsize * number_items);
    }
    /* ===================================================================================================================================== */
    /* FUNCTIONS SECTION ENDS */

}
