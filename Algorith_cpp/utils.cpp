//
//  utils.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/26.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "utils.hpp"
void exchange(int *a,int *b)
{
    int c = *a ^ *b;
    *b = *b ^ c ;
    *a = *a ^ c;
}
void transferDoubleList(DoubleList *l)
{
    while (l != NULL) {
        cout << l->val <<",";
        l = l->next;
    }
}

void transferList(ListNode *l)
{
    while (l != NULL) {
        cout << l->val <<",";
        l = l->next;
    }
    cout << endl;
}

void printRange(int *a, int begin, int end)
{
    for (int i = begin; i <= end; i++) {
        if (i == end) {
            cout << a[i] << endl ;
        }else{
            cout << a[i] << ",";
        }
    }
}

void printOut(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        cout<< a[i] << endl;
    }
}

int getArrayLength(int *arr)
{
    return sizeof(arr)/sizeof(arr[0]);
}

