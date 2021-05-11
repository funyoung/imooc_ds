//
//  main.cpp
//  ds
//
//  Created by yangfeng on 2021/5/11.
//  Copyright © 2021 yangfeng. All rights reserved.
//

#include <iostream>

#include "Student.h"

using namespace std;

template <typename T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }
}

template <typename T>
void printArray(T a[], int n) {
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSortAndPrint(T a[], int n) {
    selectionSort(a, n);
    printArray(a, n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, sort!\n";
    
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAndPrint(a, 10);
    
    float b[] = {5.4, 6.8, 3.2, 2.1, 1.0};
    selectionSortAndPrint(b, 5);
    
    string c[] = {"He", "ee", "oo", "ld", "good" };
    selectionSortAndPrint(c, 5);
    
    Student s[] = {{"Tom", 10}, {"Ruby", 10}, {"Toby", 4}, {"Sam", 9}};
    selectionSortAndPrint(s, 4);
    
    return 0;
}
