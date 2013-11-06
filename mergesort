//
//  mergesort.cpp
//  CSS342-Lab4
//
//  Created by Lance Cho on 10/31/13.
//  Copyright (c) 2013 Lance Cho. All rights reserved.
//

#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

template <class Comparable>
void mergesort( vector<Comparable> &origin ) {
    
    int size = origin.size( );
    vector<Comparable> temp( size );  // this is only one temporary array.
    
    int part_index = 0, part_size = 1;
    bool unsorted = true;
    
    while(unsorted) {
        
        for(; part_index < size; part_index += (2*part_size))
        {
            merge(origin, temp, part_index, part_size);
        }
        
        part_size *= 2;
        part_index = 0;
        
        if(part_size >= size)
            unsorted = !unsorted;
    }
    
    // implement a nonrecursive mergesort only using vectors a and b.
}

template <class Comparable>
void merge(vector<Comparable> &from, vector<Comparable> &to, int part_index, int part_size) {
    int index2 = part_index + part_size;
    int index = part_index;
    
    for( ; index < part_index + part_size; index++)
    {
        if( from[index] < from[index2] )
        {
            to[index] = from [index];
            index++;
        }else
        {
            to[index] = from [index2];
            index2++;
        }
        
    }
    
    for(int i = 0; i < from.size(); i++)
    {
        from[i] = to[i];
    }
}




