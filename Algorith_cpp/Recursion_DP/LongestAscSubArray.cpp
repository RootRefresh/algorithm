//
//  LongestAscSubArray.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/21.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "LongestAscSubArray.hpp"
#include <math.h>
vector<int> dp_list(vector<int> &arr)
{
    vector<int> dp(arr.size(),0);
    
    for (int i = 0; i < arr.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

vector<int> getList(vector<int> &arr, vector<int> &dp)
{
    int len = 0;
    int index = 0;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] > len) {
            len   = dp[i];
            index = i;
        }
    }
    vector<int> tmp(len, 0);
    tmp[--len] = arr[index];

    for (int j = index; j >= 0; j--) {
        if (arr[j] < arr[index] && dp[j] == dp[index]-1) {
            tmp[--len] = arr[j];
            index  = j;
        }
    }
    return tmp;
}

vector<int> dp_list2(vector<int> &arr)
{
    vector<int> dp(arr.size(), 0);
    vector<int> end(arr.size(), 0);
    end[0] = arr[0];
    dp[0]  = 1;

    int right = 0;
    int L = 0;
    int M = 0;
    int R = 0;
    
    for (int i = 1; i < arr.size(); i++) {
        L = 0;
        R = right;
        while (L <= R) {
            M = (L+R)/2;
            if (arr[i] > end[M]) {
                L = M + 1;
            }else{
                R = M - 1;
            }
        }
        right  = max(right, L);
        end[L] = arr[i];
        dp[i]  = L + 1;
    }
    return dp;
}

vector<int> longestList(vector<int> &arr)
{
    if (arr.size() == 0) {
        return arr;
    }
    vector<int> dp = dp_list2(arr);
    return getList(arr, dp);
}
