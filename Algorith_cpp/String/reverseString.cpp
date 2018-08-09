//
//  reverseString.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/7/16.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "reverseString.hpp"

string reverseString(string str)
{
    char tmp;
    int i , j;
    for (i = 0,j = str.size()-1; i<j; i++,j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}
