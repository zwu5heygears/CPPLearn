#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
// hello
/* hello */
#define MAX 200
using namespace std;  // const
const int MAX2 = 300;

int main() {
    int v2_; // letter number _ (case)
    int a = 0;  // variable use for manage memory
    cout << a << endl;
    a = 1;
    cout << a << endl;
    double b = static_cast<double>(a);

    // 数据类型
    cout << sizeof(a) << endl;
    cout << sizeof(short) << sizeof(int) << sizeof(long) <<sizeof(long long) << endl;
    cout << sizeof(ushort) << sizeof(uint) << sizeof(ulong) << sizeof(unsigned long long) << endl;
    cout << sizeof(wchar_t) << sizeof(char) << sizeof(char16_t) << sizeof(char32_t) << endl;

    cout << sizeof(float) << sizeof(double) << endl; // 7位有效数字  15-16位有效数字
    float f1 = 3.141592657f;
    double d1 = 3.141592657;
    cout << d1 << endl;  // 默认输出5位小数
    cout << f1 << endl;

    float f2 = 3e-3;
    cout <<f2 <<endl;
    cout << "Hello heygears" << endl;

    return 0;
}
