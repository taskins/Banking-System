//
//  Funds.h
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#ifndef __lab5__Funds__
#define __lab5__Funds__

#include <stdio.h>



#include <vector>
#include <string>
#include "Transaction.h"
using namespace std;
class Funds
{
    friend ostream& operator<<(ostream &ostream, Funds &client);
public:
    Funds();
    Funds(string);
    ~Funds();
    bool hasHistory();
    int getAmount();
    string getName();
    
    void setAmount(int);
    void setFundName(string);
    void addHistory(Transaction *);
    void displayHistory();
    
private:
    int amount;
    string nameOfFund;
    vector<Transaction> history;
};


#endif /* defined(__lab5__Funds__) */
