/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 13, 2018, 12:15 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <list>
#include <iterator>
using namespace std;

//User Libraries

//Function Prototypes
string randStr(int);
unsigned int RSHash(const string&);

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variables
    unsigned int SIZE=5000000,strSize=20;
    string *a1=new string[SIZE], *a2=new string[SIZE], *a3=new string[SIZE];
    set<string> sortedA2;
    map<unsigned int, list<string> > hashes;
    int cnt1=0,cnt2=0,cnt3=0;
    string s;
    int begin,end;
    int loops;
    
    //Fill Arrays w/ Random Strings
    for(int i=0; i<SIZE; i++){
        s=randStr(strSize);
        a1[i]=s;
        sortedA2.insert(s);
        a3[i]=s;
    }
    
    //Copies Sorted Set to Binary Search Array
    set<string>::iterator it=sortedA2.begin();
    int index=0;
    for(it=sortedA2.begin(); it!=sortedA2.end(); ++it){
        a2[index]=(*it);
        index++;
    }
    
    //Linear Search
    /*loops=13;
    begin=time(0);
    for(int j=0; j<loops; j++){
        for(int i=0; i<SIZE; i++)
            if(s==a1[i]) cnt1++;
    }
    end=time(0);
    cout<<"\nLinear Search:"<<endl;
    cout<<"Array Size = "<<SIZE<<endl;
    cout<<"Loops = "<<loops<<endl;
    cout<<"String Size = "<<strSize<<endl;
    cout<<"Linear Occurrences = "<<cnt1<<endl;
    cout<<"Time = "<<end-begin<<endl;*/
    
    //Binary Search
    /*s=a2[SIZE-1];
    loops=16000000;
    begin=time(0);
    for(int i=0; i<loops; i++){
        int middle,min=0,max=SIZE-1;;
        while (min<=max){
            middle=(int)(((max+min)/2)+0.5);
            if(s==a2[middle]){
                cnt2++;
                break;
            }else if(a2[middle]<s)
                min=middle+1;
            else
                max=middle-1;
        }
    }
    end=time(0);
    cout<<"\nBinary Search:"<<endl;
    cout<<"Array Size = "<<SIZE<<endl;
    cout<<"Loops = "<<loops<<endl;
    cout<<"String Size = "<<strSize<<endl;
    cout<<"Time = "<<end-begin<<endl;*/
    
    //Hash Search
    for(int i=0; i<SIZE; i++){
        unsigned int x=RSHash(a3[i]);
        hashes[x].push_back(a3[i]);
    }
    begin=time(0);
    loops=8000000;
    for(int i=0; i<loops; i++){
        unsigned int h=RSHash(s);
        if(hashes.count(h)==0) cnt3+=0;
     else {cnt3+=hashes[h].size(); break;}
    }
    end=time(0);
    cout<<"\nHash Search:"<<endl;
    cout<<"Array Size = "<<SIZE<<endl;
    cout<<"Loops = "<<loops<<endl;
    cout<<"String Size = "<<strSize<<endl;
    cout<<"Time = "<<end-begin<<endl;
    
    delete [] a1;
    delete [] a2;
    delete [] a3;
    
    //Exits Program
    return 0;
}

//Random String Utility Function
string randStr(int strSize){
    string s="";
    for(int i=0; i<strSize; i++)
        s+=(48 + (rand() % (int)(122 - 48 + 1)));
    return s;
}

//RSHash Function
unsigned int RSHash(const std::string& str){
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}



