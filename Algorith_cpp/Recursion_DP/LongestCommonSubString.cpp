//
//  LongestCommonSubString.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/27.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "LongestCommonSubString.hpp"
vector<vector<int>> getdp(string str1, string str2)
{
    vector<vector<int>> dp(str1.length());
    for (int i=0; i < str1.length(); i++) {
        dp[i].resize(str2.length());
    }
    
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[0]) {
            dp[i][0] = 1;
        }
    }
    for (int j = 1; j < str2.length(); j++) {
        if (str1[0] == str2[j]) {
            dp[0][j] = 1;
        }
    }
    for (int i = 1; i < str1.length(); i++) {
        for (int j = 1; j<str2.length(); j++) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }
    return dp;
}

string lcst1(string str1, string str2)
{
    if (str1.empty() || str1.length()==0 || str2.length()==0) {
        return "";
    }
    int end = 0;
    int max = 0;
    vector<vector<int>> dp = getdp(str1, str2);
    for (int i=0; i < str1.length(); i++) {
        for (int j = 0; j < str2.length(); j++) {
            if (dp[i][j] > max) {
                end = i;
                max = dp[i][j];
            }
        }
    }
    return str1.substr(end-max+1,max);
}

