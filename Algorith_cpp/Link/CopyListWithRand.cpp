//
//  CopyListWithRand.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/2.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "CopyListWithRand.hpp"

RandList *copyListWithRand(RandList *head)
{
    RandList *cur = head;
    RandList *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = new RandList(cur->val);
        cur->next->next = next;
        cur = next;
    }
    
    cur = head;
    while (cur != NULL) {
        cur->next->rand = cur->rand->next;
        cur = cur ->next->next;
    }
    cur = head;
    RandList *tmp =head->next;
    RandList *copy = head->next;
    while (cur != NULL) {
        next = cur->next->next;
        tmp->next = next->next;
        cur->next = next;
        cur = next;
        tmp = next->next;
    }
    return copy;
}
