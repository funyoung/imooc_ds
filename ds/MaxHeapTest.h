//
//  MaxHeapTest.h
//  ds
//
//  Created by Ruby on 2021/5/15.
//

#ifndef MaxHeapTest_h
#define MaxHeapTest_h

#include "MaxHeap.h"

void testMaxHeap(int n) {
    MaxHeap h(n);
    for (int i = 0; i < n; i++) {
        h.push(i);
        cout << i << " pushed: " << h << endl;
    }
    
    while (!h.empty()) {
        int i = h.pop();
        cout << i << " poped: " << h << endl;
    }
}

#endif /* MaxHeapTest_h */
