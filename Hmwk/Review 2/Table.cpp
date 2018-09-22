/* 
@file:      Table.cpp
@author:    Uriel Salazar
@date:      September 19th, 2018
@section:   47986
@brief:     Driver for the table
 */

//User Libraries
#include "Table.h"

Table::Table(unsigned int row, unsigned int col)
{
    //Check parameters
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
    
    //Declare array size
    columns = new RowAray*[this->szRow];
    
    //Create row size
    for(int i = 0; i < this->szRow; i++)
    {
        columns[i] = new RowAray(this->szCol);
    }
}

//Set columns equal to rows
Table::Table(const Table &other)
{
    this->szCol = other.getSzCol();
    this->szRow = other.getSzRow();
    this->columns = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        this->columns[i] = new RowAray(szCol);
    }
    
    for(int i = 0; i < szRow; i++)
    {
        for(int j = 0; j < szCol; j++)
        {
            setData(i, j, other.getData(i, j));
        }
    }
}

//Destructor
Table::~Table()
{
    //Delete all records
    for(int i = 0; i < this->szRow; i++)
    {
        delete columns[i];
    }
    delete [] columns;
}

int Table::getData(int row, int col) const
{
    //Set restrictions for rows and columns
    if(row >= 0 && row < this->szRow && col >= 0 && col < getSzCol())
    {
        return columns[row]->getData(col);
    }
}

void Table::setData(int row, int col, int num)
{
    //Set restrictions for rows and columns
    if(row >= 0 && row < this->szRow && col >= 0 && col < getSzCol())
    {
        columns[row]->setData(col, num);
    }
}