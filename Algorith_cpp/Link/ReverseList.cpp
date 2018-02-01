//
//  ReverseList.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "ReverseList.hpp"

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *pre=NULL,*last = NULL;
    ListNode *cur = head;
    
    while (cur != NULL && cur->next != NULL) {
        last = cur ->next;
        
        cur->next = pre;
        ListNode *tmp = last->next;
        last->next = cur;

        pre = last;
        cur = tmp;
        
    }
    
    if (cur != NULL) {
        cur->next = pre;
    }else{
        cur = last;
    }
    
    return cur;
}

ListNode *reverseSubList(ListNode *head, int from, int to)
{
    int n = 0;
    ListNode *cur = head;
    while (cur) {
        cur = cur->next;
        n++;
    }
    if (from < 1 || to > n) {
        return head;
    }
    
    ListNode *pre = NULL;
    ListNode *begin = NULL;
    ListNode *endNode = NULL;
    cur = head;
    
    
    n = 0;
    while (cur) {
        if (n == from-1) {
            begin = cur;
        }
        if (n == to-1) {
            endNode = cur;
        }
        pre = cur;
        cur = cur->next;
        n++;
    }
    
    if (pre != NULL) {
        pre->next = endNode;
        begin->next = endNode->next;
    }
    ListNode *tmp = begin->next;
    ListNode *pre = NULL;

    ListNode *next = NULL;
    
    while (begin != endNode) {
        next = tmp->next;
        tmp->next = begin;
        
    }
    
    return head;
}

DoubleList *reverseDoubleList(DoubleList *head)
{
    DoubleList *p = NULL;
    DoubleList *next = NULL;
    
    while (head != NULL) {
        next = head->next;
        head ->next = p;
        head ->pre = next;
//        if (p != NULL) {
//            p->pre = head;
//        }
        p = head;
        head = next;
    }
    return p;
}

ListNode *bestReverseList(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *next = NULL;
    
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
