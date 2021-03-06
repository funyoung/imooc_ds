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

/**
 *随机生成n个元素的数组，数组元素取值是[low, high]之间的随机值
 */
int * generateRandomArray(int n, int low, int high) {
    assert(low <= high);
    int * arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}

/**
 *随机生成近似有序的数组。先生成含有n个元素的有序数组，取值从从0到n-1。然后随机交换某两个索引的元素swapTimes次
 */
int * generateNearlyOrderArray(int n, int swapTimes) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    srand(time(NULL));
    for (int i = 0; i < swapTimes; i++) {
        int l = rand() % n;
        int r = rand() % n;
        swap(arr[l], arr[r]);
    }
    
    return arr;
}

template <typename T>
bool isAsscend(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool arrayEquals(T src[], T dst[], int n) {
    if (src == dst) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (dst[i] != src[i]) {
            return false;
        }
    }
    
    return true;
}

template <typename T>
void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
    clock_t start = clock();
    sort(arr, n);
    clock_t end = clock();
    
    assert(isAsscend(arr, n));
    cout << sortName << " : " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
}

int * copyArray(int src[], int n) {
    assert(src);
    assert(n >= 0);
    
    int *dst = new int[n];
    memcpy(dst, src, n * sizeof(int));
    
    assert(dst != src);
    assert(arrayEquals(src, dst, n));
    
    return dst;
}

}

#endif /* SortTestHelper_h */
