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

using namespace std;
void timer();
void mergesort(int array[], int low, int high);
void quicksort();
void setArray(int b[], int x);
int randomNumber();
void printArray(int a[], int x);
void merge(int array[], int first, int mid, int last, int x);

double diffclock(clock_t   clock1, clock_t clock2)
{
    double  diffticks = clock1 - clock2;
    double diffms = (diffticks*10)/CLOCKS_PER_SEC;
    return diffms;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    cout << "Hello, World!\n" << endl;
    cout << randomNumber() << endl;
    int anArray1[10];
    int anArray2[100];
    int anArray3[1000];
    int anArray4[10000];
  
    
    
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
    
    
    /**
        for each of the arrays set up, do this
     */
 
/** 10 */
    //start the timer
    clock_t begin = clock();
    //run the recursive merge sort
    mergesort(anArray1, 0, 10);
    //stop the timer
    clock_t end = clock();
    //print results
    printArray(anArray1, 10);
    //save the time
    double time10 = diffclock(begin, end);
    //print the time
    cout << "Time in ms: " << time10 << "ms!" << endl;
/** 100 */
    //start the timer
    clock_t begin2 = clock();
    mergesort(anArray2, 0, 100);
    //stop the timer
    clock_t end2 = clock();
    //print the array
    printArray(anArray2, 100);
    //save the time
    double time100 = diffclock(begin2, end2);
    //print the time and save it
    cout << "Time in ms: " << time100 << "ms!" << endl;
/** 1000 */
    //start the timer
    clock_t begin3 = clock();
    mergesort(anArray3, 0, 1000);
    //stop the timer
    clock_t end3 = clock();
    //print the array
    printArray(anArray3, 1000);
    //save the time
    double time1000 = diffclock(begin3, end3);
    //print the time and save it
    cout << "Time in ms: " << time1000 << "ms!" << endl;
/** 10000 */
    //start the timer
    clock_t begin4 = clock();
    mergesort(anArray4, 0, 10000);
    //stop the timer
    clock_t end4 = clock();
    //print the array
    printArray(anArray4, 10000);
    //save the time
    double time10000 = diffclock(begin4, end4);
    //print the time and save it
    cout << "Time in ms: " << time10000 << "ms!" << endl;
    //end test time
    
/** sorting times*/
    cout << endl << endl << "-------------finished sorting!";
    
    cout << "Times: " << endl << "10 elements = " << time10 <<
    endl << "100 elements = " << time100 << endl << "1000 "<<
    "elements = " << time1000 << endl << "10000 elements = " <<
    time10000 << endl;
    
    return 0;
}//end main

int randomNumber(){
    int x = 0;
    x = rand() % 100;
    return x;
}//end randomNumber

void setArray(int b[], int x){
    int i = 0;
    while (i < x) {
        b[i] = randomNumber();
        i++;
    }//end while
}//end setArray

void printArray(int a[], int x){
    int i = 0;
    cout << "{";
    while (i < x) {
        cout << a[i] << ", ";
        i++;
    }//end while
    cout << "}"<< endl<<endl;
}//end printArray

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
    }
    
    //finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        //Invariant: the array is already in order
        tempArray[index] = array[first2];
    }
    
    //copy the results back into the original array
    for (index = first; index <= last; ++index) {
        array[index] = tempArray[index];
    }
    
    
    
    
    
}//end merge
