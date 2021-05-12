//
//  InsertSort.h
//  ds
//
//  Created by Ruby on 2021/5/12.
//

#ifndef InsertSort_h
#define InsertSort_h


using namespace std;

/**
  * 暴力插入排序版本
 */
template <typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j -1]);
            } else {
                break;
            }
        }
    }
}

/**
 *优化插入位置
 */
template <typename T>
void insertSortOpt(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] < val) {
                arr[j] = val;
                break;
            } else {
                arr[j] = arr[j - 1];
            }
        }
        
    }
}

#endif /* InsertSort_h */
