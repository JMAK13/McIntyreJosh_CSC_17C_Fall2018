/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 13, 2018, 10:39 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include <ctime>
using namespace std;

//Function Prototypes
void swap(int*, int*);
int partition (int [], int, int);
void quickSort(int [], int, int);

// Driver program to test above functions 
int main(){
    
    srand(static_cast<unsigned int>(time(0)));

    int SIZE=300000;
    int arr[SIZE];
    
    for(int i=0; i<SIZE; i++)
        arr[i]=rand()%90+10;
    
    int begin=time(0);
    quickSort(arr, 0, SIZE-1); 
    int end=time(0);
    cout<<"\nTime = "<<end-begin<<endl;
    return 0; 
}

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}

