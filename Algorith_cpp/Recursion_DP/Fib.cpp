//
//  Fib.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/17.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "Fib.hpp"

//斐波那契
int f1(int n)
{
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    
    return f1(n-1)+f1(n-2);
}

int f2(int n)
{
    if (n < 0) {
        return 0;
    }
    if (n==1 || n==2) {
        return 1;
    }
    int pre = 1;
    int res = 1;
    int total = 0;
    for (int i = 3; i <= n; i++) {
        total = res + pre;
        pre   = res;
        res   = total;
    }
    return total;
}
