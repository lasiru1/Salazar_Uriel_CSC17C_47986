/* 
@file:      Link.cpp
@author:    Uriel Salazar
@date:      September 30, 2018
@section:   47986
@brief:     Implementation file for linked list
 */

//System libraries
#include <iostream>
using namespace std;

//User libraries
#include "Link.h"

Link::Link()
{
    this->data = -1;
    this->nextPtr = NULL;
    this->previousPtr = NULL;
}

Link::Link(int val)
{
    this->data = val;
    this->nextPtr = NULL;
    this->previousPtr = NULL;
}

Link::~Link()
{
    
}

void Link::setData(int val)
{
    this->data = val;
}

int Link::getData()
{
    return data;
}

Link* Link::getNextLink()
{
    return nextPtr;
}

void Link::setNextLink(Link * next)
{
    this->nextPtr = next;
}

Link* Link::getPreviousLink()
{
    return previousPtr;
}

void Link::setPreviousLink(Link * next)
{
    this->previousPtr = next;
}