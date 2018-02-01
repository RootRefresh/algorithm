//
//  RemoveByRatio.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "RemoveByRatio.hpp"
#include <math.h>
//删除a/b处 节点
ListNode * removeByRatio(ListNode *head, int a, int b)
{
    if (head == NULL || a > b || a < 1) {
        return head;
    }
    
    int len = 0;
    ListNode *cur = head;
    while (cur != NULL) {
        cur = cur->next;
        len++;
    }
    
    int k = ceil(len * a/b);
    ListNode *pre = NULL;
    cur = head;
    if (k == 1) {
        return head->next;
    }
    while (k > 1) {
        pre = cur;
        cur = cur->next;
        k--;
    }
    pre->next = cur->next;
    return head;
}
