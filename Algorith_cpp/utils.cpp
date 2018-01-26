//
//  utils.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/26.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "utils.hpp"


void printRange(int *a, int begin, int end)
{
    for (int i = begin; i <= end; i++) {
        if (i == end) {
            cout << a[i] << endl ;
        }else{
            cout << a[i] << ",";
        }
    }
}

void printOut(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        cout<< a[i] << endl;
    }
}
