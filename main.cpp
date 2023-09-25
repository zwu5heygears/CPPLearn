#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>

#include "Cube.h"
#include "Sort.h"
#include "Test.h"
#include "AddressBook.h"
// hello
/* hello */
#define MAX 200
using namespace std;  // const
const int MAX2 = 300;
int add2(int a = 10, int b = 10);
int add2(int a, int b, int c);
int add2(int &a, int &b, int &c); // &
int add(int a, int b)
{
    return a + b;
}
void swap(int * a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

struct Student
{
    string name;
    int age;
    float height;
};

struct Teacher{
    string name;
    int age;
    float height;
}teacher;

struct school{
    struct Tea{
        string name;
        int age;
    };
    struct Stu{
        string name;
        int age;
    };
    struct Mon{
        const string name;
        const int age;
    }mon;
};

struct TestStruce{
public:
    string name;
    int m_data;
private:
    int StructFun();
};

int TestStruce::StructFun() {
    return m_data;
}

void printAll(const Student &s);
void printAll(const Student *s);
int * fun();
//void * fun(); // 函数重载不能修改返回值
int * fun(int a);
int &fun1(const int &a);
int fun2(const int &a, int, float);
void fun3(Cube c);
void fun4(Cube &c);
Cube fun5();
void fun6();
int fun7(){return 10;}  // 函数的返回值可以不接受

int g_a = 10;
const int c_a = 10;

// 静态成员/函数 成员函数都不属于类的对象
class Person{
    int mA;
    const static int sA = 20;
    void fun(){};
    static void fun2(){};
};


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

    int m7= 20;
    while(m7 > 0){
        m7--;
        cout << m7 << " ";
    }
    do{
        m7++;
        cout << m7 << " ";
    }while(m7 < 0);

    int randnum = rand() % 100 +1;
    double randnum2 = (double)rand() / RAND_MAX * (100 - 10) + 10; // 随机数

    int v = 100;
    do{
        if((pow(v % 10, 3) + pow(v / 10 % 10, 3) + pow(v / 100, 3)) == double(v)){
            cout << v << " ";
        }
        v++;
    }while(v < 1000);

    for(int i = 0; i < 10; ++i){
        if(i > 2){
            cout << i << " ";
            continue;
        }
        if(i > 5) break;
    }

    /// 数组 (相同类型 连续内存空间)
    int arr1[10];
    int arr2[5] = {1, 20, 3,42,5};
    int arr3[] = {1, 2, 3};
    int arr4[] = {};
    cout << sizeof(arr1) / sizeof(arr1[0]) << endl;
    for(int i = 0; i < sizeof(arr2) / sizeof(int); ++i){
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << arr2 << &arr2[0] << endl;

    int start = 0;
    int end = sizeof(arr2) / sizeof(int) - 1;
    while(start < end){
        auto temp = arr2[start];
        arr2[start] = arr2[end];
        arr2[end] = temp;
        start++;
        end--;
    }
    for(int i = 0; i < sizeof(arr2) / sizeof(int); ++i){
        cout << arr2[i] << " ";
    }
    cout << endl;
    Sort::GetInstance().BubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]));

    int arr[2][3];
    int arr5[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    int arr6[2][3] = {1, 2, 3, 4, 5, 6};
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cout << arr5[i][j] << " ";
        }
    }
    cout << endl;
    cout << sizeof(int *) << ":" << sizeof(char *) << endl;
    cout << sizeof(arr5) << arr5 << &arr5[0][0] << endl;

    /// 函数
    cout << add(1, 10) << endl;
    int swap1 = 10, swap2 = 20;
    swap(swap1, swap2);
    cout << "1:" << swap1 << "2:" << swap2 << endl;
    cout << add2(1, 2) << endl;
    cout << add2(1, 2, 3) << endl;


    /// 指针
    int m8 = 10;
    int *p = &m8;
    cout << p << *p << endl;
    cout << sizeof(p) << sizeof(int*) << sizeof(float*) << sizeof(char*) << endl;
    int *p1 = nullptr;
    cout << sizeof(p1) << p1 << endl;
//    *p1 = 10;  // 空指针(0-255)地址系统占用不可访问

//    int *p2 = (int *)0x1100;  //  指针变量中的值是非法的内存地址，进而形成野指针。
//    局部指针变量没有被初始化。
//    指针所指向的变量在指针之前被销毁（返回局部变量和局部数组）。
//    使用已经释放过的指针。
//    进行了错误的指针运算。
//    进行了错误的强制类型转换。
//    *p2 = 10;
//    cout << *p2 << endl;

    int m10 = 20;
    int m11 = 30;
    const int * p3 = &m10;  // 常量指针
//    *p3 = 50;  // no
    p3 = &m11;
    cout << *p3 << endl;

    int * const p4 = &m10; // 指针常量
//    p4 = &m11; // no
    *p4 = 50;
    cout << *p4 << endl;


    for(int i = 0; i < sizeof(arr2) / sizeof(int); ++i){
        cout << arr2[i] << " ";
    }
    cout << endl;
    int *p5 = arr2;
    for(int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); ++i)
    {
        cout << *p5 << " ";
//        p5++;
//        p5 = p5 + 1;
//        p5 = p5 + sizeof(int); // no
        p5 ++;
    }
    cout << endl;

    cout << arr2 << " " << arr2 + 1 << endl;
    cout << p5 << " " << ++p5 << " " << (p5 + 1) << endl;

    int* p6 = arr6[0];
    for(;p6 < arr6[0] + 6; ++p6){
        cout << *p6 << " ";
    }
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cout << *(arr6[i] + j) << " ";
        }
    }
    int a1 = 10, a2 = 20;
    swap(&a1, &a2);
    cout << a1 << a2 << endl;

    /// 结构体
    Student s1{"zwu5", 10, 200.0};
    cout << s1.age << s1.name << s1.height << endl;

    teacher.name = "zeku";
    teacher.age = 50;
    teacher.height = 300.0;
//    teacher = s1;  // 同一种结构体相互赋值
    Student s2 = std::move(s1);
    cout << s2.name << endl;

    Student sArray[3] = {
            {"z", 2, 2.0},
            {"w", 3, 3.0},
            {"k", 4, 4.0}
    };
    Student *ss = sArray;
    cout << ss->name << (ss+1)->age << endl;
    printAll(*ss);
    printAll(ss+2);

//    AddressBook::GetInstance();

    /// 内存模型
    // 代码区 --> 全局区 --> 栈区 --> 堆区
    int l_a = 10;
    static int s_a = 10;
    const int c_l_a = 10;
    cout << &l_a << " " << &g_a << " " << &s_a << " " << &c_l_a << " " << &c_a << endl;

    int *p7 = fun();
    cout << p7 << *p7 << endl;
    delete p7;
    cout << p7 << endl;
//    if(p7 == nullptr) cout << "nullptr" << endl;  // 指针不为空指针
    *p7 = l_a;
    cout << p7 << *p7 << endl;

    /// 引用 = 指针常量
    int m12 = 10;
    int &m13 = m12;  // 不可改变指向其他变量
    cout << m13 << endl;
    m12 = 20;
    cout << m13 << endl;
    m13 = 50;
    m13 = l_a;
    cout << m12 << endl;

    int& m14 = fun1(l_a);
    cout << m14 << endl;
    cout << add2() << endl;

    Cube c1, c2;  // 不要加() 编译器误认为函数声明
    string string1 = "cube";
    Cube c6 = string1; // 隐式转换
    cout << c6.getName() << endl;
    c1.SetH(20.0);
    c1.SetL(30.0);
    c1.SetW(40.0);
    cout << c1.GetArea() << " " << c1.GetVolume() << endl;
    c2.SetH(20.0);
    c2.SetL(30.0);
    c2.SetW(40.0);
    cout << Cube::isSame(c1, c2) << endl;
    Cube c3("today");
    cout << c3.getName() << ":" << c2.getName() << endl;

    Cube c5(c3);
    cout << &(c5.m) << &(c3.m) << endl;

    fun3(c5);
    Cube c7 = fun5();
    cout << "拷贝构造函数后地址" << &c7 << endl;
//    fun6();
    int Height = 20;
    int *m_height = new int (Height);  // 深拷贝
    cout << "height:" << *m_height << endl;
    int *m_h2 = new int (10);
    cout << *m_h2 << endl;

    Test t1(20, 30);  // 类成员（构造:类成员-自己 析构：自己-类成员
    // 不能通过实例初始化静态成员,不属于某个对象
    cout << t1.s_m << Test::s_m << endl;
    Test::printAll();

    Person p1class;
    cout << sizeof(p1class) << endl; // 空对像占用1个字节(区分不同空对象)



    Test mt1(10, 20);
    Test mt2(20, 30);
    Test mt3 = mt1.TestAddHeight(mt2).TestAddHeight(mt2);
    cout << *mt1.mW << endl;
    cout << *mt3.mW << endl;

    Test *mt5 = nullptr;  // 空指针可以调用成员函数，但注意判断函数是否有this调用,不能有非静态成员函数
    mt5->printHello();
    mt1.setMember();
    const Test mt6(0, 10); // 常对象
    mt6.setMember(); // 只能调用常函数
//    mt1.getCubePrivate();

    Cube cc;


    /// 数值转换  int() static_cast<int>() memcpy() cout.setf()
    float f5 = 1.0;
    char ch5[4] = {0};
    memcpy(&ch, &f5, 4);
    cout.setf(ios::hex);

    return 0;
}

int add2(int a, int b)
{
    return (a + b) * 2;
}

int add2(int a, int b, int c)
{
    return (a + b + c);
}

void printAll(const Student &s)
{
    cout << &s << endl;
    cout << s.name << s.age << s.height << endl;
}

void printAll(const Student *s)
{
    cout << s->name << s->age << s->height << endl;
}

int *fun()
{
    int *p = new int(10);
    return p;
}

int * fun(int a)
{
    return nullptr;
}

int &fun1(const int &a){
    static int b = a + 10;
    return b;
}

int fun2(const int &a, int, float)
{
    int b = a + 10;
    return b;
}

void fun3(Cube c)
{
    cout << c.getName() << endl;
}

Cube fun5(){
    Cube p;
    cout << "拷贝构造函数前地址" << &p << endl;
    return p;
}

void fun6()
{
    Cube cc = fun5();
    cout << "拷贝构造函数后地址" << &cc << endl;
}