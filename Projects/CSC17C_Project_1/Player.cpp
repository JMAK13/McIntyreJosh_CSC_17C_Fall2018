/* 
 * File:   Player.cpp
 * Author: Josh McIntyre
 * Created on May 16, 2018, 1:28 PM
 */

//Included System Libraries
#include <iostream>
#include <iterator>
using namespace std;

//Included User Libraries
#include "Player.h"

//Default Player Constructor
Player::Player(){
    isPl=true;
    name="Player Name";
    inHand=0;
    hand.reserve(52);
    for(int i=0; i<hand.capacity(); i++)
        hand.push_back(-1);
}

//Overloaded Player Constructor
Player::Player(string s){
    isPl=true;
    name=s;
    inHand=0;
    hand.reserve(52);
    for(int i=0; i<hand.capacity(); i++)
        hand.push_back(-1);
}

//Player Copy Constructor
Player::Player(Player &player){
    name=player.name;
    hand=player.hand;
    inHand=player.inHand;
}

//Player Destructor
Player::~Player(){
    
}

//Index Mutator Member Function
void Player::setHand(int i, int v){
    if(i>=0) hand[i]=v;
    else throw Player::BadIndex();
}

//Counts Indexes in Player's Hand Vector
int Player::cntHand(){
    vector<int>::iterator it;
    int count=0;
    for(it=hand.begin(); it<hand.end(); it++)
        if(*it>=0)count++;
        
    return count;
}

//Gets Index at Top of Player's Vector
int Player::getTop(){
    vector<int>::iterator it;
    for(it=hand.begin(); it<hand.end(); it++)
        if(*(it+1)==-1) return *it;
    
}

//Sets Index at Top of Player's Vector to -1
void Player::setTop(){
    for(int i=0; i<hand.capacity(); i++){
        try{
            if(getHand(i+1)==-1) setHand(i,-1);
        }
        catch(Player::BadIndex){
            std::cout<<"Invalid index has been entered.\n";
        }
    }
}

//Moves Top Card of Player's Hand to Bottom
void Player::toBot(int c){
    int tmp=hand.front(),tmp2;
    for(int i=0; i<52; i++){
        if(i==0) hand[i]=c;
        else{
            tmp2=hand[i];
            hand[i]=tmp;
            tmp=tmp2;
        }
    }
    try{
        setHand(0,c);
    }catch(Player::BadIndex){
        cout<<"Invalid index has been entered./n";
    }
}
