//
//  IsDeformation.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/28.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "IsDeformation.hpp"

bool isDeformation(string str1, string str2)
{
    if (str1.empty() || str2.empty() || str1.length() != str2.length()) {
        return false;
    }
    vector<int> map(256);
    for (int i = 0; i < str1.length(); i++) {
        map[str1[i]]++;
    }
    for (int j = 0 ; j < str2.length(); j++) {
        map[str2[j]]--;
        if (map[str2[j]] < 0) {
            return false;
        }
    }
    
    return true;
}
