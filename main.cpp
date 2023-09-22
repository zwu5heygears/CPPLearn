#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
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

    /// 数据类型
    cout << sizeof(a) << endl;
    cout << sizeof(short) << sizeof(int) << sizeof(long) <<sizeof(long long) << endl;
    cout << sizeof(ushort) << sizeof(uint) << sizeof(ulong) << sizeof(unsigned long long) << endl;
    cout << sizeof(wchar_t) << sizeof(char) << sizeof(char16_t) << sizeof(char32_t) << endl;
    cout << INT32_MAX << ":" << UINT32_MAX << endl;


    cout << sizeof(float) << sizeof(double) << endl; // 7位有效数字  15-16位有效数字
    float f1 = 3.141592657f;
    double d1 = 3.141592657;
    cout << d1 << endl;  // 默认输出5位小数
    cout << f1 << endl;

    float f2 = 3e-3;
    cout << f2 <<endl;

    char ch = 'a';  // 存储对应的ASCII编码
//    char ch2 = "b";  // ""内包含\0
    cout << ch << int(ch) << endl;
    cout << sizeof(char) << sizeof(u_char) << sizeof(char16_t ) << sizeof(char32_t) << endl;

    // \t \f \n \b \a
    cout << "hello" << "\b 22" << "\t \\33" << endl;

    char str[] = "hello";
    cout << str << endl;
    string str1 = "hello";
    cout << str1 << endl;

    bool b1 = true; // 1 非0为true
    cout << b1 << endl;
    cout << sizeof(bool) << endl;

    /// 数据输入
//    char cina;
//    cin >> cina;
//    cout << cina << int(cina) << endl;


    /// 运算符
    int m = 100;
    m = m + 10;
    m = m - 10;
    m = -10 + m;
    m = m / 10;
    m = m % 10;
    m++;
    m--;
    ++m;
    --m;
    m += 20;
    m -= 20;
    m *= 20;
    m /= 20;
    m %= 10;
    cout << m << endl;
    cout <<  isnan(0.0/ 0.0) << endl;
//    isnan(0 / 0)  // 程序停止运行
//    cout << 2.0f % 3.0f  <<endl;
    int m2 = 10, m3 = 11;
    cout << (m2 == m3) << (m2 < m3)  << (m2 > m3) << (m2 <= m3) << (m2 > m3) << endl;
    cout << (m2 & m3) << (m2 | m3) << (~m3) << (m2 << 2) << (m3 >> 2) << endl;
    cout << !m2 << (!m2 && !m3) << (!m2 || m3) << endl;

    /// 流程结构
    int m4 = 54;
    if(m4 > 0){
        cout << 1;
    }
    else if(m4 < 0){
        cout << 20;
    }
    else{
        cout << 0;
    }
    int m5 =  m2 > m3 ? 20 : 30;
    cout << m5 << endl;

    int m6 = 20;
    switch (m6) {
        case 20:
        {
            cout << "good";
        }
        break;

        case 30:
        {
            cout << "perfect";
        }
        break;
        default:
            break;
    }



    return 0;
}
