/* 
@file:      RowAray.h
@author:    Uriel Salazar
@date:      October 7, 2018
@section:   47986
@brief:     Template class for RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

template <class T> class RowAray
{
    protected: 
        int size;
        T *rowData;
        
    public:
        RowAray(unsigned int);
        ~RowAray();
        int getSize()const{return size;}
        T   getData(int i)const
        {
            if(i >= 0 && i < size)
            {
                return rowData[i];
            }
            else
            {
               return 0; 
            }
        }
        void setData(int,T);
};

template<class T> RowAray<T>::RowAray(unsigned int n) 
{
    //Set array size
    this->size = n;
    
    //Set pointer to a sized T array
    rowData = new T[size];
    
    //Fill array
    for (int i = 0; i < this->size; i++)
    {
        rowData[i] = rand() % 90 + 10;
    }
}

template<class T> RowAray<T>::~RowAray()
{
    delete [] rowData;
}

template<class T> void RowAray<T>::setData(int col, T num)
{
    rowData[col] = num;
}

#endif	/* ROWARAY_H */