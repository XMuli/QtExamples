//
//  main.cpp
//  test
//
//  Created by muli on 2020/3/2.
//  Copyright © 2020 muli. All rights reserved.
//

#include <iostream>
using namespace std;
#include "ExHeader.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    double a = 12;
    double b = 2;
    
    double valAdd = add(a, b);
    double valSub = sub(a, b);
    double valMul = mul(a, b);
    double valDiv = div(a, b);
    
    cout<<"[显示结果"
    <<"  a:"<<a
    <<"  b:"<<b
    <<"  ]\n"
    <<"  valAdd:"<<valAdd
    <<"  valSub:"<<valSub
    <<"  valMul:"<<valMul
    <<"  valDiv:"<<valDiv
    <<endl;
    
    return 0;
}
