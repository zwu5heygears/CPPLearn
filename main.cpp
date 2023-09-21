#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
std::vector<char> m1;
m1.push_back(0x00);
m1.push_back(0x00);
m1.push_back(0x80);
m1.push_back(0x3f);
    char tmp[4] = { 0 };
tmp[0] = m1[0] & 0xFF;
tmp[1] = m1[1] & 0xFF;
tmp[2] = m1[2] & 0xFF;
tmp[3] = m1[3] & 0xFF;
float value = 0;
printf("%f", value);
    return 0;
}
