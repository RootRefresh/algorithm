//
//  ArrayLongestSequence.cpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/6/27.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#include "ArrayLongestSequence.hpp"
#include "map"
void transMap(map<int,int> m)
{
    map<int,int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout<<iter->first<<":"<<iter->second<<endl;
    }
}

int mergeArr(map<int,int> &hashMap, int less, int more)
{
    
    int l  = less-hashMap[less] + 1;
    int r  = more+hashMap[more] - 1;
    int len = r-l+1;
    cout<<"begin：";
    transMap(hashMap);
    hashMap[less] = len;
    hashMap[more] = len;
    cout<<"end：";
    transMap(hashMap);

    return len;
}

int longestLength(vector<int> arr)
{
    if (arr.empty()) {
        return 0;
    }
    int kMax = 1;
    map<int, int> hashMap;

    for (int i = 0; i < arr.size(); i++) {
        if (hashMap.find(arr[i]) == hashMap.end()) {
            hashMap[arr[i]] = 1;
            if (hashMap.find(arr[i]-1) != hashMap.end()) {
                kMax = max(kMax, mergeArr(hashMap, arr[i]-1, arr[i]));
            }
            
            if (hashMap.find(arr[i]+1) != hashMap.end()) {
                kMax = max(kMax, mergeArr(hashMap, arr[i], arr[i]+1));
            }
        }
    }
    return kMax ;
}
