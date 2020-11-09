#include <iostream>
#include <chrono>
#include <future>

long sumArray(int *a, size_t s) {
    long sum = 0;
    for (size_t i = 0; i < s; i++) sum+=*(a+i);    
    return sum;    
}

long fibonacci(unsigned n) {
    return 0;
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
 
int main()
{/*
    auto start = std::chrono::steady_clock::now();

    auto a = std::async(std::launch::async, fibonacci, 43);
    auto b = fibonacci(42);    
    std::cout << "f(44) = " << a.get() + b << '\n';



    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    auto start2 = std::chrono::steady_clock::now();    
    b = fibonacci(44);    
    std::cout << "f(44) = " << b << '\n';
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2-start2;
    std::cout << "elapsed time: " << elapsed_seconds2.count() << "s\n";


    return 0;*/
    size_t s = 50000;
    int *aa = new int[s];
    for (size_t i = 0; i < s; i++) aa[i] = std::rand();

    auto start3 = std::chrono::steady_clock::now();

    auto c = std::async(std::launch::async, sumArray, aa,s/2);
    
    auto b = sumArray(aa+s/2,s/2);

    std::cout << "Sum = " << b+c.get() << '\n';
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3-start3;
    std::cout << "elapsed time: " << elapsed_seconds3.count() << "s\n";

    auto start4 = std::chrono::steady_clock::now();    

    b = sumArray(aa,s);
    std::cout << "Sum = " << b << '\n';


    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = end4-start4;
    std::cout << "elapsed time: " << elapsed_seconds4.count() << "s\n";

    delete [] aa;
}



