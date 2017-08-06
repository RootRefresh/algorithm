//
//  ReverseStackByRecursion.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/8/1.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include "ReverseStackByRecursion.hpp"


#include <stack>

#include <iostream>

using namespace std;

stack<int>myStack;

void ReverseStack::push(int val)
{
    myStack.push(val);
}
int ReverseStack::getAndRemoveElement()
{
    int tmp = myStack.top();
    myStack.pop();
    
    if (myStack.empty()) {
        
        return tmp;
   
    }else{
    
        int last = getAndRemoveElement();
        myStack.push(tmp);
        return last;
    }
}


void ReverseStack::reverse()
{
    if (myStack.empty()) {
        return;
    }
    
    int i = getAndRemoveElement();
//    traversal();
    cout<< "i=" << i << endl;
    reverse();
    myStack.push(i);
//    traversal();
}


void ReverseStack::traversal()
{
    while (!myStack.empty()) {
        
        cout << myStack.top() <<endl;
        myStack.pop();
    }
}
