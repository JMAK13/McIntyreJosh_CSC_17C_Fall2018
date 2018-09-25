/* 
 * File:   RowAray.cpp
 * Author: Josh McIntyre
 * Created on September 18, 2018, 8:28 PM
 */

#include "RowAray.h"

RowAray::RowAray(unsigned int s):AbsRow() {
    if(s>1)size=s;
    else size=2;
    
    rowData=new int[size];
    for(int i=0; i<size; i++){
        rowData[i]=rand()%90+10;
    }
}

RowAray::~RowAray() {
    delete[] rowData;
}

void RowAray::setData(int i, int x){
    rowData[i]=x;
}

