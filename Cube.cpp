//
// Created by heygears on 23-9-22.
//

#include "Cube.h"
using namespace std;

Cube::Cube() {

}

Cube::~Cube() {

}

float Cube::GetArea() {
    float area = (m_l * m_h + m_l * m_w + m_w * m_h) * 2;
    return area;
}

float Cube::GetVolume() {
    return m_h * m_l *m_w;
}

void Cube::SetL(float l) {
    m_l = l;
}

void Cube::SetW(float w) {
    m_w = w;
}

void Cube::SetH(float h) {
    m_h = h;
}

bool Cube::isSame(Cube &c1, Cube &c2) {
    if(c1.m_h == c2.m_h && c1.m_l == c2.m_l && c1.m_w == c2.m_w){
        return true;
    }
    else
    {
        return false;
    }
}

Cube::Cube(std::string name) {
    this->name = name;
}

std::string Cube::getName() {
    return name;
}

//Cube::Cube(const Cube & c) {  // 在类的成员函数中可以访问同类型实例的私有变量。
//    name = c.name;
//    m_h = c.m_h;
//    m_l = c.m_h;
//    m_w = c.m_w;
//    cout << "拷贝构造函数" << endl;
//}
