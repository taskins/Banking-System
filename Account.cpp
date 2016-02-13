//
//  Account.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include "Account.h"



istream& operator>>(istream &instream, Account &client)
{
    instream >> client.lastName >> client.firstName >> client.iD;
    return instream;
}

ostream& operator<<(ostream &ostream, Account &client)
{
    ostream << client.firstName << " " << client.lastName << " Account ID: " << client.iD << "\n";
    for (int i = 0; i < 10; i++)
    {
        ostream << "\t" << client.tenFunds[i] << "\n";
    }
    return ostream;
}

Account::Account() :Account("", "", 0)
{
}

Account::Account(string last, string first, int iD)
{
    firstName = first;
    lastName = last;
    this->iD = iD;
    tenFunds[0].setFundName("Money Market");
    tenFunds[1].setFundName("Prime Money Market");
    tenFunds[2].setFundName("Long-Term Bond");
    tenFunds[3].setFundName("Short-Term Bond");
    tenFunds[4].setFundName("500 Index Fund");
    tenFunds[5].setFundName("Capital Value Fund");
    tenFunds[6].setFundName("Growth Equity Fund");
    tenFunds[7].setFundName("Growth Index Fund");
    tenFunds[8].setFundName("Value Fund");
    tenFunds[9].setFundName("Value Stock Index");
}
const int Account::getID()
{
    return iD;
}

void Account::setFirstName(string first)
{
    firstName = first;
}

void Account::setLastName(string last)
{
    lastName = last;
}

void Account::setID(int accountNum)
{
    iD = accountNum;
}

void Account::depositFunds(Transaction *t)
{
    int fundID;
    if (t->getSecondAccountID() == -1)
    {
        fundID = t->getAccountID() % 10;
    }
    else
    {
        fundID = t->getSecondAccountID() % 10;
    }
    int fundAmount = tenFunds[fundID].getAmount();
    int depositAmount = t->getCash();
    tenFunds[fundID].setAmount(fundAmount + depositAmount);
    tenFunds[fundID].addHistory(t);
}
void Account::withdrawFunds(Transaction *t)
{
    int fundID = t->getAccountID() % 10;
    int fundAmount = tenFunds[fundID].getAmount();
    int withdrawlAmount = t->getCash();
    
    if ((fundAmount - withdrawlAmount) >= 0)
    {
        tenFunds[fundID].setAmount((fundAmount - withdrawlAmount));
    }
    else
    {
        int differenceAmount = fundAmount - withdrawlAmount;
        if ((fundID == 0 || fundID == 2) &&
            (tenFunds[fundID + 1].getAmount() + differenceAmount >= 0))
        {
            tenFunds[fundID + 1].setAmount(tenFunds[fundID + 1].getAmount() + differenceAmount);//change the transaction amount -(diff)
            t->setCash(-differenceAmount);
            t->setAccountID(t->getAccountID() + 1);
            tenFunds[fundID + 1].addHistory(t);
            
            t->setAccountID(t->getAccountID() - 1);
            tenFunds[fundID].setAmount(0);
            t->setCash(fundAmount);
        }

        else if ((fundID == 1 || fundID == 3) &&
                 (tenFunds[fundID - 1].getAmount() + differenceAmount >= 0))
        {
            tenFunds[fundID - 1].setAmount(tenFunds[fundID - 1].getAmount() + differenceAmount);
            t->setCash(-differenceAmount);
            t->setAccountID(t->getAccountID() - 1);
            tenFunds[fundID - 1].addHistory(t);
            
            t->setAccountID(t->getAccountID() + 1);
            tenFunds[fundID].setAmount(0);
            t->setCash(fundAmount);
        }
        else
        {
            t->setSuccess(false);
            cerr << "ERROR: Not enough funds to withdraw " << withdrawlAmount << " from " << firstName << " " << lastName << " " << tenFunds[fundID].getName() << ".\n";
        }
    }
    tenFunds[fundID].addHistory(t);
}

void Account::displayAccount(Transaction *t)
{
    cout << "Transaction History for " << firstName << " " << lastName << " by fund.\n";
    for (int i = 0; i < 10; i++)
    {
        if (tenFunds[i].hasHistory())
        {
            cout << tenFunds[i].getName() << ": $" << tenFunds[i].getAmount() << "\n";
            tenFunds[i].displayHistory();
        }
    }
}
void Account::displayFund(Transaction *t)
{
    int fundID = t->getAccountID() % 10;
    cout << "Transaction History for " << firstName << " " << lastName << " " << tenFunds[fundID].getName() << ": $" << tenFunds[fundID].getAmount() << "\n";
    tenFunds[fundID].displayHistory();
}

Account::~Account()
{
}

