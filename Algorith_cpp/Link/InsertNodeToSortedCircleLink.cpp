//
//  InsertNodeToSortedCircleLink.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/11.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "InsertNodeToSortedCircleLink.hpp"

/*
     1、插入链表为空，则新节点为唯一节点，next指针指向自己，构成循环链表，返回自己
     2、新插入点 大于/小于 链表中所有节点，则插入到尾部，与当前首节点相连，如果小于所有节点，则将head指针
         指向新节点，返回head
     3、循环遍历，找到大于新节点值的第一个点，将该节点的前一节点指向新节点，新节点与该节点相连，完成插入
*/

ListNode *insert(ListNode *head,  int num)
{
    ListNode *node = new ListNode(num);
    if (head == NULL) {
        node ->next = node;
        return node;
    }
    ListNode *pre = head;
    ListNode *cur = head->next;
    //小于等于 所有节点中最小节点的情况
//    if (num <= head->val) {
//        while (cur != head) {
//            pre = cur;
//            cur = cur->next;
//        }
//        pre->next = node;
//        node->next = cur;
//        return node;
//    }
    //常规插入
    while (cur != head) {
        if (cur->val >= num && pre->val <= num) {
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    
    //大于等于所有节点中最大节点的情况
//    if (pre->next == head && num >= pre->val) {
//        pre->next = node;
//        node->next = cur;
//    }
    //优化 最终都是插入到pre cur之间，无论常规还是插入尾部
    pre->next  = node;
    node->next = cur;
    
    return head->val > num ? node:head;
}
