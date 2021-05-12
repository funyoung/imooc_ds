//
//  SelectionSort.h
//  ds
//
//  Created by Ruby on 2021/5/12.
//

#ifndef SelectionSort_h
#define SelectionSort_h

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
void selectionSortAndPrint(T a[], int n) {
    selectionSort(a, n);
    SortTestHelper::printArray(a, n);
}


#endif /* SelectionSort_h */
