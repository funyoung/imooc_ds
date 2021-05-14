//
//  HeapSort.h
//  ds
//
//  Created by Ruby on 2021/5/13.
//

#ifndef HeapSort_h
#define HeapSort_h

#include <cassert>

using namespace std;

// [0, n)的数组，下移第i个元素节点以满足最大堆的约束要求根节点不小于它的两个子节点的值
template <typename T>
void __shiftDown(T arr[], int i, int n) {
    //cout << "__shiftDown: " << i << ", " << n << endl;
    
    int l = 2 * i + 1;
    int r = l + 1;
    if (l < n) {
        int k = l;
        if (r < n) {
            k = arr[l] > arr[r] ? l : r;
        }
        if (arr[i] < arr[k]) {
            swap(arr[i], arr[k]);
            __shiftDown(arr, k, n);
        }
    }
}

// heapify, 从第一个非叶子节点的索引开始到根节点索引0一次进行shiftDown
// 最大堆结构的数组变换成从小到大排序数组，索引0与最后索引n-1的值交换，然后shiftDown索引0的节点重建[0, n-1)为最大堆。
template <typename T>
void heapifyInlineSort(T arr[], int n) {
    assert(arr);
    assert(n >= 0);
    for (int i = (n - 2) / 2; i >=0; i--) {
        __shiftDown(arr, i, n);
    }
    
    for (int count = n - 1; count > 0; count--) {
        swap(arr[0], arr[count]);
        __shiftDown(arr, 0, count);
    }
}

#endif /* HeapSort_h */
