//
//  BubbleSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/8/9.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "BubbleSort.hpp"
#include "utils.hpp"

void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n-1; i++) {
        int k = i;
        for (int j = i+1; j < n; j++) {
            if (a[k] > a[j]) {
                exchange(&a[k], &a[j]);
            }
            k = j;

        }
        printOut(a, n);

    }
}
