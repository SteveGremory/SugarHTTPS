#include <string>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Multi.hpp>

#define MY_PORT 8080

int trySomething() {
    try {
        cURLpp::Cleanup myCleanup;

        cURLpp::Easy easyHandle;

        easyHandle.setOpt(new cURLpp::Options::Url("https://google.com"));
        

        std::cout << easyHandle << "\n";
    }
    catch( cURLpp::RuntimeError &e )
        {
        std::cout << e.what() << std::endl;
        }
    catch( cURLpp::LogicError &e )
        {
        std::cout << e.what() << std::endl;
        }
    return 0; 
}