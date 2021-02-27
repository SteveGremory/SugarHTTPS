#include <iostream>
#include "restclient-cpp/restclient.h"

//
//RestClient::Response r = RestClient::get("http://url.com")
//RestClient::Response r = RestClient::post("http://url.com/post", "application/json", "{\"foo\": \"bla\"}")
//

namespace sugar {
    
    RestClient::Response get(std::string url, bool allowRedicts = true, int redictsCount = 3, int timeout = 5, std::string userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36");

    RestClient::Response post(std::string url, std::string parameteres,  bool allowRedicts = true, int redictsCount = 3, int timeout = 5, std::string userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36");
    
}