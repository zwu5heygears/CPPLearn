#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "ThreadPool.h"

using namespace std;
void thread_1(){
    cout << this_thread::get_id() << endl;
    int y = 200;
    while(y > 0){
        cout << "y:" << y << endl;
        y--;
    }
}

void thread_2(int x){
    while(x > 0)
    {
        cout << "x:" << x << endl;
        x--;
//        this_thread::sleep_for(std::chrono::seconds(1));
        if(x < 50){
            this_thread::yield();
        }
    }
}

std::mutex mtx;
std::mutex mtx2;
void print_block(int n, char c){
    mtx.lock();
    for(int i = 0; i < n; ++i){
        cout << 1 <<" ";
    }
    cout << '\n';
    mtx.unlock();
}

void print_block2(int n, char c){
    mtx2.lock();
    for(int i = 0; i < n; ++i){
        cout << 2 <<" ";
    }
    cout << '\n';
    mtx2.unlock();
}

std::mutex g_i_mutex;
int g_i = 0;
void safe_increment(){
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    cout << this_thread::get_id() << ":" << g_i << "\n";
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
    t1.join();
    t2.join();
    std::cout << "main:" << g_i << endl;
}

std::mutex watiMutx;
std::condition_variable cv;
int cargo = 0;

bool shipment_available(){
    return cargo != 0;
}

void consume(int n){
    for(int i = 0; i < n; ++i){
        std::unique_lock<std::mutex> lck(watiMutx);
        cv.wait(lck, shipment_available);
        cout << cargo << '\n';
        cargo = 0;
    }
}
void func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "worker thread ID" << std::this_thread::get_id() << std::endl;
}


int main_1(){
//    thread thread1(thread_1);
//    thread thread2(thread_2, 100);
//    thread2.join();
//    if(thread1.joinable()){
//        thread1.join();
//    }


//    thread th1(print_block, 10000, '*');
//    thread th2(print_block2, 10000, '&');
//    th1.join();
//    th2.join();
//    safe_increment();

      /// 出现阻塞问题
//    thread consumer_thread(consume, 10);
//
//    consumer_thread.join();
//    for(int i = 0; i < 10; ++i){
//        while (shipment_available()) std::this_thread::yield();
//        std::unique_lock<std::mutex> lck(mtx);
//        cargo = i + 1;
//        cv.notify_one();
//    }
//
//    cout << "main thread" << endl;

    cout << sizeof(size_t) << endl;

    ThreadPool pool(4);

    return 0;
}