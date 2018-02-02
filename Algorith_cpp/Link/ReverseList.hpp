//
//  ReverseList.hpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#ifndef ReverseList_hpp
#define ReverseList_hpp

#include <stdio.h>
#include "utils.hpp"

ListNode *reverseList(ListNode *head);
ListNode *bestReverseList(ListNode *head);

DoubleList *reverseDoubleList(DoubleList *head);

ListNode *reverseSubList(ListNode *head, int from, int to);

#endif /* ReverseList_hpp */
