#include <iostream>
#include <thread>
#include <SugarHTTPS_RestClient.hpp>
#include <mutex>

//get(std::string url, int threadNumber, int Timeout, bool FollowRedicts, int RedictsNumber, std::string userAgent);

std::mutex m;
bool running = true;

auto MakeRequest = []() {
    for(int i = 0; i < 10; ++i) {
        auto r = sugar::get("http://91.232.174.39/hit");
        std::cout << r.body;
    }
};

int main() {

    std::thread threadOne(MakeRequest);
    std::thread threadTwo(MakeRequest);
    
    threadOne.join();
    threadTwo.join();
    return 0;
}