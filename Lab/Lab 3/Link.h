/* 
@file:      Link.h
@author:    Uriel Salazar
@date:      September 30, 2018
@section:   47986
@brief:     Function declarations for linked list
 */

#ifndef LINK_H
#define LINK_H

//System libraries
#include <iostream>
using namespace std;

//Declare class
class Link
{
    private:
        int     data;
        Link    *nextPtr;
        Link    *previousPtr;
    public:
        Link();
        Link(int);
        ~Link();
        void    setData(int);
        int     getData();
        Link    *getNextLink();
        Link    *getPreviousLink();
        void    setNextLink(Link *);
        void    setPreviousLink(Link *);
};

#endif /* LINK_H */