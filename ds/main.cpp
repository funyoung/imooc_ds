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

template <typename T>
void copyArrayAndTestSort(string sortName, void(*sort)(T[], int), T src[], int n) {
    int *dst = SortTestHelper::copyArray(src, n);
    SortTestHelper::testSort(sortName, sort, dst, n);
    delete dst;
}

template <typename T>
void testArraySort(string testName, T arr[], int n) {
    cout << testName << " with " << n << " elements:" << endl;
    copyArrayAndTestSort("Selection Sort", selectionSort, arr, n);
    copyArrayAndTestSort("Insert Sort", insertSort, arr, n);
    copyArrayAndTestSort("Insert Sort(opt)", insertSortOpt, arr, n);
    copyArrayAndTestSort("Bubble Sort", bubleSort, arr, n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, sort!\n";
    
    //int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 100000;
    
    // todo: zhe'liang'ha
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    //selectionSortAndPrint(arr, n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    testArraySort("Test with random array", arr, n);
    delete arr;
    
    int *data = SortTestHelper::generateNearlyOrderArray(n, 100);
    testArraySort("Test with nearly ordered array", data, n);
    delete data;
    
    float b[] = {5.4, 6.8, 3.2, 2.1, 1.0};
    selectionSortAndPrint(b, 5);
    
    string c[] = {"He", "ee", "oo", "ld", "good" };
    selectionSortAndPrint(c, 5);
    
    Student s[] = {{"Tom", 10}, {"Ruby", 10}, {"Toby", 4}, {"Sam", 9}};
    selectionSortAndPrint(s, 4);
    
    return 0;
}
