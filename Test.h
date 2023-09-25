//
// Created by heygears on 23-9-25.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_TEST_H
#include "Cube.h"
#include <iostream>

class Test {
    friend class Cube; // 友元类
    friend void friendFun(Test *test); // 全局友元函数
    // 成语函数友元
public:
    Test(int height, int width);
    Test(int a, int b, int c);
    ~Test();

    Test(const Test &test);
    static void printAll();  // 静态函数只能访问静态成员
    const static int s_m = 20;  // 静态成员 全部类共享 内存共享 类外初始化
    Test& TestAddHeight(Test test);
    void printHello();

    void setMember() const; // 常函数 不可修改成员属性(除非mutable)
    void printABC();
    Test operator+(Test & test);
    void operator<<(Test &test);
    void setWH(int w, int h);

    int *mW;
private:
    int *mH;
    mutable float f1;
    int ma = 10;
    int mb;
    int mc;
    int a;
    Cube c1;


};


#endif //UNTITLED_TEST_H
