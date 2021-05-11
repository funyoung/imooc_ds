//
//  SortTestHelper.h
//  ds
//
//  Created by yangfeng on 2021/5/11.
//  Copyright © 2021 yangfeng. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {
template <typename T>
void printArray(T a[], int n) {
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int * generateRandomArray(int n, int low, int high) {
    assert(low <= high);
    int * arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}
}

#endif /* SortTestHelper_h */
