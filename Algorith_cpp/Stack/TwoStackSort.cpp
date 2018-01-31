//
//  TwoStackSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/31.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "TwoStackSort.hpp"
#include <stack>
#include "utils.hpp"

stack<int> stackOrigin;
stack<int> stackHelp;

void twoStackSort(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        stackOrigin.push(a[i]);
    }
    
    while (!stackOrigin.empty()) {
       
        int tmp = stackOrigin.top();

        if (stackHelp.empty() || stackHelp.top() < tmp) {
            stackHelp.push(tmp);
            stackOrigin.pop();
        }else{
            stackOrigin.pop();

//            int k = 0;
            while (!stackHelp.empty() && stackHelp.top() > tmp) {
                stackOrigin.push(stackHelp.top());
                stackHelp.pop();
//                k++;
            }
            
            stackHelp.push(tmp);
           
//            while (k != 0) {
//                stackHelp.push(stackOrigin.top());
//                stackOrigin.pop();
//                k--;
//            }
        }

    }
    
    while (!stackHelp.empty()) {
        cout << stackHelp.top() << ",";
        stackHelp.pop();
    }
}
