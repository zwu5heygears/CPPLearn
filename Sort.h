//
// Created by heygears on 23-9-22.
//

#ifndef UNTITLED_SORT_H
#define UNTITLED_SORT_H
#include <iostream>

class Sort {
public:
    void BubbleSort(int *array, int len);
    void TempSort(int *array, int len);



    static Sort& GetInstance();
private:
    Sort();
    ~Sort();
    Sort(const Sort&) = delete;
    Sort& operator=(const Sort&) = delete;

};
#endif //UNTITLED_SORT_H
