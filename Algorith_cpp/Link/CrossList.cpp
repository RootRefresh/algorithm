//
//  CrossList.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/6.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "CrossList.hpp"

ListNode* hasCircle(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return fast;
        }
    }
    return NULL;
}

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

ListNode *loopCross(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    
    ListNode *has1 = hasCircle(h1);
    ListNode *has2 = hasCircle(h2);
 
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

