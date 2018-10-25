/* 
 * File:   AbstractCard.h
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

//Included System Libraries
#include <string>

//Abstract Base Card Class
class AbstractCard {
    virtual std::string getSuit()const=0;
    virtual int getVal()const=0;
    virtual std::string getName(int)=0;
};

#endif /* ABSTRACTCARD_H */

