//
//  TraverseBinaryTree.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/14.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "TraverseBinaryTree.hpp"
#include <stack>
void preOrderTree(Tree *root)
{
    if (root == NULL ) {
        return;
    }
    printf("%d",root->val);
    preOrderTree(root->left);
    preOrderTree(root->right);
}

void inOrderTree(Tree *root)
{
    if (root == NULL ) {
        return;
    }
    inOrderTree(root->left);
    printf("%d",root->val);
    inOrderTree(root->right);
}

void afterOrderTree(Tree *root)
{
    if (root == NULL ) {
        return;
    }
    afterOrderTree(root->left);
    afterOrderTree(root->right);
    printf("%d",root->val);
}

void stackPreOrder(Tree *root)
{
    stack <Tree *> myStack;
    myStack.push(root);

    while (!myStack.empty()) {
        Tree *cur = myStack.top();
        myStack.pop();
        
        printf("%d",cur->val);
        
        if (cur->right != NULL) {
            myStack.push(cur->right);
        }
        if (cur->left != NULL) {
            myStack.push(cur->left);
        }
    }
}

void stackInOrder(Tree *root)
{
    stack <Tree *> myStack;
    Tree *cur = root;
    while (!myStack.empty() || cur != NULL) {
        if (cur != NULL) {
            myStack.push(cur);
            cur = cur->left;
        }else{
            Tree *node = myStack.top();
            myStack.pop();
            cur = node->right;
            printf("%d",node->val);
        }
    }
}

void stackAfterOrder(Tree *root)
{
    Tree *cur = NULL;
    Tree *out = NULL;
    stack<Tree *> s;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if (cur->left != NULL && out != cur->left && out != cur->right) {
            s.push(cur->left);
        }else if (cur->right != NULL && out != cur->right){
            s.push(cur->right);
        }else{
            out = s.top();
            printf("%d",out->val);
            s.pop();
        }
    }
}

