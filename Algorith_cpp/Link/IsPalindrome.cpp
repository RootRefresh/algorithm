//
//  IsPalindrome.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/2.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "IsPalindrome.hpp"
#include <stack>
//最简单方法：全部入栈，依次出栈比较
bool isPalindrome1(ListNode *head)
{
    stack<int> myStack;
    ListNode *cur = head;
    while (cur != NULL) {
        myStack.push(cur->val);
        cur=cur->next;
    }
    cur = head;
    while (!myStack.empty()) {
        if (cur->val != myStack.top()) {
            return false;
        }else{
            myStack.pop();
            cur = cur->next;
        }
    }
    return true;
}

//一半入栈， 依次出栈比较
bool isPalindrome2(ListNode *head)
{
    if (head == NULL) {
        return false;
    }
    stack<int> s;
    ListNode *cur = head;
    ListNode *right = head->next;
    
    while (cur->next != NULL && cur->next->next != NULL) {
        right = right->next;
        cur   = cur->next->next;
    }
    while (right != NULL) {
        s.push(right->val);
        right = right->next;
    }
    cur = head;
    while (!s.empty()) {
        if (s.top() != cur->val) {
            return false;
        }
        s.pop();
        cur = cur->next;
    }
    return true;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL) {
        return false;
    }
    bool res = true;
    ListNode *mid   = NULL;
    ListNode *left  = head;
    ListNode *right = head;
    ListNode *cur = head;
    
    while (cur->next != NULL && cur->next->next != NULL) {
        cur   = cur->next->next;
        right = right->next;
    }
    mid  = right;
    left  = right;
    right = right->next;
    while (cur != NULL) {
        cur = right->next;
        right->next = left;
        
        left = right;
        right = cur;
    }
    cur   = left;
    right = left;
    left  = head;
    
    while (left != mid) {
        if (left->val != cur->val) {
            res = false;
            break;
        }
        left = left->next;
        cur  = cur->next;
    }
    
    //复原右半边
    cur = NULL;;
    while (right != mid) {
       
        left = right->next;
        right->next = cur;
        
        cur = right;
        right = left;
    }
    right->next = cur;
    
    transferList(head);
    return res;
}

