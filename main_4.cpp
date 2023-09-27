/*
 * condition_variable
*/
#include <condition_variable>
#include <thread>
#include <mutex>
#include <deque>
#include <iostream>
using namespace std;

mutex Mutex;
condition_variable conditionVariable;
deque<int> dataDeque;

const int MAX = 30;
const int PRODUCER_THREAD_NUM = 3;
const int CUSTOMER_THREAD_NUM = 5;
int index = 0;

void producer_thread(int threadid)
{
    while(true)
    {
        this_thread::sleep_for(std::chrono::milliseconds(500));  // 间隔500ms判断，减少判断消耗资源
        std::unique_lock<std::mutex> lock(Mutex);
        // condition_variable 一定搭配mutex使用，应为判断条件是临界资源(保证全局条件和wait是原则操作)
        if(dataDeque.size() <= MAX)
        {
            index++;
            dataDeque.push_back(index);  // 任务为全局变量
            cout << "produce thread id" << threadid << " " << index << endl;
            cout << "dataDeque size" << dataDeque.size() << endl;
        }
        else
        {
            conditionVariable.notify_all();
            conditionVariable.notify_one(); // 随机唤醒一个休眠的线程
        }
    }
}

void customer_thread(int threadid){
    while(true){
        this_thread::sleep_for(std::chrono::milliseconds(500));
        std::unique_lock<std::mutex> lock(Mutex);
        if(!dataDeque.empty()){
            int data = dataDeque.front();
            dataDeque.pop_front();
            cout << "customer thread id" << threadid << endl;
            cout << "data:" << data << "dataDeque size" << dataDeque.size() << endl;
        }
        else{
            // wait(lock)
//            conditionVariable.wait(lock);

            // wait(lock, condition)
            // 增加第二个参数，判断条件是否唤醒，解决虚假虚假唤醒(notify_all 通知了但没有产品)
//            conditionVariable.wait(lock, []()->bool{return !dataDeque.empty();});

            // wait_for() 阻塞时长超过后返回
//            conditionVariable.wait_for(lock, std::chrono::milliseconds(1000));

            // wait_until() 阻塞超过指定时间点
            conditionVariable.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(100));

        }
    }
}

int main(){
    thread *proThread[PRODUCER_THREAD_NUM];
    thread *cusThread[CUSTOMER_THREAD_NUM];

    for(int i = 0; i < PRODUCER_THREAD_NUM; ++i){
        proThread[i] = new thread(producer_thread, ref(i));
    }

    for(int j = 0; j < CUSTOMER_THREAD_NUM; ++j){
        cusThread[j] = new thread(customer_thread, ref(j));
    }

    // join()
    for(int i = 0; i < PRODUCER_THREAD_NUM; ++i){
        proThread[i]->join();
    }
    for(int j = 0; j < CUSTOMER_THREAD_NUM; ++j){
        cusThread[j]->join();
    }

}
