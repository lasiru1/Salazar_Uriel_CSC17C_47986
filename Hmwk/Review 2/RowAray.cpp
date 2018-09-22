/* 
@file:      RowAray.cpp
@author:    Uriel Salazar
@date:      September 19th, 2018
@section:   47986
@brief:     Driver for the row array
 */

//System Libraries
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

//User Libraries
#include "RowAray.h"

RowAray::RowAray(unsigned int x)
{
    //Size cannot be less than 1
    if(x > 1)
    {
        this->size = x;
    }
    else
    {
        this->size = 1;
    }
    
    //Pointer is set to a sized int array
    rowData = new int[size];
    
    //Fill array
    for(int i = 0; i < this->size; i++)
    {
        //Fill with random two-digit numbers
        rowData[i] = rand() % 90 + 10;
    }
}

//Destructor
RowAray::~RowAray()
{
    delete [] rowData;
}

void RowAray::setData(int col, int num)
{
    rowData[col] = num;
}