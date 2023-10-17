#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <pthread.h>


#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include "worker.hh"

std::mutex iomutex;
pthread_key_t thread_key;

std::string print(const std::vector<int>& v)
{
    std::string  retval = std::string("[") + std::to_string(v.size()) + std::string("] { ");
    for (auto const& e : v)
        retval +=  std::to_string(e) + ' ';
    retval +=  "}\n";
    return retval;
}

void printThreadInfo(int num, pthread_t thread, const std::vector<int>& data) {
    std::lock_guard<std::mutex> lk(iomutex);
    std::cout << "Thread " << num << " has pthread ID " << thread << '\n';
    std::cout << "Thread-specific key is: " << pthread_getspecific(thread_key) << '\n';
    std::cout << "Thread-specific data untouchd is: " << print(data) << '\n';
    std::cout << "Thread-specific data (sorted) is: " << print(demo_work::do_work(data)) << '\n';
}

void f(int num, int vec_size) {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto gen = std::mt19937{std::random_device{}()};
    std::uniform_int_distribution<int> dist(-10, 10); // Replace min_value and max_value with your bounds
    std::vector<int> hmm(vec_size, 0);
    std::generate(hmm.begin(), hmm.end(), [&]() { return dist(gen); });

    pthread_t this_thread = pthread_self();

    // Set thread-specific data
    pthread_setspecific(thread_key, (void*) &num);

    printThreadInfo(num, this_thread, hmm);
}

int main() {

    // create a generator for random vector creation
    // Create a key for thread-specific data
    pthread_key_create(&thread_key, nullptr);

    std::thread t1(f, 1, 25), t2(f, 2, 3);

    // Print main thread info
    printThreadInfo(0, pthread_self(), {3,1,4,1,5,9});

    t1.join();
    t2.join();

    // Delete the key for thread-specific data
    pthread_key_delete(thread_key);

    return 0;
}
