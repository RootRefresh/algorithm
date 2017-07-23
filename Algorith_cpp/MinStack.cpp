//
//  MinStack.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/7/20.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include "MinStack.hpp"
#include <iostream>
#include <stack>
using namespace std;

//MinStack::MinStack()
//{
//    
//}
//MinStack::~MinStack()
//{
//    
//}

stack<int> stackData;
stack<int> stackMin;

void MinStack::push(int val){
    
    if (stackMin.empty()) {
        stackMin.push(val);
    }else{
        int tmp = 0;
      
        if (val <= stackMin.top()) {
            tmp = val;
        }else{
            tmp = stackMin.top();
        }
        
        stackMin.push(tmp);
    }
    
    stackData.push(val);
}

void MinStack::pop(){
    if (!stackData.empty()) {
        stackMin.pop();
        stackData.pop();
    }
}

int MinStack::getMin(){
    
    if (stackMin.empty()) {
        ;
        cout<<"空栈"<<endl;
        return -111111;
    }
//    try {
//       return stackMin.top();
//    } catch (<#catch parameter#>) {
//        <#statements#>
//    }
    return stackMin.top();

}

int MinStack::empty()
{
    return stackData.empty()?1:0;
}

