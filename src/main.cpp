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

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";

    std::stringstream ss;
    ss << result << ": " << std::this_thread::get_id();
    
    std::lock_guard<std::mutex> guard(g_pages_mutex);
    g_pages[url] = ss.str();
}

int main() {
    std::cout << "Testing thread sync primitives" << std::endl;

    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();
 
    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}