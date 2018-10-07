/* 
@file:      Stack.h
@author:    Uriel Salazar
@date:      October 6, 2018
@section:   47986
@brief:     Function declarations for push and pop (stack)
 */

#ifndef STACK_H
#define STACK_H

//User libraries
#include "Link.h"

//Declare class
class Stack
{
    private:
        Link *stk;
        Link *first;
    public:
        Stack();
        ~Stack();
        void    push(int);  //add link
        void    pop();      //delete link
        int     size();     //return size of stack
        bool    isEmpty();
        void    displayStackInfo();
    
};

#endif /* STACK_H */