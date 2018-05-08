//
//  CrossList.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/6.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "CrossList.hpp"

/* 一个链表有环则快慢指针定会相交，相交后重置快指针到头指针位置，然后同慢指针一起一步走再相等就是入环第一节点
   无环则快指针会走到终点 null
 */
ListNode* getLoopNode(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next == NULL) {
        return NULL;
    }
    
    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    
    while (fast != slow) {
        if (fast->next == NULL || fast->next->next == NULL) {
            return NULL;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
/*
     无环相交
     1、分别遍历连个链表，并记录长度和尾节点，若尾节点不同，则不相交
     2、链表1较长 则先走len1-len2 步；链表2较长，则先走len2-len1步。然后两链表一起走，当首次相遇的节点，就是第一个相交节点
 */
//原始
ListNode *noLoopCross(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    ListNode *n1 = h1;
    ListNode *n2 = h2;
    
    int len1 = 1, len2 = 1;
    
    while (n1->next != NULL) {
        n1 = n1->next;
        len1++;
    }
    while (n2->next != NULL) {
        n2 = n2->next;
        len2++;
    }
    if (n1 != n2) {
        return NULL;
    }
    n1 = h1;
    n2 = h2;
    int k = len1-len2;
    
    if (len1 > len2) {
        while (k-- > 0) {
            n1=n1->next;
        }
    }else if (len1 < len2){
        while (k-- > 0) {
            n2=n2->next;
        }
    }
    ListNode *res = NULL;
    while (n1->next != NULL) {
        if (n1 == n2 ) {
            res = n1;
            break;
        }
        n1=n1->next;
        n2=n2->next;
    }
    return  res;
}
//无环相交优化
ListNode *noLoop(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    ListNode *n1 = h1;
    ListNode *n2 = h2;
    int n = 0;//差几步
    while (n1->next != NULL) {
        n++;
        n1=n1->next;
    }
    while (n2->next != NULL) {
        n--;
        n2=n2->next;
    }
    n1 = n > 0 ? h1:h2;
    n2 = n1 == h1? h2:h1;
    n = abs(n);
    while (n != 0) {
        n1 = n1->next;
    }
    while (n1 != n2) {
        n1=n1->next;
        n2=n2->next;
    }
    return n1;
}

//原始 不满足条件
ListNode *loopCross(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    
    ListNode *has1 = getLoopNode(h1);
    ListNode *has2 = getLoopNode(h2);
 
    if (has1 != NULL && has2 != NULL) {
        
        if (has1 == has2) {
            return has1;
        }
        
        ListNode *tmp = has1;
        while (tmp != has1) {
            tmp = tmp->next;
            if (tmp == has2) {
                return tmp;
            }
        }
        
    }
    
    
    return NULL;
}
/*
     两带环链表找相交节点
     1、入环节点相同，则方法同无环链表找相交节点
     2、入环节点不同，选择一个链表入环节点，循环递进，看是否遇到另一链表的入环节点
 */
ListNode *bothLoop(ListNode *h1, ListNode *loop1, ListNode *h2, ListNode *loop2)
{
    ListNode *cur1 = NULL;
    ListNode *cur2 = NULL;
    if (loop1 == loop2) {
        cur1 = h1;
        cur2 = h2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop1) {
            n--;
            cur2 = cur2->next;
        }
        n = abs(n);
        cur1 = n>0 ? h1:h2;
        cur2 = cur1 = h1?h2:h1;
        while (n != 0) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
        
    }else{
        cur1 = loop1->next;
        while (cur1 != loop1) {
            if (cur1 == loop2) {
                return cur1;
            }
            cur1=cur1->next;
        }
    }
    return cur1;
}

//整个题目主方法
ListNode *getIntersectNode(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    ListNode *loop1 = getLoopNode(h1);
    ListNode *loop2 = getLoopNode(h2);
    if (loop1 == NULL && loop2 == NULL) {
        noLoop(h1, h2);
    }
    if (loop1 != NULL && loop2 != NULL) {
        bothLoop(h1, loop1, h2, loop2);
    }
    return NULL;
}
