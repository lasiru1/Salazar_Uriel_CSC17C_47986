/* 
@file:      Stack.cpp
@author:    Uriel Salazar
@date:      October 6, 2018
@section:   47986
@brief:     Implementation file for push and pop (stack)
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries
#include "Stack.h"

Stack::Stack()
{
    stk = NULL;
    first = NULL;
}

Stack::~Stack()
{
    
}

void Stack::push(int val)
{
    if (this->isEmpty() == true)
    {
        stk = new Link();
        stk->setData(val);
        first = stk;
    }
    else 
    {
        Link *temp = new Link();
        temp->setData(val);
        stk->setNextLink(temp);
        stk = stk->getNextLink(); //traverse to the next link
    }
    cout << "Pushed value " << val << " onto the Stack!" << endl;
}

void Stack::pop()
{
    if (this->isEmpty() == true)
    {
        cout << "Error: Stack is Empty. Cannot pop value" << endl;
    } 
    else 
    {
        Link *next = first;
        Link *previous = NULL;
        
        while (next->getNextLink() != NULL)
        {
            previous = next;
            next = next->getNextLink();
        }
        next = NULL;
        
        //checks if stack is not empty
        if (previous != NULL)
        {
            previous->setNextLink(NULL);
        }
        stk = previous;
        cout << "Popped off";
    }
}

int Stack::size()
{
    int index = 0;
    if (!this->isEmpty() == true)
    {
        index++;
        Link * temp = first;
        while (temp->getNextLink() != NULL)
        {
            index++;
            temp = temp->getNextLink();
        }
    }
   return index;
}

bool Stack::isEmpty()
{
    if (stk == NULL)
    {
        return true;
    }
    return false;
}

void Stack::displayStackInfo()
{
    if (this->isEmpty() == true)
    {
        cout << "\nStack is Empty" << endl;
    }
    else 
    {  
        cout << endl << "Stack of size " << this->size() << " contains: ";
        Link *next = first;
        do
        {
            cout << next->getData() << " ";
            next = next->getNextLink();
        } while(next != NULL);
        cout << endl << endl;
    }
}
