#include <vector>
#include <math.h> // may need to use pow( )
#include <iostream>
using namespace std;

//Working for some cases... hard to explain just run it with ./a.out # where # is diff numbers each time (start with 1 and go up to see for yourself)
template <class Comparable>
void merge(vector<Comparable> &from, vector<Comparable> &temp, int part_index, int part_size) {

   int index2 = part_index + part_size;
   int index = part_index;
   int endPart = part_index + part_size;
   int endPart2 = part_index + (2 * part_size);
   
   for(int counter = index; counter < endPart2; counter++)
   {
      if(index >= endPart)
      {
         temp[counter] = from[index2];
         index2++;
      }
      else if (index2 >= endPart2)
      {
         temp[counter] = from[index];
         index++;
      }
      else if(from[index] < from[index2])
      {
         temp[counter] = from[index];
         index++;
      }
      else //if(index2 < endPart2)
      {
         temp[counter] = from[index2];
         index2++;
      }
   }
   
   //copy sorted temp back into origin
   for(int i = part_index; i < endPart2; ++i)
      from[i] = temp[i];
}

template <class Comparable>
void mergesort( vector<Comparable> &origin ) {
    
    int size = origin.size( );
    int mid, last;
    vector<Comparable> temp( size );  // this is only one temporary array.
    
    int part_index = 0, part_size = 1;
    bool unsorted = true;
    
    while(unsorted) {
        
        for(; part_index < size; part_index += (2*part_size))
        {
            last = part_index + (2 * part_size);
            mid = (part_index + last) / 2;
            //merge(origin, part_index, mid, last); 
            merge(origin, temp, part_index, part_size);
        }
        
        part_size *= 2;
        part_index = 0;
        
        if(part_size*2 > size)
            unsorted = !unsorted;
    }
}

