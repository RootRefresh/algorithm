//
//  QuickSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/30.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "QuickSort.hpp"
#include "utils.hpp"
int partision(int *a, int begin, int end)
{
    int privot = a[end];
    
    int i = 0, j = 0;

    while (j < end) {
        if (a[j] <= privot) {
//            cout<<"开始:"<<endl;
//            printRange(a, begin, end);

            exchange(&a[i], &a[j]);
//            cout<<"结束:"<<endl;
//            printRange(a, begin, end);

            i++;
        }
        j++;
    }
    
    exchange(&a[i], &a[end]);
//    printRange(a, begin, end);
    return i;
}

void quickSort(int *a, int begin, int end)
{
    if (begin < end) {
        
        int p = partision(a, begin, end);
        
        quickSort(a, begin, p-1);
        quickSort(a, p+1, end);
    }
    
}
