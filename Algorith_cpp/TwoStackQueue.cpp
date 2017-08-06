//
//  TwoStackQueue.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/8/1.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include "TwoStackQueue.hpp"



#include <stack>

#include <iostream>
using namespace std;

stack<int > stackPush;
stack<int > stackPop;

void TwoStackQueue::add(int a){
    
    stackPush.push(a);
    
}
//top() && pop()
int TwoStackQueue::poll()
{
    if (stackPush.empty() && stackPop.empty()) {
        
        try {
            
            throw "empty queue";

        } catch (char *error) {
            
        }
    }else if (stackPop.empty()) {
            
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
           
    }
    
    int r = stackPop.top();
    
    stackPop.pop();
    
    return r;
    
}

//only top()
int TwoStackQueue::peek()
{
    if (stackPush.empty() && stackPop.empty()) {
        
        try {
            
            throw "empty queue";
            
        } catch (char *error) {
            cout<< error <<endl;
        }
    }else if(stackPop.empty()){
        
            
            while (!stackPush.empty()) {
               
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        
    }
    
    return stackPop.top();

}



