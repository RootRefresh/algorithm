//
//  SingleLinkSelectionSort.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/10.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "SingleLinkSelectionSort.hpp"

ListNode *smallPreNode(ListNode *head)
{
    ListNode *cur = head->next;
    ListNode *pre = head;
    ListNode *smallPre = head;
    ListNode *small = head;
    while (cur != NULL) {
        if (cur->val < small->val) {
            small = cur;
            smallPre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    return smallPre;
}


ListNode *selectionSort(ListNode *head)
{
    if (head == NULL) {
        return head;
    }
    
    ListNode *pre = head;
    ListNode *cur = head;
    ListNode *small = head;
    ListNode *smallPre = head;
    
    while (cur != NULL) {
        smallPre = smallPreNode(cur);
        small = smallPre->next;
        head  = head->val > small->val ? small:head;
        
        if (small->val < cur->val) {
            smallPre->next = cur->next;
        }
        
        pre = cur;
        cur = cur->next;
    }
    
    return head;
}
