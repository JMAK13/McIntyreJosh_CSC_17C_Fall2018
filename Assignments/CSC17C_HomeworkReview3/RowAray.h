/* 
 * File:   RowAray.h
 * Author: Josh McIntyre
 * Created on September 24, 2018, 6:16 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include <cstdlib>

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

//Constructor
template <class T>
RowAray<T>::RowAray(int s){
    //Initialize Member Variable
    s>0?size=s:size=2;
    
    //Allocate Memory
    rowData=new T[size];
    
    //Fill With Default Values
    for(int i=0; i<size; i++)
        rowData[i]=rand()%90+10;
}

//Destructor
template <class T>
RowAray<T>::~RowAray(){
    if(rowData) delete [] rowData;
}

//Data Mutator
template <class T>
void RowAray<T>::setData(int i, T v){
    if(rowData!=NULL) rowData[i]=v;
}

#endif /* ROWARAY_H */

