//
//  utils.hpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/1/26.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct DoubleList{
    int val;
    DoubleList *pre;
    DoubleList *next;
    DoubleList(int x):val(x),pre(NULL),next(NULL){}
}DoubleList;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
}ListNode;

typedef struct Tree {
    int val;
    Tree *left;
    Tree *right;
    Tree *parent;

    Tree(int x):val(x),left(NULL),right(NULL),parent(NULL){}
}Tree;

void transferDoubleList(DoubleList *l);
void transferList(ListNode *l);
void exchange(int *a,int *b);
void printRange(int *a, int begin, int end);
void printOut(int *a, int n);
int getArrayLength(int *arr);
#endif /* utils_hpp */
