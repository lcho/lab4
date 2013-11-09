//
//  main.cpp
//  lab4
//
//  Created by Terence Schumacher on 11/4/13.
//  Copyright (c) 2013 Terence Schumacher. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
using namespace std;



void timer();
void mergesort(int array[], int low, int high);
void quicksort();
void setArray(int b[], int x);
int randomNumber();
double bigO(int n);
double diffclock(clock_t   clock1, clock_t clock2);
void printArray(int a[], int x);
void merge(int array[], int first, int mid, int last, int x);
void choosePivot(int array[], int first, int last);
void partition(int array[], int first, int last, int& pivotIndex);
void quicksort(int array[], int first, int last);
void setTestArrays();




int main(int argc, const char * argv[])
{

    // insert code here...

// arrays
//---------------------------------------------------------------------
    
//MergeSort
    int anArray1[10];
    int anArray2[100];
    int anArray3[1000];
    int anArray4[10000];
    
//QuickSort
    int QanArray1[10];
    int QanArray2[100];
    int QanArray3[1000];
    int QanArray4[10000];
    
       
//NonRecursiveMergeSort
    int ManArray1[10];
    int ManArray2[100];
    int ManArray3[1000];
    int ManArray4[10000];

//set and print-merge sort arrays
//---------------------------------------------------------------------
    
    //set up an array with random values of 10
    setArray(anArray1, 10);
    //print it
    printArray(anArray1, 10);
    //set up an array with random values of 100
    setArray(anArray2, 100);
    //print it
    printArray(anArray2, 100);
  
    //set up an array with random values of 1000
   setArray(anArray3, 1000);
    //print it
    printArray(anArray3, 1000);
    //set up an array with random values of 10000
    setArray(anArray4, 10000);
    //print it
    printArray(anArray4, 10000);
    
    
    
//sets and prints-Quick Sort Arrays
//------------------------------------------------------------------
    cout << endl << "Quick Sort Arrays: "<< endl << endl;
    //set up an array with random values of 10
    setArray(QanArray1, 10);
    //print it
    printArray(QanArray1, 10);
    //set up an array with random values of 100
    setArray(QanArray2, 100);
    //print it
    printArray(QanArray2, 100);
    
    //set up an array with random values of 1000
     setArray(QanArray3, 1000);
     //print it
     printArray(QanArray3, 1000);
     //set up an array with random values of 10000
     setArray(QanArray4, 10000);
     //print it
     printArray(QanArray4, 10000);
    
    
    //set and print-non recursive merge sort arrays
    //---------------------------------------------------------------------
    
    //set up an array with random values of 10
    setArray(ManArray1, 10);
    //print it
    printArray(ManArray1, 10);
    //set up an array with random values of 100
    setArray(ManArray2, 100);
    //print it
    printArray(ManArray2, 100);
    
    //set up an array with random values of 1000
    setArray(ManArray3, 1000);
    //print it
    printArray(ManArray3, 1000);
    //set up an array with random values of 10000
    setArray(ManArray4, 10000);
    //print it
    printArray(ManArray4, 10000);


    cout << "-----------------------------------------" <<
    endl << endl << endl << endl << endl;
// for each of the arrays set up, mergesort
//----------------------------------------------------------
// 10
    //start the timer
    clock_t begin = clock();
    //run the recursive merge sort
    mergesort(anArray1, 0, 10);
    //stop the timer
    clock_t end = clock();
    //print results
    printArray(anArray1, 10);
    //save the time
   long double time10 = diffclock(begin, end);
    //print the time
    cout << "Time in ms: " << time10 << "ms!" << endl << endl;
    
// 100
    //start the timer
    clock_t begin2 = clock();
    mergesort(anArray2, 0, 100);
    //stop the timer
    clock_t end2 = clock();
    //print the array
    printArray(anArray2, 100);
    //save the time
   long double time100 = diffclock(begin2, end2);
    //print the time and save it
    cout << "Time in ms: " << time100 << "ms!" << endl << endl;
    
 
//1000
    //start the timer
    clock_t begin3 = clock();
    mergesort(anArray3, 0, 1000);
    //stop the timer
    clock_t end3 = clock();
    //print the array
    printArray(anArray3, 1000);
    //save the time
  long  double time1000 = diffclock(begin3, end3);
    //print the time and save it
    cout << "Time in ms: " << time1000 << "ms!" << endl << endl;
    
//10000
    //start the timer
    clock_t begin4 = clock();
    mergesort(anArray4, 0, 10000);
    //stop the timer
    clock_t end4 = clock();
    //print the array
    printArray(anArray4, 10000);
    //save the time
    long  double time10000 = diffclock(begin4, end4);
    //print the time and save it
    cout << "Time in ms: " << time10000 << "ms!" << endl << endl;



// for each of the arrays set up, quick sort
//--------------------------------------------------------------------------------
  
// 10
  //start the timer
  clock_t Qbegin = clock();
  //run the recursive merge sort
  mergesort(QanArray1, 0, 10);
  //stop the timer
  clock_t Qend = clock();
  //print results
  printArray(QanArray1, 10);
  //save the time
  long double Qtime10 = diffclock(Qbegin, Qend);
  //print the time
  cout << "Time in ms: " << Qtime10 << "ms!" << endl << endl;
  
// 100
  //start the timer
  clock_t Qbegin2 = clock();
  mergesort(QanArray2, 0, 100);
  //stop the timer
  clock_t Qend2 = clock();
  //print the array
  printArray(QanArray2, 100);
  //save the time
  long double Qtime100 = diffclock(Qbegin2, Qend2);
  //print the time and save it
  cout << "Time in ms: " << Qtime100 << "ms!" << endl << endl;

    
//1000
     //start the timer
     clock_t Qbegin3 = clock();
     mergesort(QanArray3, 0, 1000);
     //stop the timer
     clock_t Qend3 = clock();
     //print the array
     printArray(QanArray3, 1000);
     //save the time
     long  double Qtime1000 = diffclock(Qbegin3, Qend3);
     //print the time and save it
     cout << "Time in ms: " << Qtime1000 << "ms!" << endl << endl;
     
//10000
     //start the timer
     clock_t Qbegin4 = clock();
     mergesort(QanArray4, 0, 10000);
     //stop the timer
     clock_t Qend4 = clock();
     //print the array
     printArray(QanArray4, 10000);
     //save the time
     long  double Qtime10000 = diffclock(Qbegin4, Qend4);
     //print the time and save it
     cout << "Time in ms: " << Qtime10000 << "ms!" << endl << endl;
  
   
    // For each array, set up the Non-Recursive Merge Sort
    //---------------------------------------------------------------------------------
    
// 10
    //start the timer
    clock_t Mbegin = clock();
    //run the recursive merge sort
    mergesort(ManArray1, 0, 10);
    //stop the timer
    clock_t Mend = clock();
    //print results
    printArray(ManArray1, 10);
    //save the time
    long double Mtime10 = diffclock(Mbegin, Mend);
    //print the time
    cout << "Time in ms: " << Mtime10 << "ms!" << endl << endl;
    
// 100
    //start the timer
    clock_t Mbegin2 = clock();
    mergesort(ManArray2, 0, 100);
    //stop the timer
    clock_t Mend2 = clock();
    //print the array
    printArray(ManArray2, 100);
    //save the time
    long double Mtime100 = diffclock(Mbegin2, Mend2);
    //print the time and save it
    cout << "Time in ms: " << Mtime100 << "ms!" << endl << endl;
    
    
//1000
    //start the timer
    clock_t Mbegin3 = clock();
    mergesort(ManArray3, 0, 1000);
    //stop the timer
    clock_t Mend3 = clock();
    //print the array
    printArray(ManArray3, 1000);
    //save the time
    long  double Mtime1000 = diffclock(Mbegin3, Mend3);
    //print the time and save it
    cout << "Time in ms: " << Mtime1000 << "ms!" << endl << endl;
    
//10000
    //start the timer
    clock_t Mbegin4 = clock();
    mergesort(ManArray4, 0, 10000);
    //stop the timer
    clock_t Mend4 = clock();
    //print the array
    printArray(ManArray4, 10000);
    //save the time
    long  double Mtime10000 = diffclock(Mbegin4, Mend4);
    //print the time and save it
    cout << "Time in ms: " << Mtime10000 << "ms!" << endl << endl;
  
     //sorting times
     //---------------------------------------------------------------------------------
     cout << endl << endl << "-------------finished sorting!" << endl << endl;
     
 //10
     cout << "Time 10: " << endl 
     << " Worst Case: " << bigO(10) << endl
     << " MergeSort: " << time10 << endl
     << " QuickSort: " << Qtime10 << endl
     << "NR MergeSort: " << Mtime10 << endl << endl;
     
//100
     cout << "Time 100: " << endl
     << " Worst Case: " << bigO(100) << endl
     << " MergeSort: " << time100 << endl
     << " QuickSort: " << Qtime100 << endl
     << "NR MergeSort: " << Mtime100 << endl << endl;

//1000
     cout << "Time 1000: " << endl
     << " Worst Case: " << bigO(1000) << endl
     << " MergeSort: " << time1000 << endl
     << " QuickSort: " << Qtime1000 << endl
     << "NR MergeSort: " << Mtime1000 << endl << endl;
     
//10000
     cout << "Time 10000: " << endl
     << " Worst Case: " << bigO(10000) << endl
     << " MergeSort: " << time10000 << endl
     << " QuickSort: " << Qtime10000 << endl
     << "NR MergeSort: " << Mtime10000 << endl << endl;
    
    return 0;
}//end main

/** generates random number */
int randomNumber(){
    int x = 0;
    x = rand() % 100;
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
    while (i < x) {
        cout << a[i] << ", ";
        i++;
    }//end while
    cout << "}"<< endl<<endl;
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
