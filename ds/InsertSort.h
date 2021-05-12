//
//  InsertSort.h
//  ds
//
//  Created by Ruby on 2021/5/12.
//

#ifndef InsertSort_h
#define InsertSort_h


using namespace std;

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

#endif /* InsertSort_h */
