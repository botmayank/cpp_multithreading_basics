#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <vector>

std::mutex _mutex;
int shared_val = 0;
int max_count = 100;

#define USE_MUTEX  // comment to get incorrect value

void increment_val() {
#ifdef USE_MUTEX
        std::unique_lock<std::mutex> writeLock(_mutex);
#endif
    for(int i=0; i < max_count; i++){
        sleep(0.5);        
        shared_val++;
    }
}

void increment_val_try() {
    bool check = false;
#ifdef USE_MUTEX
    std::unique_lock<std::mutex> writeLock(_mutex, std::defer_lock);
    check = writeLock.try_lock();
#endif
    if(check){
        for(int i=0; i < max_count; i++){
            sleep(0.5);        
            shared_val++;
        }
    }
}

void run_mutex_test() {
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
}
