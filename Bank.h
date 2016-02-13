//
//  Bank.h
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#ifndef __lab5__Bank__
#define __lab5__Bank__

#include <stdio.h>

#pragma once
#include <string>
#include <queue>
#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "Transaction.h"
using namespace std;
class Bank
{
public:
    Bank();
    ~Bank();
    bool ReadFile(const string&);
    void ExecuteTransaction();
    void Display();
    
    
private:
    queue<Transaction> transactions;
    void chooseTransaction(Transaction *);
    
    BSTree *clients;
    
    void OpenAccount(Transaction *);
    void Deposit(Transaction *);
    void Withdraw(Transaction *);
    void Transfer(Transaction *);
    void History(Transaction *);
    
    
    bool checkID(int, int, int);
};



#endif /* defined(__lab5__Bank__) */
