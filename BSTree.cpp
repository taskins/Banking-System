//
//  BSTree.cpp
//  lab5
//
//  Created by Selen Taskin on 6/6/15.
//  Copyright (c) 2015 Selen Taskin. All rights reserved.
//

#include "BSTree.h"


using namespace std;


BSTree::BSTree()
{
    root = NULL;
}

BSTree::BSTree(const BSTree& source) : root(NULL)
{
    copy(source);
}

bool BSTree::Insert(Account *client)
{
    Node *temp;
    temp = new Node();
    temp->pAcct = client;
    if (root == NULL)
    {
        root = temp;
        return true;
    }
    return Insert(root, temp);
}

bool BSTree::Insert(Node *traverse, Node *temp)
{
    if (traverse->pAcct->getID() > temp->pAcct->getID())
    {
        if (traverse->left == NULL)
        {
            traverse->left = temp;
            return true;
        }
        else if (traverse->left->pAcct->getID() < temp->pAcct->getID())
        {
            temp->left = traverse->left;
            traverse->left = temp;
        }
        else
        {
            return Insert(traverse->left, temp);
        }
    }
    else if (traverse->pAcct->getID() < temp->pAcct->getID())
    {
        if (traverse->right == NULL)
        {
            traverse->right = temp;
            return true;
        }
        else if (traverse->right->pAcct->getID() > temp->pAcct->getID())
        {
            temp->right = traverse->right;
            traverse->right = temp;
        }
        else
        {
            return Insert(traverse->right, temp);
        }
    }
    return false;
}

bool BSTree::Retrieve(const int &iD, Account * &client) const
{
    if (this == NULL)
    {
        client = NULL;
        return false;
    }
    return Retrieve(root, iD, client);
}

bool BSTree::Retrieve(const Node *head, const int &iD, Account * &client) const
{
    if (head == NULL)
    {
        client = NULL;
        return false;
    }
    else if (head->pAcct->getID() == iD)
    {
        client = head->pAcct;
        return true;
    }
    else if (head->pAcct->getID() < iD)
    {
        return Retrieve(head->right, iD, client);
    }
    else
    {
        return Retrieve(head->left, iD, client);
    }
}

bool BSTree::isEmpty() const
{
    return root == NULL;
}
//Processing!
void BSTree::Empty()
{
    if (root != NULL)
    {
        Empty(root);
        root = NULL;
    }
}
void BSTree::Empty(Node *traverse)
{
    if (traverse == NULL)
    {
        return;
    }
    Empty(traverse->left);
    Empty(traverse->right);
    delete traverse->pAcct;
    delete traverse;
}
//Done
void BSTree::Display() const
{
    if (root != NULL)
    {
        Display(root);
    }
}
//Done
void BSTree::Display(Node *traverse) const
{
    if (traverse == NULL)
    {
        return;
    }
    Display(traverse->left);
    cout << *traverse->pAcct << "\n";
    Display(traverse->right);
}

BSTree& BSTree::operator=(const BSTree &source)
{
    if (this != &source)
    {
        clear();
        copy(source);
    }
    return *this;
}
void BSTree::clear()
{
    delete root;
    root = NULL;
}

void BSTree::copy(const BSTree & source)
{
    root = new Node();
    *root = *source.root;
}

BSTree::~BSTree()
{
    clear();
}


