/** starter code to test mergsort function
    It includes timing code 
    This code is not ideal and could be made more modular/readable
    @file lab4driver.cpp 
    @author MF & RCS
    @param size - the number of data elements to be sorted
    @return -1 if there are any problems, 0 otherwise
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
//#include "mergesort.cpp"   //  you must implement an iterative mergesort
using namespace std;

extern void mergesort( vector<int> &originalData );

/**  fill array with random numbers */
void initArray( vector<int> &array, int randMax ) {
  int size = array.size( );

  for ( int i = 0; i < size; ) {
    int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if ( array[j] == tmp ) {
        hit = true;
        break;
      }
    }
    if ( hit )
      continue;
    array[i] = tmp;
    i++;
  }
}

// array printing
void printArray( vector<int> &array, char arrayName[] ) {
  int size = array.size( );

  for ( int i = 0; i < size; i++ )
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}

// performance evaluation
int elapsed( timeval &startTime, timeval &endTime ) {
  return ( endTime.tv_sec - startTime.tv_sec ) * 1000000
    + ( endTime.tv_usec - startTime.tv_usec );
}

int main( int argc, char* argv[] ) {
  // verify arguments
                                                           
  if ( argc != 2 ) {
    cerr << "usage: a.out size" << endl;
    return -1;
  }

  // verify an array size
                                                       
  int size = atoi( argv[1] );
  if ( size <= 0 ) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // array generation
                                                           
  srand( 1 );
  vector<int> items( size );
  initArray( items, size );
  cout << "initial:" << endl;   // comment out when evaluating performance only
  printArray( items, "items" ); // comment out when evaluating performance only

  // mergesort
  struct timeval startTime, endTime;
  gettimeofday( &startTime, 0 );
  mergesort( items );
  gettimeofday( &endTime, 0 );
  cout << "elapsed time: " << elapsed( startTime, endTime ) << endl;

  cout << "sorted:" << endl;    // comment out when evaluating performance only
  printArray( items, "items" ); // comment out when evaluating performance only

  return 0;
}
