//
//  ReveseKNode.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/8.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "ReveseKNode.hpp"
#include <stack>
ListNode *resign1(stack<ListNode *>mStack, ListNode *left, ListNode *right)
{
    ListNode *cur = mStack.top();
    mStack.pop();
    if (left != NULL) {
        left->next = cur;
    }
    ListNode *next = NULL;
    while (!mStack.empty()) {
        next = mStack.top();
        mStack.pop();
        cur->next = next;
        cur = next;
    }
    cur->next = right;
    return cur;
}

ListNode * reverseKNode(ListNode *head, int K)
{
    if (K < 2) {
        return head;
    }
    stack<ListNode *> mStack;
    ListNode *cur = head;
    ListNode *newHead = head;
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (cur != NULL) {
        mStack.push(cur);
        next = cur->next;
        if (mStack.size() == K) {
            pre = resign1(mStack, pre, next);
            newHead = newHead == head ? cur:newHead;
        }
        cur = next;
    }
    return newHead;
}
//start到end 指针逆序，然后非空left指向新链表头，新链表尾指向right
void resign2(ListNode *left, ListNode *start, ListNode *end, ListNode *right)
{
    ListNode *pre = start;
    ListNode *cur = pre->next;
    ListNode *next = NULL;
    while (cur != right) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    
    if (left != NULL) {
        left->next = pre;
    }
    start->next = right;
}

ListNode *reverseKNode2(ListNode *head, int K)
{
    if (K < 2) {
        return head;
    }
    
    ListNode *pre = NULL;
    ListNode *next = NULL;
    ListNode *cur = head;
    ListNode *start = NULL;
    int count = 1;
    
    while (cur != NULL) {
        next = cur->next;
        if (count == K) {
            start = pre == NULL? head: pre->next;
            head  = pre == NULL? cur: head;      //找到新的头结点
            resign2(pre, start, cur, next);
            pre = start;
            count = 0;
        }
        count++;
        cur = next;
    }
    return head;
}



