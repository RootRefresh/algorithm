//
//  LongestSubString.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/5/22.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "LongestSubString.hpp"

vector<vector<int> > dp_list(string s1, string s2)
{
    vector<vector<int> >  dp(s1.length());
    for (int i = 0; i < s1.length(); i++) {
        dp[i].resize(s2.length());
    }

    dp[0][0] = s1[0] == s2[0] ? 1:0;
    for (int j = 1; j < s1.length(); j++) {
        dp[j][0] = max(dp[j-1][0],s1[j] == s2[0] ? 1:0);
    }
    for (int k = 1; k < s2.length(); k++) {
        dp[0][k] = max(dp[0][k-1],s1[0] == s2[k] ? 1:0);
    }
    for (int i = 1; i < s1.length(); i++) {
        for (int j = 1; j < s2.length(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
            }
        }
    }
    
    return dp;
}

string lcse(string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0) {
        return "";
    }
    vector<vector<int> > dp = dp_list(s1, s2);
    int m = (int)(s1.length()-1);
    int n = (int)(s2.length()-1);
    string res (dp[m][n], ' ');
    cout <<"ssss" << res<< endl;
    int index = dp[m][n]-1;
    while (index >= 0) {
        if (m > 0 && dp[m-1][n] == dp[m][n]) {
            m--;
        }else if (n > 0 && dp[m][n-1] == dp[m][n]) {
            n--;
        } else{
         
            res.replace(index--, 1, s1.substr(m,1));
            cout<<res<<endl;
            m--;
            n--;
           
        }
    }
    return res;
}
