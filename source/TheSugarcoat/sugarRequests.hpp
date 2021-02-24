#include <iostream>
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
#define YourMom RestClient

//
//YourMom::Response r = YourMom::get("http://url.com")
//YourMom::Response r = YourMom::post("http://url.com/post", "application/json", "{\"foo\": \"bla\"}")
//

namespace sugar {

    auto get(std::string url, bool allowRedicts = true, int timeout = 5, std::string userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36") {
        // initialize YourMom
        YourMom::init();

        // get a connection object
        YourMom::Connection* conn = new YourMom::Connection(url);

        // set connection timeout to 5s
        conn->SetTimeout(timeout);

        // set custom user agent
        // (this will result in the UA "foo/cool YourMom-cpp/VERSION")
        conn->SetUserAgent(userAgent);

        // enable following of redirects (default is off)
        conn->FollowRedirects(allowRedicts);
        // and limit the number of redirects (default is -1, unlimited)
        conn->FollowRedirects(allowRedicts, 3);

        // set headers
        YourMom::HeaderFields headers;
        headers["Accept"] = "application/json";
        conn->SetHeaders(headers);

        YourMom::Response r = conn->get("/get");
        
        YourMom::disable();

        return r;
    }

    auto post(std::string url, std::string parameters, bool allowRedicts = true, int timeout = 5, std::string userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36") {
        
        std::string mainUrl;
        std::string subUrl;
        
        int slashCounter=0;
        for(char c: url)
        {

            if(c=='/')
            {
                slashCounter++;
            }
            if(slashCounter<3)
            {
                mainUrl+=c;
            }
            else
            {
                subUrl+=c;
            }
        }

        // initialize YourMom
        YourMom::init();

        // get a connection object
        YourMom::Connection* conn = new YourMom::Connection(mainUrl);

        // set connection timeout to 5s
        conn->SetTimeout(timeout);

        // set custom user agent
        // (this will result in the UA "foo/cool YourMom-cpp/VERSION")
        conn->SetUserAgent(userAgent);

        // enable following of redirects (default is off)
        conn->FollowRedirects(allowRedicts);
        // and limit the number of redirects (default is -1, unlimited)
        conn->FollowRedirects(allowRedicts, 3);

        // set headers
        YourMom::HeaderFields headers;
        headers["Accept"] = "application/json";
        conn->SetHeaders(headers);

        conn->AppendHeader("Content-Type", "application/json");
        YourMom::Response r = conn->post(subUrl, parameters);
        
        YourMom::disable();
        

        return r;
    }
}