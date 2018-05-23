//
//  changeMoneyMethodCount.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/18.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "changeMoneyMethodCount.hpp"
int strongRecure(vector<int> &arr, int index, int aim)
{
    int res = 0;
    
    if (index == arr.size()) {
        return aim == 0 ? 1:0;
    }else{
        
        for (int i = 0; arr[index]*i < aim; i++) {
            res += strongRecure(arr , index+1, aim-arr[index]*i);
        }
    }
    return res;
}

int rec(vector<int> &arr, int aim){
    if (arr.size() == 0 || aim<0) {
        return -1;
    }
    return strongRecure(arr, 0, aim);
}


