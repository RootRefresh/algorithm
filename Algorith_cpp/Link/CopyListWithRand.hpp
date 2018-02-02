//
//  CopyListWithRand.hpp
//  Algorith_cpp
//
//  Created by 丰华财经 on 2018/2/2.
//  Copyright © 2018年 com.lottery.www. All rights reserved.
//

#ifndef CopyListWithRand_hpp
#define CopyListWithRand_hpp

#include <stdio.h>

typedef struct RandList
{
    int val;
    RandList *next;
    RandList *rand;
    RandList(int x):val(x),next(NULL),rand(NULL){}
    
}RandList;

RandList *copyListWithRand(RandList *head);

#endif /* CopyListWithRand_hpp */
