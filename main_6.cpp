/*
 * deadlock
 */

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int A = 10;
int B = 20;

mutex Mutex1;
mutex Mutex2;

void fun1(){
    // 1 破坏互斥
//    int A1 = A;
//    int B1 = B;
    unique_lock<std::mutex> lock1(Mutex1);
    ++A;
    cout << "get A" << A << endl;
    // 2 破坏请求保持
//    lock1.unlock();
    // 3 破坏不可剥削
//    int t    ;
//    while(t > -1){
//        t--;
//        if(t < 0){
//            return;
//        }
//    }
    unique_lock<std::mutex> lock2(Mutex2);
    ++B;
    cout << "get B" << B << endl;
}

void fun2(){
    // 4 破坏循环等待 强制Mutex1 Mutex2
    unique_lock<std::mutex> lock1(Mutex2);
    ++B;
    cout << "get B" << B << endl;
    // lock1.unlock();
    unique_lock<std::mutex> lock2(Mutex1);
    ++A;
    cout << "get A" << A << endl;
}

int main(){
    thread th1(fun1);
    thread th2(fun2);
    th1.join();
    th2.join();
    return 0;
}
