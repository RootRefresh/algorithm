//
//  HanoTower.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/21.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "HanoTower.hpp"
#include "utils.hpp"
#include <string>
//汉诺塔 初级问题

void func(int n, string from, string mid, string to)
{
    if (n == 1) {
        cout << "from " << from << " to " << to << endl;
    }else{
        func(n-1, from, to, mid);
        func(1, from, mid, to);
        func(n-1, mid, from, to);
    }
}

void hanoi(int n)
{
    if (n > 0) {
        func(n, "left", "mid", "right");
    }
}

//进阶问题 TO DO


