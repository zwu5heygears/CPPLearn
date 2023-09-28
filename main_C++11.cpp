#include <iostream>
#include <atomic>
#include <thread>
#include <future>
using namespace std;

void fun(std::promise<int> &p1){
    p1.set_value(20);
    cout << __func__ << "is end" << endl;
}
void fun2(std::future<int> f2){
    int x = f2.get();
    cout << "f2:" << x << endl;
}
void fun3(std::shared_ptr<std::promise<int>> promisePtr){
    promisePtr->set_value(120);
}
int main(){
//    atomic_int a = 1; // 错误初始化
    atomic<int> a(1);  // 准确
    cout << std::boolalpha << a.is_lock_free() << endl;
    a.store(2);
    int b = a.exchange(20);
    int c = 20;
    int d = 101;
    atomic_compare_exchange_strong(&a, &c, d);
//    atomic_compare_exchange_weak()
    cout << b << " " << a.load() << " " << d << endl;
    cout << a.load() << endl;
    a.fetch_add(20);
    cout << a.load() << endl;

    std::promise<int> p1;
    std::future<int> f1 = p1.get_future();
    thread th1(fun, ref(p1)); // 父线程获取子线程的值
//    f1.wait();
    cout << "f1:" << f1.get() << endl;
    th1.join();  // 创建线程后要告知join/detach

    // 由于promise及future不可复制，需要通过&传递或初始化为智能指针再直接传递
    std::shared_ptr<std::promise<int>> promisePtr;
    promisePtr.reset(new std::promise<int>);
    thread th3(fun3, promisePtr);
    cout << "fun3:" << promisePtr->get_future().get() << endl;
    th3.join();


    std::promise<int> p2;
    std::future<int> f2 = p2.get_future(); // 关联
    thread th2(fun2, std::move(f2));  // 子线程获取父线程的值
    p2.set_value(20);
    th2.join();
    std::promise<int> pp1;
//    std::promise<int> pp2(pp1);  // 除了move，promise 和 future 不允许拷贝
//    std::promise<int> pp3 = pp1;
    std::promise<int> pp4 = std::move(pp1);
    std::future<int> ff1 = pp4.get_future();
//    std::future<int> ff2 = ff1;
//    std::future<int> ff3(ff1);
    std::future<int> ff4 = std::move(ff1);


    return 0;

}