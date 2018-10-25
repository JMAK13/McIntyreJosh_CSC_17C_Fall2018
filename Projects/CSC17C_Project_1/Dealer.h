/* 
 * File:   Dealer.h
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

#ifndef DEALER_H
#define DEALER_H

//Included System Libraries
#include <iostream>
using namespace std;
//Included User Libraries
#include "GameEntity.h"
#include "Player.h"

//Dealer Template Class
template <class T>
class Dealer:public GameEntity{
    public:
        //Dealer Constructor
        Dealer();
        
        //Dealer Destructor
        ~Dealer();
        
        //Overloaded Virtual Function
        virtual bool isPlayer()const override{return isPl;}
        
        //Deals Cards
        void dealCrds(Player &,Deck &,int);
        
        //Shuffles Cards
        void shuffle(Deck &);
        
        //Invalid Card Amount Exception
        class BadCardCount
            {   };
};

//Dealer Constructor
template <class T>
Dealer<T>::Dealer():GameEntity(){
    isPl=false;
}

//Dealer Destructor
template <class T>
Dealer<T>::~Dealer() {
    
}

//Deals Card to Player from Deck
template <class T>
void Dealer<T>::dealCrds(Player &p, Deck &d, int n){
    if(n+d.getDelt()>d.numCards()) throw BadCardCount();
    else {
        int ind=0;
        for(int i=d.getDelt(); i<n+d.getDelt(); i++){
            p.setHand(ind, d.getI(i));
            ind++;
        }
        d.setDelt(d.getDelt()+n);
    }
}

//Shuffles Deck
template <class T>
void Dealer<T>::shuffle(Deck &d){
    for(int shfl=0; shfl<=3; shfl++){
        for(int i=0; i<d.numCards(); i++){
            int random=rand()%d.numCards();
            int temp=d.getI(i);
            d.setI(i,d.getI(random));
            d.setI(random,temp);
        }
    }
}

#endif /* DEALER_H */

