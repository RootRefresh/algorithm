//
//  InsertSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/26.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "InsertSort.hpp"
#include "utils.hpp"
#include <iostream>

using namespace std;


void insertSort(int *a, int n)
{
    for (int i = 1; i < n; i ++) {
        
        int j = i - 1;
        int tmp = a[i];
        while (j>=0 && a[j] > tmp) {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = tmp;
    }
    printOut(a, n);
}
