//
//  MinStack.hpp
//  Algorith_cpp
//
//  Created by USER on 2017/7/20.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>



class MinStack
{
public:
//    MinStack();
//    ~MinStack();
    
    void push(int);
    void pop();
    int getMin();
    int empty();
};




#endif /* MinStack_hpp */
