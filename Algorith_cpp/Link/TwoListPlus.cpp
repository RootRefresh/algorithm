//
//  TwoListPlus.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/6.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "TwoListPlus.hpp"

ListNode *reverseListTool(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *pre = NULL;
    ListNode *tmp = head->next;
    while (head != NULL) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    
    return pre;
}

ListNode *listPlus(ListNode *h1, ListNode *h2)
{
    ListNode *res = NULL;

    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }
    
    ListNode *n1 = reverseListTool(h1);
    ListNode *n2 = reverseListTool(h2);
    
    int ca = 0;
    ListNode *tmp = NULL;
    
    
    while (n1 != NULL && n2 != NULL) {
        int val = n1->val + n2->val + ca;
        ca = val / 10;
        
        ListNode *cur = new ListNode(val%10);
       
        if (res != NULL) {
            tmp -> next = cur;
            tmp = cur;
        }else{
            res = cur;
            tmp = cur;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    
    while (n1 != NULL) {
        int val = n1->val + ca;
        ca = val / 10;
        ListNode *cur = new ListNode(val%10);
        tmp->next = cur;
        tmp = cur;
        n1=n1->next;
    }
    
    while (n2 != NULL) {
        int val = n2->val + ca;
        ca = val / 10;
        ListNode *cur = new ListNode(val%10);
        tmp->next = cur;
        tmp = cur;
        n2=n2->next;
    }
    if (ca > 0) {
        ListNode *cur = new ListNode(ca);
        tmp->next = cur;
    }
    
    return reverseListTool(res);
}
