//
//  JumpGame.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/28.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "JumpGame.hpp"

int jumpStep(vector<int> arr)
{
    if (arr.empty()) {
        return 0;
    }
    int cur = 0;
    int next = 0;
    int jump = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (cur < i) {
            cur = next;
            jump++;
        }
        next = max(next, i+arr[i]);
    }
    return jump;
}
