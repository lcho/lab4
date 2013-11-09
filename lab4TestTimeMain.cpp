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
#define TEN 10
#define HUNDRED 100
#define CASE1 100000
#define CASE2 400000
#define CASE3 1000000
#include "nonRecMergesort.h"
using namespace std;

//#################################
//  Methods
//#################################




int main(int argc, const char * argv[])
{
    
    // insert code here...
    
      //MergeSort
      int anArray1[CASE1];
      int anArray2[CASE2];

      //QuickSort
      int QanArray1[CASE1];
      int QanArray2[CASE2];
    
      //NonRecMergeSort
      int ManArray1[CASE1];
      int ManArray2[CASE2];
    
    //----------MERGESORT-----------------------
    //set up an array with random values of 10
    setArray(anArray1, CASE1);
    //print it
    printArray(anArray1, CASE1);
    //set up an array with random values of 100
    setArray(anArray2, CASE2);
    //print it
    printArray(anArray2, CASE2);
    
    
    //-----------QUICKSORT----------------------
    //set up an array with random values of 10
    setArray(QanArray1, CASE1);
    //print it
    printArray(QanArray1, CASE1);
    //set up an array with random values of 100
    setArray(QanArray2, CASE2);
    //print it
    printArray(QanArray2, CASE2);
    
    
    //-----------------NONRECURSIVEMERGESORT---------
    //set up an array with random values of 10
    setArray(ManArray1, CASE1);
    //print it
    printArray(ManArray1, CASE1);
    //set up an array with random values of 100
    setArray(ManArray2, CASE2);
    //print it
    printArray(ManArray2, CASE2);
   
    //----------MERGESORT-----------------------
     //start the timer
     clock_t begin = clock();
     //run the recursive merge sort
     mergesort(anArray1, 0, CASE1);
     //stop the timer
     clock_t end = clock();
     //print results
     printArray(anArray1, CASE1);
     //save the time
     long double time = diffclock(begin, end);
    //start the timer
    clock_t begin2 = clock();
    //run the recursive merge sort
    mergesort(anArray2, 0, CASE2);
    //stop the timer
    clock_t end2 = clock();
    //print results
    printArray(anArray2, CASE2);
    //save the time
    long double time2 = diffclock(begin2, end2);
    
    //------------QUICKSORT----------------------
    //start the timer
    clock_t Qbegin = clock();
    //run the recursive merge sort
    mergesort(QanArray1, 0, CASE1);
    //stop the timer
    clock_t Qend = clock();
    //print results
    printArray(QanArray1, CASE1);
    //save the time
    long double Qtime = diffclock(Qbegin, Qend);
    //start the timer
    clock_t Qbegin2 = clock();
    //run the recursive merge sort
    mergesort(QanArray2, 0, CASE2);
    //stop the timer
    clock_t Qend2 = clock();
    //print results
    printArray(QanArray2, CASE2);
    //save the time
    long double Qtime2 = diffclock(Qbegin2, Qend2);
    
    //-------------NONRECURSIVEMERGESORT-----------------
    //start the timer
    clock_t Mbegin = clock();
    //run the recursive merge sort
    mergesort(ManArray1, 0, CASE1);
    //stop the timer
    clock_t Mend = clock();
    //print results
    printArray(ManArray1, CASE1);
    //save the time
    long double Mtime = diffclock(Mbegin, Mend);
    //start the timer
    clock_t Mbegin2 = clock();
    //run the recursive merge sort
    mergesort(ManArray2, 0, CASE2);
    //stop the timer
    clock_t Mend2 = clock();
    //print results
    printArray(ManArray2, CASE2);
    //save the time
    long double Mtime2 = diffclock(Mbegin2, Mend2);
    
    
    cout << "Time "<< CASE1<<": " << endl
    << " Worst Case: " << bigO(CASE1) << endl
    << " MergeSort: " << time << endl
    << " QuickSort: " << Qtime << endl
    << "NR MergeSort: " << Mtime << endl << endl;
    
    
    cout << "Time "<< CASE2<<": " << endl
    << " Worst Case: " << bigO(CASE2) << endl
    << " MergeSort: " << time2 << endl
    << " QuickSort: " << Qtime2 << endl
    << "NR MergeSort: " << Mtime2 << endl << endl;
    
    
    return 0;
    }//end main
