//
//  Transaction.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include "Transaction.h"



istream& operator>>(istream &instream, Transaction &trans)
{
    
    instream >> trans.typeOfTrans;
    
    if (trans.typeOfTrans == 'O')
    {
        instream >> trans.lastName >> trans.firstName >> trans.accountID;
    }
    else if (trans.typeOfTrans == 'W' || trans.typeOfTrans == 'D')
    {
        instream >> trans.accountID >> trans.cash;
    }
    else if (trans.typeOfTrans == 'H')
    {
        instream >> trans.accountID;
    }
    else if (trans.typeOfTrans == 'T')
    {
        instream >> trans.accountID >> trans.cash >> trans.secondAccountID;
    }
    return instream;
}
ostream& operator<<(ostream &ostream, Transaction &trans)
{
    if (trans.typeOfTrans == 'D' || trans.typeOfTrans == 'W')
    {
        ostream << trans.typeOfTrans << " " << trans.accountID << " " << trans.cash;
    }
    else if (trans.typeOfTrans == 'T')
    {
        ostream << trans.typeOfTrans << " " << trans.accountID << " " << trans.cash << " " << trans.secondAccountID;
    }
    else  //(trans.getSuccess() == false)
    {
        ostream << " (Failed)";
    }
   
    return ostream;
}
Transaction::Transaction()
{
    secondAccountID = -1;
}
string Transaction::getFirstName()
{
    return firstName;
}
string Transaction::getLastName()
{
    return lastName;
}
int Transaction::getAccountID()
{
    return accountID;
}
int Transaction::getSecondAccountID()
{
    return secondAccountID;
}
int Transaction::getCash()
{
    return cash;
}
char Transaction::getTypeTrans()
{
    return typeOfTrans;
}
bool Transaction::getSuccess()
{
    return success;
}
void Transaction::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}
void Transaction::setLastName(string newLastName)
{
    lastName = newLastName;
}
void Transaction::setAccountID(int newID)
{
    accountID = newID;
}
void Transaction::setSecondAccountID(int newSecondID)
{
    secondAccountID = newSecondID;
}
void Transaction::setCash(int newAmount)
{
    cash = newAmount;
}
void Transaction::setTypeTrans(char newTransaction)
{
    typeOfTrans = newTransaction;
}
void Transaction::setSuccess(bool f)
{
    success = f;
}

Transaction::~Transaction()
{
}


