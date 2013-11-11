/** #include this file to test on main.cpp
    #include yourfilename.h
    Make sure to change and include the .cpp
*/

//  lab4Tester
//
//  Created by Terence Schumacher on 11/8/13.
//  Copyright (c) 2013 Terence Schumacher. All rights reserved.
//

#ifndef __lab4Tester__nonRecMergeSort__
#define __lab4Tester__nonRecMergeSort__

#include <iostream>

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
void nonRecMergeSort(int array[], int n);



#endif /* defined(__lab4Tester__nonRecMergeSort__) */
