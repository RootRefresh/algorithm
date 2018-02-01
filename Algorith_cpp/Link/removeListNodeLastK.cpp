//
//  removeListNodeLastK.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "removeListNodeLastK.hpp"

ListNode * removeLastK(ListNode *head, int K)
{
    int len = 0;
    ListNode *tmp = head;
    while (tmp != NULL) {
        tmp = tmp-> next;
        len ++;
    }
    if (K > len || K < 1 || head == NULL) {
        return head;
    }
    ListNode *pre = NULL;
    tmp = head;
    for (int i = 0; i < len-K; i++) {
        pre = tmp;
        tmp = tmp->next;
    }
    //删除头结点
    if (tmp == head) {
        head = head->next;
    }else{
        pre->next = tmp ->next;
    }
    return head;
}

DoubleList * removeKthNode(DoubleList *head, int K)
{
    int len = 0;
    DoubleList *tmp = head;
    while (tmp != NULL) {
        tmp = tmp-> next;
        len ++;
    }
    if (K > len || K < 1 || head == NULL) {
        return head;
    }
    
    DoubleList *p = NULL;
    tmp = head;
    for (int i = 0; i < len - K; i++) {
        p   = tmp;
        tmp = tmp ->next;
    }
    if (tmp == head) {
        head = head->next;
        head -> pre = NULL;
    }else{
        p ->next = tmp->next;
        if (tmp->next != NULL) {
            tmp->next->pre = p;
        }
        tmp->pre = NULL;
    }
    
    return head;
}

