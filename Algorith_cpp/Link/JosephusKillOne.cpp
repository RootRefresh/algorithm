//
//  JosephusKillOne.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/2.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "JosephusKillOne.hpp"

ListNode * josephusKill(ListNode *head, int m)
{
    if (head == NULL || m < 1) {
        return head;
    }
    
    ListNode *pre = head;
    ListNode *cur = head;
    int k = m;
    
    while (pre->next != pre) {
        while (k > 1) {
            pre = cur;
            cur = cur->next;
            k--;
        }
        pre->next = cur->next;
        cur = cur->next;
        k = m;
    }
    return pre;
}
