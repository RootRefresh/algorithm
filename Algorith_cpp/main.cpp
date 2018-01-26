//
//  main.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/7/8.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include <iostream>

#include "MinStack.hpp"

#include "TwoStackQueue.hpp"

#include "ReverseStackByRecursion.hpp"

#include "utils.hpp"
#include "InsertSort.hpp"
#include "MergeSort.hpp"
using namespace std;

void test_1_0_2()
{
    cout << "1.0.2" << endl;
    cout << "1.0.3" << endl;
    cout << "1.0.4" << endl;


}

int main(int argc, const char * argv[]) {
  
    int arr2[] = {3,6,2,8,5,4};
//    insertSort(arr2, 6);
    mergeSort(arr2, 0, 5);
    
    int arr[] = {1,2,3};
    //最小值栈
//    MinStack s;
//    
//    for (int i = 0; i< 4; i++) {
//        s.push(arr[i]);
//    }
//    while (!s.empty()) {
//        
//        cout << s.getMin() << endl;
//        s.pop();
//    }
    
    //两个栈模拟队列
//    TwoStackQueue queue;
//    
//    for (int i = 0; i< 4; i++) {
//        queue.add(arr[i]);
//    }
//    
//
//    for (int i = 0; i< 4; i++) {
//        cout << queue.peek() << endl;
//       
//        if (i==2) {
//            queue.add(8);
//        }
//
//        cout << queue.poll() << endl;
//
//    }
//    cout << queue.poll() << endl;

    
//    ReverseStack rStack;
//
//    for (int i = 0; i< 3; i++) {
//        rStack.push(arr[i]);
//    }
//    rStack.traversal();

//    rStack.reverse();
//
//    rStack.traversal();


    return 0;
}
