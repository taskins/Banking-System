//
//  main.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include <iostream>
#include "Bank.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Bank JollyBank ;
    
    JollyBank.ReadFile("/Users/selen/Desktop/css342/Assignment5/inputfile");  // file name e degismeli
    JollyBank.ExecuteTransaction();
    JollyBank.Display();

    return 0;
}
