/* 
@file:      PlusTab.cpp
@author:    Uriel Salazar
@date:      September 19th, 2018
@section:   47986
@brief:     Driver for the table addition operator
 */

//User Libraries
#include "AbsRow.h"
#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab& other)
{
    PlusTab added(this->szRow, this->szCol);
    
    for(int i = 0; i < this->szRow; i++)
    {
        for(int j = 0; j < this->szCol; j++)
        {
            added.setData(i, j, (this->getData(i, j) + other.getData(i, j)));
        }
    }
    
    return added;
}

