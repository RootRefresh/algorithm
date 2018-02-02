//
//  main.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/7/8.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include <iostream>

#include "MinStack.hpp"

#include "TwoStackQueue.hpp"

#include "ReverseStackByRecursion.hpp"

#include "utils.hpp"
#include "InsertSort.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "QuickSort.hpp"
#include "TwoStackSort.hpp"
#include "MaxWindow.hpp"
#include "SortedListPublicNode.hpp"
#include "removeListNodeLastK.hpp"
#include "removeMidNode.hpp"
#include "RemoveByRatio.hpp"
#include "ReverseList.hpp"
#include "JosephusKillOne.hpp"
#include "IsPalindrome.hpp"
using namespace std;

void test_1_0_2()
{
    cout << "1.0.2" << endl;
    cout << "1.0.3" << endl;
    cout << "1.0.4" << endl;


}

int main(int argc, const char * argv[]) {
  
    int arr2[] = {3,6,2,8,5,4};
//    insertSort(arr2, 6);
//    mergeSort(arr2, 0, 5);
//    heapSort(arr2, 6);
//    quickSort(arr2, 0, 5);
    
//    twoStackSort(arr2, 6);
//    int *tmpArr = getMaxWindow(arr2, 6, 2);
//    printOut(tmpArr , 5);
    
//链表
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;
    
    ListNode *ll5 = new ListNode(3);
    ListNode *ll6 = new ListNode(4);
    ll5->next = ll6;
    ll6->next = NULL;
    
    ListNode *l7 = NULL;

    //    printPublicNode(l1, l7);
//    ListNode *res = removeLastK(l1, 2);
//    ListNode *res = removeMidNode(l1);
//    ListNode *res = removeByRatio(l1, 3, 5);

//    ListNode *res = reverseList(ll5);
//    ListNode *res = bestReverseList(ll5);
//    ListNode *res = reverseSubList(l1, 2, 5);
//    ListNode *res = josephusKill(l1, 3);
//    transferList(res);
    cout << isPalindrome(l1) << endl;

    DoubleList *d1 = new DoubleList(1);
    DoubleList *d2 = new DoubleList(2);
    DoubleList *d3 = new DoubleList(3);
    DoubleList *d4 = new DoubleList(4);

    d1->next = d2;
    d1->pre  = NULL;
    d2->next = d3;
    d2->pre  = d1;
    d3->next = d4;
    d3->pre  = d2;
    d4->next = NULL;
    d4->pre  = d3;
    
//    DoubleList *dres = removeKthNode(d1, 2);
    DoubleList *dres = reverseDoubleList(d1);
//    transferDoubleList(dres);
    
//    int arr[] = {1,2,3};
    //最小值栈
//    MinStack s;
//    
//    for (int i = 0; i< 4; i++) {
//        s.push(arr[i]);
//    }
//    while (!s.empty()) {
//        
//        cout << s.getMin() << endl;
//        s.pop();
//    }
    
    //两个栈模拟队列
//    TwoStackQueue queue;
//    
//    for (int i = 0; i< 4; i++) {
//        queue.add(arr[i]);
//    }
//    
//
//    for (int i = 0; i< 4; i++) {
//        cout << queue.peek() << endl;
//       
//        if (i==2) {
//            queue.add(8);
//        }
//
//        cout << queue.poll() << endl;
//
//    }
//    cout << queue.poll() << endl;

    
//    ReverseStack rStack;
//
//    for (int i = 0; i< 3; i++) {
//        rStack.push(arr[i]);
//    }
//    rStack.traversal();

//    rStack.reverse();
//
//    rStack.traversal();


    return 0;
}
