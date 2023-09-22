//
// Created by heygears on 23-9-22.
//

#include "Sort.h"
using namespace std;

/// 保证最小的永远在队首 O(n^2)
void Sort::TempSort(int *array, int len) {
    for(int i = 0; i < len; ++i){
        for(int j = i; j < len; ++j){
            int temp = array[i];
            if(temp > array[j])
            {
                array[i] = array[j];
                array[j] = temp;
            }
        }

        for(int ii = 0; ii < len; ++ii){
            cout << array[ii] << " ";
        }
        cout << endl;
    }
}

/// 保证每次排序队尾为最大/小值 O(n^2)
void Sort::BubbleSort(int *array, int len) {
    for(int i = 0; i < len - 1; ++i){
        for(int j = 0; j < len - i - 1; ++j){
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }


        for(int ii = 0; ii < len; ++ii){
            cout << array[ii] << " ";
        }
        cout << endl;
    }
}

Sort &Sort::GetInstance() {
    static Sort instance;
    return instance;
}

Sort::Sort() {

}

Sort::~Sort() {

}
