//
//  Transaction.h
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#ifndef __lab5__Transaction__
#define __lab5__Transaction__

#include <stdio.h>

#pragma once
#include <iostream>

using namespace std;

class Transaction
{
    friend istream& operator>>(istream &instream, Transaction &trans);
    friend ostream& operator<<(ostream &ostream, Transaction &trans);
    
public:
    Transaction();
    //For Tranaction Open
    Transaction(char, string, string, int);
    //For Tranaction History
    Transaction(char, int);
    //For Tranaction Deposit/Withdraw
    Transaction(char, int, int);
    //For Tranaction Transfer
    Transaction(char, int, int, int);
    
    ~Transaction();
    
    string getFirstName();
    string getLastName();
    int getAccountID();
    int getSecondAccountID();
    int getCash();
    char getTypeTrans();
    bool getSuccess();
    
    void setFirstName(string);
    void setLastName(string);
    void setAccountID(int);
    void setSecondAccountID(int);
    void setCash(int);
    void setTypeTrans(char);
    void setSuccess(bool);
    
private:
    string firstName, lastName;
    char typeOfTrans;
    int accountID, secondAccountID;
    int cash;
    bool success;
};



#endif /* defined(__lab5__Transaction__) */
