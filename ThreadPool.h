//
// Created by heygears on 23-9-25.
//

#ifndef UNTITLED_THREADPOOL_H
#define UNTITLED_THREADPOOL_H

#include <vector>
#include <queue>
#include <memory>  // 内存
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>  // 函数对象
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);                          //构造函数
    template<class F, class... Args>             //类模板
    auto enqueue(F&& f, Args&&... args)->std::future<decltype(func(args...))>;//任务入队
    ~ThreadPool();                              //析构函数

private:
    std::vector< std::thread > workers;            //线程队列，每个元素为一个Thread对象
    std::queue< std::function<void()> > tasks;     //任务队列，每个元素为一个函数对象

    std::mutex queue_mutex;                        //互斥量
    std::condition_variable condition;             //条件变量
    bool stop;                                     //停止
};
#endif //UNTITLED_THREADPOOL_H
