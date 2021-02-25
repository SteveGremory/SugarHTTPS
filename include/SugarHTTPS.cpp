#include "SugarHTTPS.hpp"
#include <iostream>
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
namespace sugar {
    RestClient::Response get(std::string url, bool allowRedicts, int redictsCount, int timeout, std::string userAgent) {
        // initialize RestClient
        RestClient::init();
        // get a connection object
        RestClient::Connection* conn = new RestClient::Connection(url);
        // set connection timeout to 5s
        conn->SetTimeout(timeout);
        // set custom user agent
        // (this will result in the UA "foo/cool RestClient-cpp/VERSION")
        conn->SetUserAgent(userAgent);
        // enable following of redirects (default is off)
        conn->FollowRedirects(allowRedicts);
        // and limit the number of redirects (default is -1, unlimited)
        conn->FollowRedirects(allowRedicts, redictsCount);
        // set headers
        RestClient::HeaderFields headers;
        headers["Accept"] = "application/json";
        conn->SetHeaders(headers);
        RestClient::Response r = conn->get("/get");
        
        RestClient::disable();
        return r;
    }

    RestClient::Response post(std::string url, std::string parameters, bool allowRedicts, int redictsCount, int timeout, std::string userAgent) {
        
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
        // initialize RestClient
        RestClient::init();
        // get a connection object
        RestClient::Connection* conn = new RestClient::Connection(mainUrl);
        // set connection timeout to 5s
        conn->SetTimeout(timeout);
        // set custom user agent
        // (this will result in the UA "foo/cool RestClient-cpp/VERSION")
        conn->SetUserAgent(userAgent);
        // enable following of redirects (default is off)
        conn->FollowRedirects(allowRedicts);
        // and limit the number of redirects (default is -1, unlimited)
        conn->FollowRedirects(allowRedicts, redictsCount);
        // set headers
        RestClient::HeaderFields headers;
        headers["Accept"] = "application/json";
        conn->SetHeaders(headers);
        conn->AppendHeader("Content-Type", "application/json");
        RestClient::Response r = conn->post(subUrl, parameters);
        
        RestClient::disable();
        
        return r;
    }
}