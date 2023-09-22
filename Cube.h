//
// Created by heygears on 23-9-22.
//

#ifndef UNTITLED_CUBE_H
#define UNTITLED_CUBE_H
#include <string>
#include <iostream>

/* 编译器默认提供 空构造 空析构 空拷贝构造 */
/* 定义有参构造 则舍弃空构造  定义拷贝构造 舍弃空构造*/
class Cube {
public:
    /// constructor function 构造函数 可重载
    Cube();
    Cube(std::string name);

    /// 析构函数
    ~Cube();

    /// 拷贝构造函数
    // 1.使用创建对象初始化新对像
    // 2.值传递给函数传值
    // 3.值方式返回局部对象  ? 存疑 move
//    Cube(const Cube& c);
    float GetArea();
    float GetVolume();
    void SetL(float l);
    void SetW(float w);
    void SetH(float h);
    std::string getName();
    static bool isSame(Cube &c1, Cube &c2);

    int m = 1;
private:
    float m_l;
    float m_w;
    float m_h;
    std::string name{};
//    Cube();
//    ~Cube();
//    Cube(const Cube&) = delete;
//    Cube& operator=(const Cube&) = delete;
};


#endif //UNTITLED_CUBE_H
