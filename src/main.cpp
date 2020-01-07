/*
    Test basic CPP threading with mutexes
    https://en.cppreference.com/w/cpp/thread/mutex
*/

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex _mutex;
int shared_val = 99;

void set_100() {
        int count = 50;
        while(count--) {
            std::unique_lock<std::mutex> writeLock(_mutex);
            shared_val = 100;
            sleep(0.5);
        }
}

void set_50() {
        int count = 150;

        while(count--) {
            std::unique_lock<std::mutex> writeLock(_mutex);
            shared_val = 50;
            sleep(0.5);
        }
}

int main() {
    std::cout << "Testing thread sync primitives" << std::endl;
    std::thread t1(set_100);
    std::thread t2(set_50);

    // std::cin.get();

    t1.join();
    t2.join();

    std::cout << "Value of shared val: " << shared_val << std::endl;

    return 0;
}
