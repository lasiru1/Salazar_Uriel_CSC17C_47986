/* 
@file:      Table.cpp
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
#include "Table.h"

//Global Constants

//Function Prototypes

//Execution begins here
Table::Table(int row, int col)
{
    //Determine parameters
    if(row > 0)
    {
        szRow = row;
    }
    else
    {
        szRow = 1;
    }
    if(col > 0)
    {
        szCol = col;
    }
    else
    {
        szCol = 1;
    }
    
    //Initialize array size
    records = new RowAray*[this->szRow];
    
    //Create row sizes
    for(int i = 0; i < this->szRow; i++)
    {
        records[i] = new RowAray(this->szCol);
    }
}

//Destructor
Table::~Table()
{
    //Delete records
    for(int i = 0; i < this->szRow; i++)
    {
        delete records[i];
    }
    delete [] records;
}

int Table::getData(int row, int col)
{
    //Set row and column restrictions
    if(row >= 0 && row < this->szRow && col >= 0 && col < getSzCol())
    {
        return records[row]->getData(col);
    }
    else
    {
        //Exit program
        return 0;
    }
}