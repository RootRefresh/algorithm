//
//  NQueen.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/27.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "NQueen.hpp"
#include "utils.hpp"
void trans(vector<int> r)
{
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << ",";
    }
    cout << endl;
}
bool isValid(vector<int> record, int i, int j)
{
//    trans(record);
    for (int k = 0; k < i; k++) {
        if (j == record[k] || abs(j-record[k]) == abs(i-k)) {
            return false;
        }
    }
    return true;
}

int process1(int i, vector<int>record, int n)
{
    if (i == n) {
        return 1;
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        if (isValid(record, i, j)) {
            record[i] = j;
            res += process1(i+1, record, n);

//            trans(record);
//            cout << "放置位置："<<i<< "-"<<j <<endl;
//            cout << "放置方式："<<res <<endl;
        }
    }
    return res;
}

int nqueen(int n)
{
    if (n < 1) {
        return 0;
    }
    vector<int> record(n);
    return process1(0, record, n);
}
