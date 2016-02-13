//
//  Funds.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include "Funds.h"

//#include "stdafx.h"

ostream& operator<<(ostream &ostream, Funds &fund)
{
    ostream << fund.nameOfFund << ": $" << fund.amount;
    return ostream;
}

Funds::Funds()
{
    amount = 0;
}
bool Funds::hasHistory()
{
    return history.size() != 0;
}
int Funds::getAmount()
{
    return amount;
}

string Funds::getName()
{
    return nameOfFund;
}

void Funds::setAmount(int newAmount)
{
    amount = newAmount;
}

void Funds::setFundName(string newName)
{
    nameOfFund = newName;
}

void Funds::addHistory(Transaction *t)
{
    history.push_back(*t);
}

void Funds::displayHistory()
{
    for (int i = 0; i < history.size(); i++)
    {
        cout << "  " << history.at(i) << "\n";
    }
}
Funds::~Funds()
{
}

