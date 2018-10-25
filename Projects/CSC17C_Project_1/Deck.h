/* 
 * File:   Deck.h
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

#ifndef DECK_H
#define DECK_H

//Included System Libraries
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;

//Included User Libraries
#include "Card.h"

//Deck Class
class Deck{
    private:
        vector<int> index;
        map<Card,int,Comparator> data;
        static const int nCards=52;
        int delt;
    public:
        //Constructor Taking Number of Cards as Parameter
        Deck();
        
        //Destructor
        ~Deck();
        
        //Card Accessor Member Function
        Card getCard(int i);
        
        
        //Card Index Accessor Member Function
        int getI(int i)const{return index[i];}
        
        //Card Index Mutator Member Function
        void setI(int,int);
        
        //Gets Number of Cards in Deck
        int numCards()const{return nCards;}
        
        //Delt Accessor Member Function
        int getDelt()const{return delt;}
        
        //Delt Mutator Member Function
        inline void setDelt(int i){
            if(i>=0) delt=i;
        };
        
        //Invalid Index Exception
        class InvalidIndex
            {   };
};
#endif /* DECK_H */

