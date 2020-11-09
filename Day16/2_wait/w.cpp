#include <iostream>
#include <future>
#include <thread>
#include <chrono>
 
int main()
{
    std::future<int> future = std::async(std::launch::async/*deferred*/, [](){ 
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 8;  
    }); 
 
    std::cout << "waiting...\n";
    std::future_status status;
/*
    std::chrono::system_clock::time_point one_seconds_passed
        = std::chrono::system_clock::now() + std::chrono::seconds(1);
  */
    std::cout << "result is " << future.get() << '\n';  
    do {
        //status = future.wait_until(one_seconds_passed);
        status = future.wait_for(std::chrono::seconds(1));       

        if (status == std::future_status::deferred) {
            std::cout << "deferred\n";
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout\n";
        } else if (status == std::future_status::ready) {
            std::cout << "ready!\n";
        }
    } while (status != std::future_status::ready); 
    future.
    
}