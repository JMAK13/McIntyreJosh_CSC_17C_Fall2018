/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 25, 2018, 4:19 PM
 */

//Global Constants

//Included System Libraries
#include <iostream>     //cout,endl,cin,getline
#include <cctype>       //isalpha
#include <fstream>      //fstream,write,read
#include <cstdlib>      //rand,srand
#include <ctime>        //time
using namespace std;

//Included User Libraries
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Node.h"

//Function Prototypes
void prntCrd(Deck &d,int);               //Prints a Card
void war(Player &,Player &,Deck &);      //Initiates War Protocol
struct Node *newNode(int);               //Tree Node
void storeSorted(Node *, int [], int &); //Recursive Sort Function
Node* insert(Node* , int);               //Tree Insertion
void treeSort(int [], int);              //Tree Sort

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool menu=false;
    char menuIn;
    
    //Menu
    cout<<"###########################################\n";
    cout<<"#  Welcome to War v2.0 by Josh McIntyre!  #\n";
    cout<<"###########################################\n\n";
    
    //Menu Input Validation
    do{
        cout<<"Enter 1 to Play, 2 to View Rules, or 0 to Exit: ";
        cin>>menuIn;
        if(isalpha(menuIn)) cout<<"Invalid input, please try again!"<<endl;
        else if(menuIn-48<0||menuIn-48>2) cout<<"Invalid input, please try again!"<<endl;
        else menu=true;
    }while(!menu);
    
    cout<<"\n\n";
    
    //Menu Input Protocol
    switch(menuIn-48){
        
        //Exit Protocol
        case 0:{
            cout<<"I guess you don't want to play, see you later!"<<endl;
            break;
        }
        
        //Rules Protocol
        case 2:{
            cout<<"Both players start with 26 shuffled cards, and each turn they each flip the their top card.";
            cout<<"\nThe player whose card is a higher value takes both cards.";
            cout<<"If the cards are of the same value\nthen the 'War' protocol is initiated, each player will place down another face down card, then";
            cout<<"\nanother face up card, and whichever second face up card is of higher value that player takes all cards.";
            cout<<"\nPlayers keep repeating the 'War' protocol as long as their face ups cards are of the same value.";
            break;
        }
        
        //Game Protocol
        case 1:{
            
            //Declare Game Variables
            string name1,name2;
            fstream dataFile("players.dat",ios::out | ios::binary);
            
            //Ask Players For Their Names and Write Them to Binary File
            cout<<"User 1, please enter your name:  ";
            cin.ignore();
            getline(cin,name1);
            dataFile.write(&name1[0], sizeof(name1));
            cout<<"User 2, please enter your name:  ";
            getline(cin,name2);
            dataFile.write(&name2[0], sizeof(name2));
            dataFile.close();
            cout<<"\n";
            
            //Game Loop
            char ans;
            do{
                //Declares Variables
                string winner;
                ans=' ';
                
                //Initialize Deck and Player Objects
                Deck d;
                Player p1,p2;
                
                //Pick Who Goes First - This Function Is Only To Implement A Tree And Recursive Sort
                //In Order to Meet Project Requirements
                int arr[20]={};
                for(int i=0; i<20; i++) arr[i]=rand()%90+10;
                treeSort(arr,20);
                int indx1=rand()%20,
                    indx2=rand()%20;

                //Initialize Player Objects
                if(indx1>indx2){
                    cout<<name1<<" has been randomly chosen to be Player 1!\n";
                    p1.setName(name1);
                    p2.setName(name2);
                }
                else{
                    cout<<name2<<" has been randomly chosen to be Player 1!\n";
                    p1.setName(name2);
                    p2.setName(name1);
                }
                
                //Initializes Dealer Object
                Dealer<Card> dlr;
                
                //Dealer Shuffle Deck
                dlr.shuffle(d,0);
                
                //Dealer Deals Cards to Players
                dlr.dealCrds(p1,d,26);
                dlr.dealCrds(p2,d,26);

                //Game Loop
                do{
                    
                    //Prompt Player 1 to Begin Turn & Display Card Drawn
                    cout<<"Press enter to begin turn: ";
                    cin.get();
                    cout<<p1.getName()<<" placed down a ";
                        prntCrd(d,p1.getTop());
                    
                    //Prompt Player 2 to Begin Turn & Display Card Drawn
                    cout<<"Press enter to begin turn: ";
                    cin.get();
                    cout<<p2.getName()<<" placed down a ";
                        prntCrd(d,p2.getTop());
                        
                    //If Player 1's Card Is Greater
                    if(d.getCard(p1.getTop()) > d.getCard(p2.getTop())) {
                        cout<<p1.getName()<<" wins this round!"<<endl;
                        p1.toBot(p1.getTop());
                        p1.toBot(p2.getTop());
                        p1.setTop();
                        p2.setTop();
                    }
                        
                    //If Player 2's Card is Greater
                    else if(d.getCard(p1.getTop()) < d.getCard(p2.getTop())) {
                        cout<<p2.getName()<<" wins this round!"<<endl;
                        p2.toBot(p2.getTop());
                        p2.toBot(p1.getTop());
                        p2.setTop();
                        p1.setTop();
                    }
                        
                    //If Both Players Card's Have Same Value
                    else if(d.getCard(p1.getTop()) == d.getCard(p2.getTop())){
                        cout<<"War has been initiated!"<<endl;
                        war(p1,p2,d);
                    }
                     
                    //Clears Screen
                    cout<<"\n\n\n\n";
                
                //End Game Condition
                }while(p1.cntHand()!=52&&p2.cntHand()!=52);

                //Displays Winner
                cout<<endl<<endl;
                if(p1.cntHand()==d.numCards()) {
                    cout<<p1.getName()<<" wins the game!"<<endl;
                    winner=name1;
                }
                if(p2.cntHand()==d.numCards()) {
                    cout<<p2.getName()<<" wins the game!"<<endl;
                    winner=name2;
                }

                //Write Winner's Name to Binary File
                fstream file("winners.dat",ios::out | ios::binary);
                file.write(&winner[0], sizeof(winner));
                file.close();

                //Asks If Users Would Like to Player Again
                cout<<"Did you have fun? [Y/N]";
                cin>>ans;

            }while(toupper(ans)=='Y');
            
            //Exit Message
            cout<<"It was fun playing, hope to see you again soon!\n";
            
            //Exits Game Protocol
            break;
        }
    }

    //Exits Program
    return 0;
}

//Prints a Card
void prntCrd(Deck &d, int n){
    if(n>=0)cout<<d.getCard(n).getName(d.getCard(n).getVal())<<" of "<<d.getCard(n).getSuit()<<endl;
}

//Initiates 'war' Protocol
void war(Player &p1, Player &p2, Deck &d){
    int wars=1;
    bool end=false;
    
    do{
        bool done=false;
        int crd1,crd2,i=0;
        while(!done){
            if(p1.getHand(i)==-1){
                crd1=p1.getHand(i-(wars*2)-1);
                done=true;
            }
            i++;
        }
        i=0;
        done=false;
        while(!done){
            if(p2.getHand(i)==-1){
                crd2=p2.getHand(i-(wars*2)-1);
                done=true;
            }
            i++;
        }
        
        //Display Cards Placed Down
        cout<<"Player 1 placed down a ";
            prntCrd(d,crd1);
        cout<<"Player 2 placed down a ";
            prntCrd(d,crd2);
            
        //If Player 1's Card is Higher
        if(d.getCard(crd1) > d.getCard(crd2)){
            for(int j=0; j<(wars*2)+1; j++){
                p1.toBot(p1.getTop());
                p1.toBot(p2.getTop());
                p1.setTop();
                p2.setTop();
            }
            cout<<p1.getName()<<" won the war!"<<endl;
            end=true;
        }
            
        //If Player 2's Card is Higher
        else if(d.getCard(crd1) < d.getCard(crd2)){
            for(int j=0; j<(wars*2)+1; j++){
                p2.toBot(p2.getTop());
                p2.toBot(p1.getTop());
                p2.setTop();
                p1.setTop();
            }
            cout<<p2.getName()<<" won the war!"<<endl;
            end=true;
        }
            
        //If Both Players Placed Down Cards of the Same Value
        else if(d.getCard(crd1) == d.getCard(crd2)){
            wars++;
        }
    }while(!end);
}

// A utility function to create a new BST Node
struct Node *newNode(int item){
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i){
    if (root != NULL){
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
  
/* A utility function to insert a new
   Node with given key in BST */
Node* insert(Node* node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
  
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
  
    /* return the (unchanged) Node pointer */
    return node;
} 
  
// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n){
    struct Node *root = NULL;
  
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);
  
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}
