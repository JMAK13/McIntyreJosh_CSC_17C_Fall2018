/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 13, 2018, 11:12 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std; 

//Function Prototypes
int shellSort(int [], int);

int main(){
    
    srand(static_cast<unsigned int>(time(0)));
    
	int SIZE=20000000;
        int *arr=new int[SIZE];
        
        for(int i=0; i<SIZE; i++)
            arr[i]=rand()%90+10;
        
        int begin=time(0);
	shellSort(arr, SIZE);
        int end=time(0);
        
        cout<<"Time = "<<end-begin<<endl;

        delete [] arr;
        
	return 0; 
} 

/* function to sort arr using shellSort */
int shellSort(int arr[], int n) 
{ 
	// Start with a big gap, then reduce the gap 
	for (int gap = n/2; gap > 0; gap /= 2) 
	{ 
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted 
		for (int i = gap; i < n; i += 1) 
		{ 
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i]; 

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found 
			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 
			
			// put temp (the original a[i]) in its correct location 
			arr[j] = temp; 
		} 
	} 
	return 0; 
}


