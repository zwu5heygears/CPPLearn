#include <iostream>
#include <mutex> // 互斥量
#include <shared_mutex>
#include <thread>
#include <condition_variable>
#include "boost/asio/thread_pool.hpp"
#include <semaphore.h>
using namespace std;

void fun1(int x){ // 函数形参不带&，直接传递
    cout << "x:" << x << endl;
}
void fun3(int &x){  // ref(x)
    int y = x;
    cout << "y" << y << endl;
}
void fun2(int x){
    while (x > 0){
        x--;
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "x:" << x << endl;
    }
}


// mutex
std::mutex Mutex;
std::timed_mutex timedMutex;
std::recursive_mutex recursiveMutex;  // 可递归
std::recursive_timed_mutex recursiveTimedMutex;
std::shared_mutex sharedMutex;

volatile int counter = 0;
void increase10K(){
    for(int i = 0; i < 10000; i++){
        if(Mutex.try_lock())
        {
            ++counter;
            Mutex.unlock();
        }
//        Mutex.lock();
//        ++counter;
//        Mutex.unlock();
    }
}

void print_event(int x){
    if(x % 2 == 0){
        cout << x << "is even\n";
    }
    else{
        throw(std::logic_error("not even"));
    }
}

void print_thread_id(int id){
    try{
        std::unique_lock<mutex> locker(mutex);
        print_event(id);

    }
    catch(std::logic_error&) {
       cout << "[exception caught]\n";
    }
}
void funtest(){
    cout << 1 << endl;
}
class Complex{
public:
//    std::mutex Mutex1;
    std::recursive_mutex Mutex1;
    int i;
    Complex() : i(0){};
    void mul(int x){
//        lock_guard<std::mutex> lock(Mutex1);
        lock_guard<std::recursive_mutex> lock(Mutex1);
        i *= x;
    }
    void div(int x){
//        lock_guard<std::mutex> lock(Mutex1);
        lock_guard<std::recursive_mutex> lock(Mutex1);
        i /= x;
    }
    void both(int x, int y){
//        lock_guard<std::mutex> lock(Mutex1); // 重复获取自身已获取的锁，造成死锁
        lock_guard<std::recursive_mutex> lock(Mutex1);
        mul(x);
        div(x);
    }
};

void work(){
    std::chrono::milliseconds timeout(100);
    while(true){
        if(timedMutex.try_lock_for(timeout)){
            cout << this_thread::get_id << "go work with mutex" << endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            timedMutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
        else{
            cout << this_thread::get_id() << "do work without mutex" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}
int main(){
    // thread
    thread t1(fun1, 2);  // 线程的栈自身拥有，不会修改传入的参数
    int r = 10;
    thread t2(fun3, std::ref(r));

    if(t1.joinable()){
        t1.join();
    }
    if(t2.joinable()){
        t2.detach();
    }


    // lock() unlock() try_lock()
    std::thread therads[10];
    for(int i = 0; i < 10; i++){
        therads[i] = std::thread(increase10K);
    }
    for(auto &th : therads){
        th.join();
    }
    cout << "end" << counter << endl;

    // RAII lock_guard() unique_lock()
    std::thread therads2[10];
    for(int i = 0; i < 10; i++){
        therads2[i] = std::thread(print_thread_id, i + 1);
    }
    for(auto &th : therads2){
        th.join();
    }

    // 递归锁 允许同一线程多次获取同一互斥量，避免死锁
    Complex complex;
    complex.both(20, 30);

    // timed_mutex try_lock_for() try_lock_until()
//    thread ths1(work);
//    thread ths2(work);
//    ths1.join();
//    ths2.join();
//
    boost::asio::thread_pool pool(5);


    thread testjoin(funtest);

    return 0;
}