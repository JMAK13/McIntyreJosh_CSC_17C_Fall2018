/* 
 * File:   RowAray.cpp
 * Author: Josh McIntyre
 * Created on September 5, 2018, 8:11 PM
 */

#include "RowAray.h"
#include <cstdlib>

RowAray::RowAray(int s) {
    if(s>0)size=s;
    else size=2;
    rowData=new int[size];
    for(int i=0; i<size; i++){
        rowData[i]=rand()%90+10;
    }
}

RowAray::~RowAray() {
    delete [] rowData;
}

