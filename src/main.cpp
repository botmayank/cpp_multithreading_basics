/*
    Test basic CPP threading with mutexes
*/

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <vector>

std::mutex _mutex;
int shared_val = 0;
int max_count = 100;

void increment_val() {
    std::unique_lock<std::mutex> writeLock(_mutex); // comment to get incorrect value
        for(int i=0; i < max_count; i++){
            sleep(0.5);        
            shared_val++;
        }
}

void increment_val_try() {
    std::unique_lock<std::mutex> writeLock(_mutex, std::defer_lock);
    if(writeLock.try_lock()) {
        for(int i=0; i < max_count; i++){
            sleep(0.5);        
            shared_val++;
        }
    }
}

int main() {
    std::cout << "Testing thread sync primitives" << std::endl;
    std::vector<std::thread> threads;
    int num_threads = 2;
    for(int i = 0; i < num_threads; i++)
        threads.push_back(std::thread(increment_val));

    for(auto &t : threads) {
        t.join();
    }
    std::cout << "Expected value of shared_val: " << num_threads * max_count << std::endl;
    std::cout << "Value of shared val: " << shared_val << std::endl;

    return 0;
}
