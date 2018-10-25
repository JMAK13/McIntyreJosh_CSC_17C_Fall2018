/* 
 * File:   Card.h
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#ifndef CARD_H
#define CARD_H

//Included User Libraries
#include "AbstractCard.h"
#include <utility>
using namespace std;

//Card Class Derived from Abstract Base Card Class
class Card:public AbstractCard{
    private:
        pair<int,string> data;
        int serial;
    public:
        //Empty Constructor
        Card();
        
        //Constructor Taking a Card Value is a Parameter
        Card(int);
        
        //Card Copy Constructor
        Card(const Card &);
        
        //Destructor
        ~Card();
        
        //Suit Accessor Member Function
        virtual string getSuit()const override{return data.second;}
        
        //Value Accessor Member Function
        virtual int getVal()const override{return data.first;}
        
        //Suit Mutator Member Function
        void setSuit(string);
        
        //Value Mutator Member Function
        void setVal(int);
        
        //Serial Mutator Member Function
        void setS(int s){serial=s;}
        
        //Serial Mutator Member Function
        int getS()const{return serial;}
        
        //Overloaded > Function
        bool operator > (const Card &right);
        
        //Overloaded < Function
        bool operator < (const Card &right);
        
        //Overloaded == Function
        bool operator == (const Card &right);
        
        //Name Accessor Member Function
        virtual string getName(int)override;
        
        //Invalid Suit Exception
        class InvalidSuit
            {   };
            
        //Negative Value
        class NegativeValue
            {   };
};

class Comparator {
public:
    bool operator()(const Card& c1, const Card& c2){
        return c1.getS() < c2.getS();
    }
};

#endif /* CARD_H */
