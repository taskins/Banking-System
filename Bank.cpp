//
//  Bank.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include "Bank.h"




Bank::Bank()
{
    clients = new BSTree();
}

Bank::~Bank()
{
}


//DONE
bool Bank::ReadFile(const string& fileName)
{
    string lines = "";
    fstream myFile;
    myFile.open(fileName);
    
    if (myFile.is_open())
    {
        while (getline(myFile, lines))
        {
            Transaction trans;
            stringstream(lines) >> trans;
            transactions.push(trans);
        }
        myFile.close();
        return true;
    }
    return false;
}

void Bank::ExecuteTransaction()
{
    while (!transactions.empty())
    {
        Transaction firstTrans = transactions.front();
        chooseTransaction(&firstTrans);
        transactions.pop();
    }
    
}

void Bank::Display()
{
    cout << "Processing Done. Final Balances\n";
    clients->Display();
}
void Bank::chooseTransaction(Transaction *t)
{
    if (t->getTypeTrans() == 'O')
    {
        OpenAccount(t);
    }
    else if (t->getTypeTrans() == 'D')
    {
        Deposit(t);
    }
    else if (t->getTypeTrans() == 'W')
    {
        Withdraw(t);
    }
    else if (t->getTypeTrans() == 'T')
    {
        Transfer(t);
    }
    else
    {
        History(t);
    }
}

//Done
void Bank::OpenAccount(Transaction *t)
{
    Account *first;
    int accountNum = t->getAccountID();
    if (checkID(accountNum, 1000, 9999))
    {
        if (!clients->Retrieve(accountNum, first))
        {
            first = new Account(t->getFirstName(), t->getLastName(), t->getAccountID());
            clients->Insert(first);
            
        }
        else
        {
            cerr << "ERROR:Account " << accountNum << " is already open. Transaction refused.\n";
        }
    }
    t->setSuccess(true);
}

void Bank::Deposit(Transaction *t)
{
    Account *first;
    int accountNum;
    if (checkID(t->getAccountID(), 10000, 99999))
    {
        accountNum = t->getAccountID() / 10;
        if (clients->Retrieve(accountNum, first))
        {
            first->depositFunds(t);
        }
        else
        {
            cerr << "ERROR: Account Not Found.\n";
        }
    }
    else
    {
        cerr << "ERROR: Wrong Account number.\n";
    }
     t->setSuccess(true);
}

void Bank::Withdraw(Transaction *t)
{
    Account *first;
    int accountNum;
    if (checkID(t->getAccountID(), 10000, 99999))
    {
        accountNum = t->getAccountID() / 10;
        if (clients->Retrieve(accountNum, first))
        {
            first->withdrawFunds(t);
        }
        else
        {
            cerr << "ERROR: Account Not Found. \n";
        }
    }
     t->setSuccess(true);
}

void Bank::Transfer(Transaction *t)
{
    Account *first, *second;
    int accountNum;
    int secondNum;
    if (checkID(t->getAccountID(), 10000, 99999) && checkID(t->getSecondAccountID(), 10000, 99999))
    {
        accountNum = t->getAccountID() / 10;
        secondNum = t->getSecondAccountID() / 10;
        if (clients->Retrieve(accountNum, first))
        {
            if (clients->Retrieve(secondNum, second))
            {
                first->withdrawFunds(t);
                second->depositFunds(t);
            }
            else
            {
                cerr << "ERROR: Account " << secondNum << " Not Found.\n";
            }
        }
        else
        {
            cerr << "ERROR: Account " << accountNum << " Not Found. \n";
        }
    }
     t->setSuccess(true);
    
}
void Bank::History(Transaction *t)
{
    Account *first;
    if (checkID(t->getAccountID(), 1000, 99999)){
        
        int accountOrFund = t->getAccountID() / 10000;
        int accountnum = t->getAccountID();
        if (accountOrFund == 1){
            accountnum = t->getAccountID() / 10;
            if (clients->Retrieve(accountnum, first))
            {
                first->displayFund(t);
            }
            else
            {
                cerr << "ERROR: Account " << accountnum << " Not Found. \n";
            }
        }
        else if (clients->Retrieve(accountnum, first))
        {
            first->displayAccount(t);
        }
        else
        {
            cerr << "ERROR: Account " << accountnum << " Not Found.\n";
        }
    }
    
     t->setSuccess(true);
}

bool Bank::checkID(int iD, int min, int max)
{
    if (min <= iD && iD <= max)
    {
        return true;
    }
    else
    {
        cerr << "ERROR: Invalid Account ID " << iD << ".\n";
        return false;
    }
}
