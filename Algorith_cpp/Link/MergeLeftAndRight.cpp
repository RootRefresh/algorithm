//
//  MergeLeftAndRight.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/11.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "MergeLeftAndRight.hpp"
#include "utils.hpp"
/*
     1、先找到链表中点（利用快慢指针找到最佳，遍历一遍再除2 太low了）
     2、中点前部分为左半区，中点及以后为右半区
     3、穿插合并左右区
 */
//实现1
ListNode *merge(ListNode *head)
{
    if (head == NULL) {
        return head;
    }
    ListNode *cur  = head;
    ListNode *cur2 = NULL;
    int count = 1;
    while (cur != NULL) {
        cur = cur->next;
        count ++;
    }
    int step = count/2;
    ListNode *pre = NULL;
    cur=head;
    while (step != 0) {
        step--;
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
    cur2 = cur;
    cur  = head;
    
    ListNode *next1 = cur;
    ListNode *next2 = cur2;

    while (cur != NULL) {
        next1 = next1->next;
        next2 = next2->next;
        
        cur->next = cur2;
        if (next1 == NULL) {
            break;
        }
        cur2->next = next1;
        
        cur  = next1;
        cur2 = next2;
    }
    return head;
}

void mergeLR(ListNode *left, ListNode *right)
{
    ListNode *next = NULL;
    while (left->next != NULL) {
        next = right->next;
        right->next = left->next;
        left->next = right;
        left = right->next;
        right = next;
    }
    left->next = right;
}

//优化
void merge2(ListNode *head)
{
    if (head == NULL) {
        return;
    }
    ListNode *mid   = head;
    ListNode *right = head->next;
    while (right->next != NULL && right->next->next != NULL) {
        mid=mid->next;
        right = right->next->next;
    }
    right = mid->next;
    mid->next = NULL;
    mergeLR(head, right);
    
}
