//
//  Node.hpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/31.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
}ListNode;


#endif /* Node_hpp */
