//
//  ConvertSearchTreeToDoubleList.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/10.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "ConvertSearchTreeToDoubleList.hpp"
#include <queue>

void inOrderToQueue(Tree *root, queue<Tree *> q)
{
    if (root == NULL) {
        return;
    }
    
    inOrderToQueue(root->left, q);
    q.push(root);
    inOrderToQueue(root->right, q);
}

Tree * convert1(Tree *root)
{
    queue<Tree *> q;
    inOrderToQueue(root, q);
    root = q.front();
    q.pop();
    Tree *pre = root;
    pre->left = NULL;
    Tree *cur = NULL;
    
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        pre->right = cur;
        cur->left = pre;
        pre = cur;
    }
    pre->right = NULL;
    return root;
}


