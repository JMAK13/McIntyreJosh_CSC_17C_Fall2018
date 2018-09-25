/* 
 * File:   Table.cpp
 * Author: Josh McIntyre
 * Created on September 18, 2018, 8:33 PM
 */

#include "Table.h"

Table::Table(unsigned int r, unsigned int c):AbsTabl() {
    if(r>1)szRow=r;
    else szRow=2;
    if(c>1)szCol=c;
    else szCol=2;
    
    columns=new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        columns[i]=new RowAray(szCol);
    }
}

Table::Table(const Table &tabl){
    if(tabl.szRow>1)szRow=tabl.szRow;
    else szRow=2;
    if(tabl.szCol>1)szCol=tabl.szCol;
    else szCol=2;
    
    columns=new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        columns[i]=new RowAray(szCol);
    }
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            setData(i, j, tabl.getData(i,j));
        }
    }
}

Table::getData(int r, int c) const{
    return columns[r]->getData(c);
}

void Table::setData(int r, int c, int x){
    columns[r]->setData(c,x);
}

Table::~Table() {
    for(int i=0; i<szRow; i++){
        delete columns[i];
    }
    
    delete[] columns;
}

