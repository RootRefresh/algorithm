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
