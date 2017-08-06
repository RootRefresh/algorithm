//
//  Pet.hpp
//  Algorith_cpp
//
//  Created by USER on 2017/8/3.
//  Copyright © 2017年 com.lottery.www. All rights reserved.
//

#ifndef Pet_hpp
#define Pet_hpp

#include <stdio.h>

#include <string>

using namespace std;

class Pet{
    
private:
    string type;
    
public:
    Pet();
    Pet(string type);
    string getPet();
    
};


#endif /* Pet_hpp */
