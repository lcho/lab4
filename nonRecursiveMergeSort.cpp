/**
 *  @file nonRecursiveMergeSort.cpp
 *  @description 
 *  @author Milan Novakovic
 *  @author Lance Cho
 *  @author Terence Schumacher
 */
#include <vector>
#include <iostream>
using namespace std;


/**---------------------mergesort--------------------------------------
 *  @brief mergesort method
 *  @description a non-recursive implementation of the merge sort
 *               that sorts an array using only one temp array
 *  @param array  the original array built in the lab4driver.cpp
 */
template <class Comparable>
void mergesort(vector<Comparable> &array){
    
    int lowList1 = 0;
    int tempSize = 0;
    int i, j, size, highList1, lowList2, highList2;
    int tempArray[array.size()];
    
    //lowList1 lower bound of first pair and so on
    for(size=1; size < array.size(); size=size*2 )
    {
        //Index for temp array
        while( lowList1+size < array.size() )
        {
            highList1=lowList1+size-1;
            lowList2=highList1+1;
            highList2=lowList2+size-1;
            if( highList2>=array.size() ) //highList2 exceeds the limlt of array
                highList2=array.size()-1;
            //Merge the two pairs with lower limits lowList1 and lowList2
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
            
            //Merging completed
            
            lowList1=highList2+1; //Take the next two pairs for merging
        }//End of while
        
        for(i=lowList1; tempSize<array.size(); i++){ //any pair left
            tempArray[tempSize]=array[i];
            tempSize++;
        }
        for(i=0;i<array.size();i++)
            array[i]=tempArray[i];
        
        // reset the lower index
        lowList1 = 0;
        // reset the temporary array size
        tempSize = 0;
        
    }//End of for loop
    
    
}//end mergesort
