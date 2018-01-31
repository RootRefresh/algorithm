//
//  HeapSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/30.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "HeapSort.hpp"
#include "utils.hpp"
#define L(i) (2*i + 1)
#define R(i) (2*i + 2)


void maxHeapify(int *a, int i, int n)
{
    int largest = i;
    int l = L(i);
    int r = R(i);

    if (l < n && a[l] > a[i]) {
        largest = l;
    }else{
        largest = i;
    }
    
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        exchange(&a[i], &a[largest]);
        maxHeapify(a, largest, n);
    }
}


void buildMaxHeap(int *a, int n)
{
    for (int i = n/2; i >= 0; i--) {
//        cout << i << ',' << endl;
        maxHeapify(a, i, n);
    }
}


void heapSort(int *a, int n)
{
    int size = n;
    buildMaxHeap(a, n);
    for (int i = n-1; i > 0; i--) {
        exchange(&a[0], &a[i]);
        size --;
        maxHeapify(a, 0, size);
    }
    
}


