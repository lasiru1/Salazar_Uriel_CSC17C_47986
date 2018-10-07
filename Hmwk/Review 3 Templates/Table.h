/* 
@file:      Table.h
@author:    Uriel Salazar
@date:      October 7, 2018
@section:   47986
@brief:     Template class for Table
 */

#ifndef TABLE_H
#define	TABLE_H

//User libraries
#include "RowAray.h"

template <class T> class Table 
{
    protected:    
        int szRow;
        int szCol;
        RowAray<T> **columns;
      
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int     getSzRow()const {return szRow;}
        int     getSzCol()const {return szCol;}
        T       getData(int,int) const;
        void    setData(int,int,T);
        Table   operator+(const Table &);
};

template <class T> Table<T>::Table(unsigned int row, unsigned int col) 
{
    //Initialize rows and columns
    szRow = row;
    szCol = col;
    
    //Declare array size
    columns = new RowAray<T>*[szRow];
    
    //Create row size
    for (int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray<T>(szCol);
    }
}

//Equate columns and rows
template <class T> Table<T>::Table(const Table<T> &other)
{
    szCol = other.getSzCol(); 
    szRow = other.getSzRow();
    columns = new RowAray<T>*[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        this->columns[i] = new RowAray<T>(szCol);
    }
    for(int i = 0; i < szRow; i++)
    {
        for(int j = 0; j < szCol; j++)
        {
            setData(i,j, other.getData(i,j));
        }
    }
}

template <class T> Table<T>::~Table() 
{
    //Delete each record
    for(int i = 0;i < this->szRow;i++)
    {
        delete columns[i];
    }
    delete [] columns;
}

template <class T> T Table<T>::getData(int row, int col) const
{
   //restrict row and col
    if (row >= 0 && row < szRow && col >= 0
            && col < getSzCol())
    {
        return columns[row]->getData(col);
    }
}

template <class T> void Table<T>::setData(int row, int col, T num)
{
    //restrict row and col
    if (row >= 0 && row < this->szRow && col >= 0
            && col < getSzCol())
    {
        columns[row]->setData(col, num);
    } 
}

template <class T> Table<T> Table<T>::operator+(const Table<T>& other)
{
    Table<T> added(szRow, szCol);
    
    for(int i = 0; i < szRow; i++)
    {
        for(int j = 0; j < szCol; j++)
        {
            added.setData(i, j, (this->getData(i,j) + other.getData(i,j)));
        }
    }
   
    return added;
}

#endif	/* TABLE_H */