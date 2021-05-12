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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, sort!\n";
    
    //int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int * cpy = SortTestHelper::copyArray(arr, n);
    
    //selectionSortAndPrint(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    
    SortTestHelper::testSort("Insert Sort", insertSort, cpy, n);
    
    delete arr;
    delete cpy;
    
    float b[] = {5.4, 6.8, 3.2, 2.1, 1.0};
    selectionSortAndPrint(b, 5);
    
    string c[] = {"He", "ee", "oo", "ld", "good" };
    selectionSortAndPrint(c, 5);
    
    Student s[] = {{"Tom", 10}, {"Ruby", 10}, {"Toby", 4}, {"Sam", 9}};
    selectionSortAndPrint(s, 4);
    
    return 0;
}
