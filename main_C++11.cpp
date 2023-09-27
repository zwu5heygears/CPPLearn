#include <iostream>
#include <atomic>
using namespace std;

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

    return 0;

}