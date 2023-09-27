/*
 * semaphore
 */

#include <semaphore.h>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>
using namespace std;

// sem_t counting_semaphore 非负计数 binary_semaphore 二值计数 C++20
sem_t sem;

mutex Mutex;
condition_variable cvar;

void fun1(void *param){
    cout << __func__ << ": wait..." << endl;
    sem_wait(&sem);

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    ts.tv_sec += 5;
    sem_timedwait(&sem, &ts);
//    unique_lock<std::mutex> lock(Mutex);
//    cvar.wait(lock);
    int *running = (int*) param;
    cout << "fun1 running:" << *running << endl;
}

void fun2(int time){
    cout << __func__ << " " << time << endl;
    sem_post(&sem);
    int semVal;
    sem_getvalue(&sem, &semVal);
    cout << "semVal:" << semVal << endl;
//    cvar.notify_one();  // 1.条件变量不能通知指定线程 2.更麻烦需要现lock
}


int main(){
    sem_init(&sem, 0, 0);
    int time = 5;
    thread th1(fun1, &time);
    thread th2(fun2, time);
    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();
    sem_destroy(&sem);
    return 0;
}


