#include<iostream>        //Header file
using namespace std;      //For cin and cout

/*
    Merge sort is an efficient, general-purpose, comparison-based sorting algorithm.
    It is a divide and conquer algorithm that was invented by John von Neumann in 1945.

    @author Aditya Saxena
    @since 26-7-2020
*/


//Implement merge function
void merge( int a[], int start, int end){

    int temp[10000];        //Temprory array to store while merging the arrays
    int mid= ( start + end ) / 2; 

    int i= start, j= mid+1, k= start;

    //Compare and fill temp
     while( i<= mid && j<= end ){

        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        
        else{
            temp[k++]=a[j++];
        }
    }

    //Fill remaining elements in temp
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<= end){
        temp[k++]=a[j++];
    }

    //Copy elements of temp in a
    for(int i= start; i<= end; i++){
        a[i]= temp[i];
    }

    return; 
} 

//Implement Merge Sort Function
void mergeSort( int a[], int start, int end){

    //Base Case
    //If start (index) crosses end (index), there are no elements to sort further, thus return
    if( start >= end ){
        return;
    }

    //Find the mid index
    int mid= ( start + end ) / 2;

    //Recursively sort the array in two halves
    //Sort first half
    mergeSort( a, start, mid);
    //Sort second half
    mergeSort( a, mid + 1, end);

    //Merge the sorted halves
    merge( a, start, end);

    return;

}


int main(){

    int n;                  
    cout<<"Enter the number of elements of the array to be sorted: ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements of the array: ";
    
    for(int i= 0; i<n; i++){        //For loop to input n elements into the array
        cin>>a[i];
    }

    //Call the merge sort function on the array - mergeSort( array_name, start, end);
    mergeSort( a, 0, n-1 );

    //Print the sorted array
    for(int i= 0; i< n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
