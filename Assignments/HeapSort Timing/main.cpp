/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: joshr
 *
 * Created on November 13, 2018, 11:06 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//Function Prototypes
void heapify(int [], int, int);
void heapSort(int [], int);

// Driver program 
int main(){
    
    srand(static_cast<unsigned int>(time(0)));
    
    int SIZE=80000000;
    int *arr=new int[SIZE];
    
    for(int i=0; i<SIZE; i++)
        arr[i]=rand()%90+10;

    int begin=time(0);
    heapSort(arr, SIZE); 
    int end=time(0);

    cout<<"Time = "<<end-begin<<endl;
    
    delete [] arr;
    
    return 0;
}

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 
	int r = 2*i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i=n-1; i>=0; i--) 
	{ 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
}


