/* 
 * File:   PlusTab.cpp
 * Author: Josh McIntyre
 * Created on September 18, 2018, 8:27 PM
 */

#include "PlusTab.h"
#include "Table.h"

PlusTab PlusTab::operator +(const PlusTab &right){
    PlusTab temp(szRow,szCol);

    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            temp.setData(i,j,getData(i,j)+right.getData(i,j));
        }
    }
    return temp;
}

