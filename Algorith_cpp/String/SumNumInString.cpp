//
//  SumNumInString.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/28.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "SumNumInString.hpp"

int numSum(string str)
{
    if (str.empty()) {
        return 0;
    }
    int res = 0;
    int num = 0;
    int cur = 0;

    bool posi = true;
    for (int i = 0; i < str.length(); i++) {
        
        cur = str[i] - '0';
       
        if (cur < 0 || cur > 9) {
            res += num;
            num = 0;
            if (str[i] == '-') {
                if (i-1 > -1 && str[i-1] == '-') {
                    posi = !posi;
                }else{
                    posi = false;
                }
            }else{
                posi = true;
            }
            
        } else {
            
            num = num*10+(posi?cur:-cur);

        }
        
    }
    res+=num;
    return res;
}
