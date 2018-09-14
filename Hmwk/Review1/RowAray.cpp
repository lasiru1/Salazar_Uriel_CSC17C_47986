/* 
@file:      RowAray.cpp
@author:    Uriel Salazar
@date:      September 11th, 2018
@section:   47986
@brief:     Driver for dynamic objects.
 */

//System Libraries
#include <cstdlib>  //General utilites library
#include <iostream> //Input/Output library
#include <fstream>  //File input/output library

//User Libraries
#include "RowAray.h"

//Global Constants

//Function Prototypes

//Execution begins here
RowAray::RowAray(int x)
{
    //Declare size with a minimum value of 1
    if(x > 1)
    {
        this->size = x;
    }
    else
    {
        this->size = 1;
    }
    
    //Set pointer to a sized int array
    rowData = new int[size];
    
    //Fill array
    for(int i = 0; i < this->size; i++)
    {
        //Random two-digit number
        rowData[i] = rand() % 90 + 10;
    }
}

RowAray::~RowAray()
{
    delete [] rowData;
}