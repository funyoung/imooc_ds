//
//  BubbleSort.h
//  ds
//
//  Created by Ruby on 2021/5/12.
//

#ifndef BubbleSort_h
#define BubbleSort_h

using namespace std;

template <typename T>
void bubleSort(T arr[], int n) {
    for (int r = n - 1; r > 0; r--) {
        for (int i = 0; i < r; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

#endif /* BubbleSort_h */
