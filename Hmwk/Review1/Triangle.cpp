/* 
@file:      Triangle.cpp
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
#include "Triangle.h"

//Global Constants

//Function Prototypes

//Execution begins here
Triangle::Triangle(int x)
{
    //Determine parameters
    if(x > 0)
    {
        szRow = x;
        
    }
    else
    {
        szRow = 1;
    }
    
    //Initialize array size
    records = new RowAray*[this->szRow];
    
    //Create row sizes
    for(int i = 0; i < this->szRow; i++)
    {
        records[i] = new RowAray(i + 1);
    }
}

//Destructor
Triangle::~Triangle()
{
    //Delete records
    for(int i = 0; i < this->szRow; i++)
    {
        delete records[i];
    }
    delete [] records;
}

int Triangle::getData(int row, int col)
{
    //Set row and column restrictions
    if(row >= 0 && row < this->szRow && col >= 0
            && col < records[row]->getSize())
    {
        return records[row]->getData(col);
    }
    else
    {
        return 0;
    }
}