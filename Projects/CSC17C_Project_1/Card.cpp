/* 
 * File:   Card.cpp
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

//Included System Libraries
#include <vector>
#include <iostream>
using namespace std;

//Included User Libraries
#include "AbstractCard.h"
#include "Card.h"

//Default Card Constructor
Card::Card() : AbstractCard(){
}

//Overloaded Card Constructor
Card::Card(int v) : AbstractCard(){
    serial=v;
    if(v<0) throw Card::NegativeValue();
    else if(v<=13&&v>=1) data.first=v;
    else {v%=13; v==0?data.first=13:data.first=v;}
    data.second="SuitTest";
    
    //Initialize Card Suits
    try{
        if(serial>=0&&serial<=12) data.second="Spades";
        else if(serial>=13&&serial<=25) data.second="Clubs";
        else if(serial>=26&&serial<=38) data.second="Hearts";
        else if(serial>=39&&serial<=51) data.second="Diamonds";
    }
    catch(Card::InvalidSuit){
        cout<<"Invalid suit has been entered.\n";
    }
    
}

//Card Copy Constructor
Card::Card(const Card &card){
    serial=card.serial;
    data.second=card.data.second;
    data.first=card.data.first;
}

//Card Destructor
Card::~Card(){
    
}

//Suit Mutator Member Function
void Card::setSuit(string s){
    string array[4]={"Spades","Clubs","Hearts","Diamonds"};
    if(s!=array[0]&&s!=array[1]&&s!=array[2]&&s!=array[3]) throw Card::InvalidSuit();
    else for(int i=0;i<4;i++){
        if(s==array[i]) data.second=s;
    }
}

//Value Mutator Member Function
void Card::setVal(int v){
    if(v<0) throw Card::NegativeValue();
    if(v<=13&&v>=1) data.first=v;
    else {v%=13; v==0?data.first=13:data.first=v;}
}

//Name Accessor Member Function
string Card::getName(int v){
    if(v<1) throw Card::NegativeValue();
    string s;
    if(v==1)s="Ace ";
    else if(v==2)s="Two";
    else if(v==3)s="Three";
    else if(v==4)s="Four";
    else if(v==5)s="Five";
    else if(v==6)s="Six";
    else if(v==7)s="Seven";
    else if(v==8)s="Eight";
    else if(v==9)s="Nine";
    else if(v==10)s="Ten";
    else if(v==11)s="Jack";
    else if(v==12)s="Queen";
    else if(v==13)s="King";
    return s;
}

//Overloaded > Operator Function
bool Card::operator > (const Card &right){
    if(data.first==right.getVal()) return false;
    else if(data.first==1&&right.getVal()>1) return true;
    else if(data.first>1&&right.getVal()==1) return false;
    else return data.first>right.getVal();
}

//Overloaded < Operator Function
bool Card::operator < (const Card &right){
    if(data.first==right.getVal()) return false;
    else if(data.first==1&&right.getVal()>1) return false;
    else if(data.first>1&&right.getVal()==1) return true;
    else return data.first<right.getVal();
}

//Overloaded == Operator Function
bool Card::operator == (const Card &right){
    if(data.first==right.getVal()) return true;
    else return false;
}
