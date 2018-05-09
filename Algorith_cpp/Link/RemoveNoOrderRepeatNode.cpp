//
//  RemoveNoOrderRepeatNode.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/9.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "RemoveNoOrderRepeatNode.hpp"
#include <set>

void removeRep1(ListNode *head)
{
    if (head == NULL) {
        return;
    }
    set<ListNode *> mHash;
    ListNode *pre = head;
    ListNode *cur = head->next;
    mHash.insert(pre);
    while (cur != NULL) {
        if (mHash.find(cur) == mHash.end()) {
            mHash.insert(cur);
            pre = cur;
        }else{
            pre->next=cur->next;
        }
        cur = cur->next;
    }
}

void removeRep2(ListNode *head)
{
    if (head == NULL) {
        return;
    }
    
    ListNode *start = head;
    ListNode *pre = NULL;
    ListNode *cur = NULL;
    while (start != NULL) {
        pre = start;
        cur = start->next;
        while (cur != NULL) {
            if (cur->val == start->val) {
                pre->next = cur->next;
            }else{
                pre = cur;
            }
            cur = cur->next;
        }
        start = start->next;
    }

}

