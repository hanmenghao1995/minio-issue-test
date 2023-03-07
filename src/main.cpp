#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <sys/time.h>

using namespace std;

void fun(int threadNum) {
    timeval tv_ = {0, 0};
    gettimeofday(&tv_, NULL);
    auto localTimePtr = std::localtime(&tv_.tv_sec);
    auto gmTimePtr = std::gmtime(&tv_.tv_sec);
    cout << "thread is " << threadNum << " localTimePtr is : " << localTimePtr << " gmTimePtr is " << gmTimePtr << endl;
}

int main()
{
    thread t1(fun, 1);
    t1.join();
    thread t2(fun, 2);
    t2.join();
    return 0;
}