/* 
 * File:   Table.cpp
 * Author: Josh McIntyre
 * Created on September 5, 2018, 8:11 PM
 */

#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(int r, int c) {
    if(r>0)szRow=r;
    else szRow=2;
    if(c>0)szCol=c;
    else szCol=2;
    
    
    
    records=new RowAray*[szRow];
    
    for(int i=0; i<szRow; i++){
        records[i]=new RowAray(szCol);
    }
}

Table::~Table() {
    if(records){
        for(int i=0;i<szRow; i++){
            delete records[i];
        }
        delete records;
    }
}

int Table::getData(int r, int c){
    return records[r]->getData(c);
}

