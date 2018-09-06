/* 
 * File:   Triangle.cpp
 * Author: Josh McIntyre
 * Created on September 5, 2018, 8:12 PM
 */

#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int r) {
    if(r>0)szRow=r;
    else szRow=1;
    
    records=new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        records[i]=new RowAray(i+1);
    }
}

Triangle::~Triangle() {
    if(records){
        for(int i=0;i<szRow; i++){
            delete records[i];
        }
        delete records;
    }
}

int Triangle::getData(int r, int c){
    return records[r]->getData(c);
}

