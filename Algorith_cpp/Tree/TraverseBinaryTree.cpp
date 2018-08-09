//
//  TraverseBinaryTree.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/14.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "TraverseBinaryTree.hpp"
#include <stack>
#include "utils.hpp"

//判断二叉树是否为平衡二叉树
//根据后续数组重建搜索二叉树
//判读二叉树是否为搜索二叉树和完全二叉树 P147
//通过有序数组生成平衡搜索树
//在二叉树中找到两个节点的公共祖先
//通过先序和中序数组生成后序数组       P173

//层序遍历 P131


//树1包含树2拓扑结构
bool check(Tree *h, Tree *t2)
{
    if (t2 == NULL) {
        return true;
    }
    if (h == NULL || h->val != t2->val) {
        return false;
    }
    
    return check(h->left, t2->left) &&check(h->right, t2->right);
}

bool contain(Tree *t1, Tree *t2)
{
    return check(t1, t2) || contain(t1->left, t2) || contain(t1->right, t2);
}

//根据后续数组重建搜索二叉树
//1、数组是否是搜索二叉树后序遍历结果
bool isPost(int *arr, int start, int end)
{
    if (start == end) {
        return true;
    }
    
    int less = -1;
    int more = end;
    for (int i = start; i < end; i++) {
        if (arr[end] > arr[i]) {
            less = i;
        }else{
            more = more == end ? i : more;
        }
    }
    if (less == -1 || more == end) {
        return isPost(arr,start,end-1);
    }
    if (less != more-1) {
        return false;
    }
    return isPost(arr, start, less) && isPost(arr, more, end - 1);
}

bool isPostArray(int *a, int n)
{
    if (a == NULL || n == 0) {
        return false;
    }
    return isPost(a, 0, n-1);
}
//2、数组无重复值，是搜索二叉树后序遍历结果，重构二叉树
Tree *posToBST(int *posArr, int start, int end)
{
    if (start > end) {
        return NULL;
    }
    
    Tree *root = new Tree(posArr[end]);
    int less = -1;
    int more = end;
    
    for (int i = start; i < end; i++) {
        if (posArr[end] > posArr[i]) {
            less = i;
        }else{
            more = more == end? i: more;
        }
    }
    
    root->left = posToBST(posArr, start, less);
    root->right= posToBST(posArr, more, end - 1);
    return root;
}

Tree *posArrayToBST(int *a, int n)
{
    if (a == NULL) {
        return NULL;
    }
    return posToBST(a, 0, n-1);
}

//判断是否平衡二叉树
int getHeight(Tree *root, int level, vector<bool> &res)
{
    if (root == NULL) {
        return level;
    }
    int lH = getHeight(root->left, level+1, res);
    if (!res[0]) {
        return level;
    }
    int rH = getHeight(root->right, level+1, res);
    if (!res[0]) {
        return level;
    }
    if (abs(lH - rH) > 1) {
        res[0] = false;
    }
    return max(lH, rH);
    
}
bool isBanlance(Tree *root)
{
    vector<bool> res(1);
    res[0] = true;
    getHeight(root, 1, res);
    return res[0];
}

//有序数组生成平衡搜索树
Tree *generateSub(int *arr, int start, int end)
{
    if (start > end) {
        return NULL;
    }
    
    int mid = (start + end )/2;
    Tree *root = new Tree(arr[mid]);
    root->left = generateSub(arr, start, mid-1);
    root->right = generateSub(arr, mid+1, end);
    return root;
}

Tree *generateTree(int *arr, int n)
{
    if (arr == NULL) {
        return NULL;
    }
    return generateSub(arr, 0, n-1);
}


//找到一个节点的后继节点
Tree *getLeftMost(Tree *root)
{
    if (root == NULL) {
        return root;
    }
    
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Tree *getNextNode(Tree *root)
{
    if (root == NULL) {
        return root;
    }
    
    if (root->right != NULL) {
        return getLeftMost(root->right);
    }else{
        Tree *parent = root->parent;
        while (parent != NULL && parent->left != root) {
            root = parent;
            parent = root->parent;
        }
        return parent;
    }
}



//最近公共祖先
Tree * lowestAncestor(Tree *root, Tree *r1, Tree *r2)
{
    if (root == NULL || root == r1 || root == r2) {
        return root;
    }
    
    Tree *left  = lowestAncestor(root->left, r1, r2);
    Tree *right = lowestAncestor(root->right, r1, r2);
    if (left != NULL && right != NULL) {
        return root;
    }
    
    return left != NULL ? left:right;
}


//二叉树节点最大距离
int posOrder(Tree *root, vector<int> &vec)
{
    if (root == NULL) {
        vec[0] = 0;
        return 0;
    }
    
    int lMax = posOrder(root->left, vec);
    int maxfromLeft = vec[0];
    int rMax = posOrder(root->right, vec);
    int maxFromRight = vec[0];
    
    int curMax = maxfromLeft + maxFromRight + 1;
    vec[0] = max(maxfromLeft, maxFromRight) + 1;
    
    return max(max(lMax, rMax), curMax);
}

int maxDistance(Tree *root)
{
    vector<int> vec(1);
    return posOrder(root, vec);
}


//统计和生成所有不同的二叉树
int numTrees(int n)
{
    if (n < 2) {
        return 1;
    }
    
    vector<int > vec(n+1);
    vec[0] = 1;
    
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < i+1; j++) {
            vec[i] += vec[j-1] *vec[i - j];
        }
    }
    
    return vec[n];
}

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
//        cout << cur->val << endl;
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

