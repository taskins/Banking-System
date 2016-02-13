//
//  Account.h
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#ifndef __lab5__Account__
#define __lab5__Account__

#include <stdio.h>

#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Funds.h"

using namespace std;

class Account
{
    friend istream& operator>>(istream &instream, Account &client);
    friend ostream& operator<<(ostream &onstream, Account &client);
public:
    Account();
    //Account(const Account&);
    Account(string last, string first, int);
    ~Account();
    const string getFirstName();
    const string getLastName();
    const int getID();
    
    void setFirstName(string);
    void setLastName(string);
    void setID(int);
    
    void depositFunds(Transaction *);
    void withdrawFunds(Transaction *);
    void displayAccount(Transaction *);
    void displayFund(Transaction *);
    
    Account& operator=(const Account &);
    bool operator!=(const Account &)const;
    bool operator==(const Account &)const;
private:
    string firstName, lastName;
    int iD;
    Funds tenFunds[10];
    
    //void clear();
    //void copy(const Account &);
};


#endif /* defined(__lab5__Account__) */
