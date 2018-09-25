/* 
 * File:   Table.h
 * Author: Josh McIntyre
 * Created on September 24, 2018, 6:16 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

//Constructor
template <class T>
Table<T>::Table(unsigned int r, unsigned int c){
    //Initialize Table Member Variables
    r>0?szRow=r:szRow=2;
    c>0?szCol=c:szCol=2;
    
    //Allocate Table Memory
    columns=new RowAray<T>*[szRow];
    for(int i=0; i<szRow; i++){
        columns[i]=new RowAray<T>(szCol);
    }
    
    //Fill With Default Values
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i]->setData(j, rand()%90+10);
        }
    }
}

//Copy Constructor
template <class T>
Table<T>::Table(const Table<T>&copy){
    //Copy Table Member Variables
    copy.getSzRow()>0?szRow=copy.getSzRow():szRow=2;
    copy.getSzCol()>0?szCol=copy.getSzCol():szCol=2;
    
    //Allocate Table Memory
    columns=new RowAray<T>*[szRow];
    for(int i=0; i<szRow; i++){
        columns[i]=new RowAray<T>(szCol);
    }
    
    //Copy Values
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i]->setData(j, copy.getData(i, j));
        }
    }
}

//Destructor
template <class T>
Table<T>::~Table(){
    for(int i=0; i<szRow; i++){
        if(columns[i]) delete columns[i];
    }
    
    delete [] columns;
}

//Data Accessor
template <class T>
T Table<T>::getData(int r, int c) const{
    if(columns[r]!=NULL) return columns[r]->getData(c);
    else return 0;
}

//Data Mutator
template <class T>
void Table<T>::setData(int r, int c, T v){
    columns[r]->setData(c,v);
}

//Operator Overloading +
template <class T>
Table<T> Table<T>::operator +(const Table<T>&right){
    Table<T> temp(right.getSzRow(),right.getSzCol());
    
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            temp.setData(i,j,columns[i]->getData(j)+right.getData(i,j));
        }
    }
    
    return temp;
}

#endif /* TABLE_H */

