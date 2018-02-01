//
//  SortedListPublicNode.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/1.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "SortedListPublicNode.hpp"
void printPublicNode(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL) {
        return;
    }
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            l1 = l1->next;
        }else if(l1->val > l2->val){
            l2 = l2->next;
        }else{
            cout << l1->val << ",";
            l1 = l1->next;
            l2 = l2->next;
        }
    }
}
