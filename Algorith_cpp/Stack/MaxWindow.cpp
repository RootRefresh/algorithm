//
//  MaxWindow.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/31.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "MaxWindow.hpp"
#include <deque>
#include "utils.hpp"

deque <int> qmax;
//  {3,6,2,8,5,4}
int * getMaxWindow(int *arr, int len, int w)
{
    if(len < w || w == 1){
        return nullptr;
    }
    int *res = new int[len - w + 1];
    int index = 0;
    
    for (int i = 0; i < len; i++) {
        while (!qmax.empty() && arr[qmax.back()] <= arr[i]) {
            qmax.pop_back();
        }
        qmax.push_back(i);

        if (qmax.front() == i-w) {
            qmax.pop_front();
        }
        if (i >= w-1) {
            res[index++] = arr[qmax.front()];
        }
    }  
    return res;
}

