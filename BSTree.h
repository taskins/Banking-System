//
//  BSTree.h
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#ifndef __lab5__BSTree__
#define __lab5__BSTree__

#include "Account.h"
#include <stdio.h>
#include <iostream>
#include <string>




using namespace std;

class BSTree
{
public:
    BSTree();
    BSTree(const BSTree &);
    ~BSTree();
    bool Insert(Account *);
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &, Account * &) const;
    // displays the contents of a tree to cout
    void Display() const;
    void Empty();
    bool isEmpty() const;
    
    BSTree& operator=(const BSTree&);
private:
    struct Node
    {
        Account *pAcct;
        Node *right;
        Node *left;
    };
    Node *root;
    
    void clear();
    void copy(const BSTree &);
    
    bool Insert(Node *, Node *);
    bool Retrieve(const Node *, const int &, Account * &) const;
    void Display(Node *)const;
    void Empty(Node *);
};


#endif /* defined(__lab5__BSTree__) */
