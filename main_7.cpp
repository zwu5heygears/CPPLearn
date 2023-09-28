/*
 * data structure
 */
#include <boost/format.hpp>
#include <iostream>

using namespace std;
class A{
public:
    virtual void funA1(){cout << __func__ << endl;}
    void funA2(){cout << __func__ << endl;}
};

class B:public A{
public:
    virtual void funA1(){cout << 3 << __func__ << endl;}
    void funB1(){cout << __func__ << endl;}
    void funA2(){cout << "2" << __func__ << endl;}
};


int main(){
    /// 1.list

    /// 2.Stack

    /// 3.Queue
    A* ptr = nullptr;
    ptr->funA2();
    /// 4.String

    /// 5.Tree
    class binaryTree{
    public:


    };
    /// 6.Map
    int a = 1;
    int b = 2;
    cout << boost::str(boost::format("hello%d, %d") %a%b) << endl;

    return 0;
}