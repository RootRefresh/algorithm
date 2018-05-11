//
//  MergeTwoSortedLink.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/11.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "MergeTwoSortedLink.hpp"
// 自己方法，还有一种往一个链表中插入的方法
ListNode *merge(ListNode *h1,ListNode *h2)
{
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }
    
    ListNode *head = h1->val < h2->val ? h1:h2;
    ListNode *cur1 = h1->val < h2->val ? h1->next:h1;
    ListNode *cur2 = h1->val < h2->val ? h2:h2->next;
    ListNode *cur = head;
    
    while (cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            cur->next = cur1;
            cur1 = cur1->next;
        }else{
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    if (cur1 != NULL) {
        cur->next = cur1;
    }
    if (cur2 != NULL) {
        cur->next = cur2;
    }
    
    return head;
}
