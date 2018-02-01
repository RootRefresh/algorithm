//
//  removeMidNode.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "removeMidNode.hpp"


ListNode * removeMidNode(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    if (head->next->next == NULL) {
        return head->next;
    }
    ListNode *pre = head;
    ListNode *cur = head;
    cur = cur->next->next;
    while (cur->next!=NULL && cur->next->next != NULL) {
        pre = pre->next;
        cur = cur->next->next;
    }
    
    pre->next = pre->next->next;
    
    return head;
}
