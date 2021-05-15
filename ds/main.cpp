//
//  main.cpp
//  ds
//
//  Created by yangfeng on 2021/5/11.
//  Copyright © 2021 yangfeng. All rights reserved.
//

#include <iostream>

#include "Student.h"
#include "SortTestHelper.h"

#include "SelectionSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"

#include "MaxHeapTest.h"

template <typename T>
void copyArrayAndTestSort(string sortName, void(*sort)(T[], int), T src[], int n) {
    int *dst = SortTestHelper::copyArray(src, n);
    SortTestHelper::testSort(sortName, sort, dst, n);
    delete dst;
}

template <typename T>
void testFastArraySort(string testName, T arr[], int n) {
    cout << testName << " with " << n << " elements:" << endl;
    copyArrayAndTestSort("Heap Sort", heapSort, arr, n);
    //copyArrayAndTestSort("Heap Sort(heapify)", heapifySort, arr, n);
    copyArrayAndTestSort("Heap Sort(inline heapify)", heapifyInlineSort, arr, n);
    // copyArrayAndTestSort("Merge Sort", bubleSort, arr, n);
}

template <typename T>
void testSlowArraySort(string testName, T arr[], int n) {
    cout << testName << " with " << n << " elements:" << endl;
    copyArrayAndTestSort("Selection Sort", selectionSort, arr, n);
    copyArrayAndTestSort("Insert Sort", insertSort, arr, n);
    copyArrayAndTestSort("Insert Sort(opt)", insertSortOpt, arr, n);
    copyArrayAndTestSort("Bubble Sort", bubleSort, arr, n);
}

/**
 *O(n2)时间复杂度的排序算法测试
 */
void testSlowArraySort(int n) {
    cout << "------ Testing O(n2) sorting algorithms with " << n << "items ------" << endl;
    
    // todo: 这两段代码很近似，如何优化？
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    //selectionSortAndPrint(arr, n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    testSlowArraySort("Test with random array", arr, n);
    delete arr;
    
    int *data = SortTestHelper::generateNearlyOrderArray(n, 100);
    testSlowArraySort("Test with nearly ordered array", data, n);
    delete data;
    
//    int *dd = SortTestHelper::generateRepeatAraay(...);
//    testSlowArraySort("Test with large repeated elements array", dd, n);
//    delete dd;
}

/**
 *O(n*lg(n))时间复杂度的排序算法测试
 */
void testFastArraySort(int n) {
    cout << "------ O(n*lg(n)) sorting algorithms with " << n << "items ------" << endl;
    
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    testFastArraySort("Test with random array", arr, n);
    delete arr;
    
    int *data = SortTestHelper::generateNearlyOrderArray(n, 100);
    testFastArraySort("Test with nearly ordered array", data, n);
    delete data;
}


int maxOperationCount(int coin[], int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        assert(num > 0);
        
        num <<= 1;
        if (coin[i] != 0) {
            num++;
        }
    }
    return num;
}

void verify(int expected, int data[], int n) {
    int num = maxOperationCount(data, 3);
    cout << num << endl;
    assert(num == expected);
}
int main(int argc, const char * argv[]) {
//    int data[] = {0, 1, 1};
//    verify(3, data, 3);
//
//    int zero[] = {0, 0, 0, 0, 0};
//    verify(<#int expected#>, <#int *data#>, <#int n#>)
    
    
    // insert code here...
    std::cout << "Hello, sort!\n";

    testSlowArraySort(10000);

    testFastArraySort(1000000);

    float b[] = {5.4, 6.8, 3.2, 2.1, 1.0};
    selectionSortAndPrint(b, 5);

    string c[] = {"He", "ee", "oo", "ld", "good" };
    selectionSortAndPrint(c, 5);

    Student s[] = {{"Tom", 10}, {"Ruby", 10}, {"Toby", 4}, {"Sam", 9}};
    selectionSortAndPrint(s, 4);
    
    //testMaxHeap(50);
    
    return 0;
}
