/** If you wanted all the methods to compile tests in a main function
    Just #include yourfilename.h
    This is the .cpp of yourfilename.h
*/



#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include "nonRecMergeSort.h"
#define RANDOMMAX 100000
using namespace std;
/** generates random number */
int randomNumber(){
    int x = 0;
    x = rand() % RANDOMMAX;
    return x;
}//end randomNumber

/** sets random number inside of array */
void setArray(int b[], int x){
    int i = 0;
    while (i < x) {
        b[i] = randomNumber();
        i++;
    }//end while
}//end setArray

/** prints out the array */
void printArray(int a[], int x){
    int i = 0;
    cout << "{";
    while (i < (x-1)) {
        cout << a[i] << ", ";
        i++;
    }//end while
    cout << a[x] << "}"<< endl<<endl;
}//end printArray

/** recursive merge sort */
void mergesort(int array[], int low, int high){
    int x = high;
    if(low < high){
        int mid = (low + high)/2;
        mergesort(array, low, mid);
        mergesort(array, mid+1, high);
        merge(array, low, mid, high, x);
    }//end if
}//end mergesort


/**
 Merges two sorted array segments theArray[first..mid] and
 theArray[mid+1...last] into one sorted array.
 
 */
void merge(int array[], int first, int mid, int last, int x){
    int tempArray[x];
    int first1 = first;     //beginning of first subarray
    int last1 = mid;        //end of first subarray
    int first2 = mid+1;     //beginning of second subarray
    int last2 = last;       //end of second subarray
    
    //while both subarrays are not empty, copy the
    // smaller items into  the temporary array
    int index = first1;     //next available location in
    //temp array
    for(; (first1 <= last1)&&(first2 <= last2); ++index){
        //Invariant: tempArray[first...index-1] is in order
        if (array[first1]< array[first2]) {
            tempArray[index] = array[first1];
            ++first1;
        }
        else{
            tempArray[index] = array[first2];
            ++first2;
        }//end if
    }//end for
    
    //finish off the non-empty subarray
    
    //finish off the first subarray, if necessary
    for(; first1 <= last1; ++first1, ++index )
    {   //Invariant: the array is already in order
        tempArray[index] = array[first1];
    }//end for
    
    //finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        //Invariant: the array is already in order
        tempArray[index] = array[first2];
    }//end for
    
    //copy the results back into the original array
    for (index = first; index <= last; ++index) {
        array[index] = tempArray[index];
    }//end for
    
}//end merge

/** Swaps integers */
void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}//end swap


/** Choose a pivot for quicksort's partition algorithm
 and swaps  it with the first item in an array
 */
void choosePivot(int array[], int first, int last){
    int middle = (first + last)/2;
    swap(array[middle], array[first]);
    
}//end choosePivot

/** partitions the array for quick sort
 */
void partition(int array[], int first, int last, int& pivotIndex){
    choosePivot(array, first, last);        //find the pivot point
    int pivot = array[first];               //set a pivot
    int lastS1 = first;                     //pivot index
    int firstUnknown = first + 1;           //first value outside of pivot
    
    
    for (; firstUnknown <= last; ++firstUnknown) {
        if(array[firstUnknown] < pivot){
            ++lastS1;
            swap(array[firstUnknown], array[lastS1]);
        }
        
        //else item belongs in S2
        
    }//end for
    
    //decide a new pivot
    
    swap(array[first], array[lastS1]);
    pivotIndex = lastS1;
    
}//end partition

/** Sorts the items in an array into ascending order
 */
void quicksort(int array[], int first, int last){
    int pivotIndex;
    
    if (first < last){
        //Create the partition: S1, pivot, S2
        partition(array, first, last, pivotIndex);
        
        //sort regions S1 and S2
        quicksort(array, first, pivotIndex-1);
        quicksort(array, pivotIndex+1, last);
        
    }//end if
    
}//end quicksort

/** this is the timer
 */
double diffclock(clock_t   clock1, clock_t clock2)
{
    double  diffticks = clock2 - clock1;
    
    double diffms = (diffticks*10)/CLOCKS_PER_SEC;
    return diffms;
}//end diffclock

/** creates the worst case estimate of the sort
 */
double bigO(int n)
{
    double value = (n * (log(n)))/1000000;
    return value;
}//end bigO


double timeMe(function<void>& sort){
    clock_t begin = clock();
    sort;
    clock_t end = clock();
    double time = diffclock(begin, end);
    return time;
    
}


void nonRecMergeSort(int array[], int n){
    
    int lowList1 = 0;
    int tempSize = 0;
    int i, j, size, highList1, lowList2, highList2;
    int tempArray[n];
    
    /*lowList1 lower bound of first pair and so on*/
    for(size=1; size < n; size=size*2 )
    {
        /*Index for temp array*/
        while( lowList1+size < n)
        {
            highList1=lowList1+size-1;
            lowList2=highList1+1;
            highList2=lowList2+size-1;
            if( highList2>=n ) /* highList2 exceeds the limlt of array */
                highList2=n-1;
            /*Merge the two pairs with lower limits lowList1 and lowList2*/
            i=lowList1;
            j=lowList2;
            
            while(i<=highList1 && j<=highList2 )
            {
                if( array[i] <= array[j] ){
                    tempArray[tempSize]=array[i];
                    tempSize++;
                    i++;
                }
                else{
                    tempArray[tempSize]=array[j];
                    tempSize++;
                    j++;
                }//end if
                
            }//end while
            while(i<=highList1){
                tempArray[tempSize]=array[i];
                tempSize++;
                i++;}//end while
            while(j<=highList2){
                tempArray[tempSize]=array[j];
                tempSize++;
                j++;
            }//end while
            
            /**Merging completed**/
            
            lowList1=highList2+1; /*Take the next two pairs for merging */
        }/*End of while*/
        
        for(i=lowList1; tempSize<n; i++){ /*any pair left */
            tempArray[tempSize]=array[i];
            tempSize++;
        }
        for(i=0;i<n;i++)            //set the original array to the temp
            array[i]=tempArray[i];
        
    }/*End of for loop */
    
}//end myMerge


