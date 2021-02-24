#include <iostream>
#include "sugarRequests.hpp"
#include <pthread.h>

//"{\"foo\": \"bla\"}" JSON FORMAT

int main() {
    auto z = sugar::post("https://reimann-api.herokuapp.com/api/", "{\"username\": \"lolol\", \"password\":\"hdfkjd\", \"email\": \"hello@hello.com\"}");
    std::cout << z.body << "\n";
}