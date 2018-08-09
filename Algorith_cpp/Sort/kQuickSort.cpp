//
//  kQuickSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/8/9.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "kQuickSort.hpp"
#include "utils.hpp"
void swap(int *a, int *b)
{
    int c = *a ^ *b;
    *a  = *a ^ c;
    *b  = *b ^ c;
}

void printOut1(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        cout<< a[i] << ",";
        if (i == n-1) {
            cout<<endl;
        }
    }
}

int partion(int *arr, int begin, int end)
{
    int key = arr[end];
    int i = begin, j = begin;
    while (j < end) {
        if (arr[j] <= key) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    
    swap(&arr[i], &arr[end]);
//    printOut1(arr, 8);
    return i;
}

void kQuickSort(int *arr, int begin, int end)
{
    if (begin < end) {
        int mid = partion(arr, begin, end);
        kQuickSort(arr, begin, mid-1);
        kQuickSort(arr, mid+1, end);
    }
}
