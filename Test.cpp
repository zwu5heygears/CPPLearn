//
// Created by heygears on 23-9-25.
//

#include "Test.h"

using namespace std;
Test::~Test() {  // 如果使用默认的拷贝构造函数(浅拷贝) 会造成多次释放内存的bug
    if(mH != nullptr){
        delete mH;
    }
    if(mW != nullptr){
        delete mW;
    }
    cout << "析构Test" << endl;
}

Test::Test(int height, int width) {
    cout << "构造Test" << endl;

    mH = new int(height);
    mW = new int (width);
}

Test::Test(const Test &test) {
    mH = new int (*test.mH);
    mW = new int (*test.mW);
//    mW = test.mW; // 编译器的默认实现(浅拷贝)
}

Test::Test(int a, int b, int c): ma(a), mb(b), mc(c){  // 初始化列表
    this->a = a;
}

void Test::printAll() {
    cout << s_m << endl;
}

Test& Test::TestAddHeight(Test test) {
    *(this->mW) += *(test.mW);

    return *this;
}

void Test::printHello() {
    if(this == nullptr){
        cout << "hello" << "this is nullptr" << endl;
        return;
    }
    cout << "hello" << this->ma << endl;
}

void Test::setMember() const {
//    *mW = 20;
    f1 = 200;
    cout << f1 << endl;
}

void friendFun(Test *test) {
    cout << test->ma << test->mb << test->mc << endl;
}

//void Test::getCubePrivate() {
//    cout << c1.m_h << endl; // 访问友元的私有
//}
