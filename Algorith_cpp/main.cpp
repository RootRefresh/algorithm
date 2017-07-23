//
//  main.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/7/8.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include <iostream>

#include "MinStack.hpp"

using namespace std;

void test_1_0_1()
{
    cout << "2.3.1" << endl;
}

int main(int argc, const char * argv[]) {
  
    int arr[] = {2,1,5,4};
    
    MinStack s;
    
    for (int i = 0; i< 4; i++) {
        s.push(arr[i]);
    }
    while (!s.empty()) {
        
        cout << s.getMin() << endl;
        s.pop();
    }
    
    
    return 0;
}
