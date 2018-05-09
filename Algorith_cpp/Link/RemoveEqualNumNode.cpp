//
//  RemoveEqualNumNode.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/9.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "RemoveEqualNumNode.hpp"

void removeNode(ListNode *head, int num)
{
    if (head == NULL) {
        return;
    }
    
    while (head != NULL && head->val == num) {
        head = head->next;
    }
    
    ListNode *pre = NULL;
    ListNode *cur = head;

    while (cur != NULL) {
        if (cur->val == num) {
            pre->next = cur->next;
        }else{
            pre = cur;
        }
        cur = cur->next;
    }
}
