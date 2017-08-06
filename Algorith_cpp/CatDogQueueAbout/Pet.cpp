//
//  Pet.cpp
//  Algorith_cpp
//
//  Created by USER on 2017/8/3.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#include "Pet.hpp"
Pet::Pet()
{
    
}
Pet::Pet(string type)
{
    this->type = type;
}

string Pet::getPet()
{
    return this->type;
}

