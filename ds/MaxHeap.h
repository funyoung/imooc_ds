//
//  MaxHeap.h
//  ds
//
//  Created by Ruby on 2021/5/14.
//

#ifndef MaxHeap_h
#define MaxHeap_h

#include <cassert>

using namespace std;

class MaxHeap {
private:
    int capacity;
    int count = 0;
    int *data;
    
private:
    void shiftUp(int i) {
        while(i > 0) {
            int p = (i - 1) / 2;
            if (data[i] > data[p]) {
                swap(data[i], data[p]);
                i = p;
            } else {
                break;
            }
        }
    }
    
    void shiftDown(int i) {
        while (i < count) {
            int l = 2 * i + 1;
            if (l >= count) {
                break;
            }
            
            int r = l + 1;
            int k = l;
            if (r < count && data[l] < data[r]) {
                k = r;
            }
            
            if (data[k] > data[i]) {
                swap(data[i], data[k]);
                i = k;
            } else {
                break;
            }
        }
    }
    
public:
    MaxHeap(int cap) {
        capacity = cap;
        data = new int[capacity];
    }
    
    void push(int i) {
        assert(count < capacity);
        
        data[count] = i;
        shiftUp(count);
        count++;
    }
    
    int pop() {
        if (count > 0) {
            int val = data[0];
            data[0] = data[--count];
            shiftDown(0);
            return val;
        }
        return 0;
    }
    
    int size() {
        return count;
    }
    
    bool empty() {
        return count == 0;
    }
    
    friend ostream& operator<<(ostream &s, const MaxHeap &h) {
        s << "MaxHeap, capacity = " << h.count << "|" << h.capacity << endl;
        for (int i = 0; i < h.count; i++) {
            s << h.data[i] << " ";
        }
        s << endl;
        return  s;
    }
};

#endif /* MaxHeap_h */
