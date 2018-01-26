//
//  MergeSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/26.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "MergeSort.hpp"
#include "utils.hpp"
#include <math.h>
void merge(int *a, int begin, int mid, int end)
{
    cout << "开始: " << endl;
    
    printRange(a, begin, end);

    int n1 = mid - begin + 1;
    int n2 = end - mid;
    
    int leftArr[n1],rightArr[n2];
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = a[begin+i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = a[mid + 1 + j];
    }
    
    int i= 0,j=0,k=begin;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i++];
        }else{
            a[k] = rightArr[j++];
        }
        k++;
    }
    
    while (i < n1) {
        a[k++] = leftArr[i++];
    }
    
    while (j < n2) {
        a[k++] = rightArr[j++];
    }
    cout << "结束: " << endl;
    printRange(a, begin, end);
}

void mergeSort(int *a, int begin, int end)
{
    if (begin < end) {
        int mid = (begin + end)/2;
        
        mergeSort(a, begin, mid);
        mergeSort(a, mid+1, end);
        merge(a, begin, mid, end);
    }
//    printOut(a, end-begin+1);
}

