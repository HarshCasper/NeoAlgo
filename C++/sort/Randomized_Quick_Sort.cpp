#include<iostream>        //Header file 
#include<ctime>           //To use time function as a seed for pseudo random generator
#include<cstdlib>         //For pseudo random number generator
using namespace std;      //For cin and cout

/*
    In Randomized Quick Sort, we use random number to pick the next pivot (or we randomly shuffle the array)
    and then apply quick sort on the array. Randomization is used here to eliminate the worst case time complexity
    of quick sort (that is, when the input array is already sorted).

    @author Aditya Saxena
    @since 27-7-2020
*/

//Implemention randomShuffle function
void randomShuffle( int a[], int start, int end ){

    //Seed time to the pseudo random number generator
    srand( time( NULL ) );

    int i, j;

    //Generate random number and bring them to range 0 to i+1 and store in j
    //Swap element at ith and jth index
    for( i= end; i >= 0; i-- ){

        j= rand() % ( i + 1 );
        swap(a[j],a[i]);

    }
}

//Implement partitionPivot function
int partitionPivot( int a[], int start, int end ){

    int i= start-1;
    int j= start;
    int pivot= a[end];

    //Traverse the array - whenever an element smaller than pivot occurs, swap it with (i+1)th element 
    for(j= start; j<= end-1; j++){
        
        if(a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }

    //Place the pivot element at i+1 (between smaller and larger elements)
    swap(a[i+1],a[end]);

    //Return position of pivot
    return i+1;
}

//Implement Quick Sort function
void quickSort( int a[], int start, int end ){

    //base case
    //If start (index) crosses end (index), there are no elements to sort further, thus return
    if( start >= end ){
        return;
    }

    //Taking end element as pivot, place the pivot element in its right position such that
    //elements left to the pivot are smaller than pivot and elements right to the pivot are greater than pivot
    //Return pivot's position (index)
    int p= partitionPivot( a, start, end );

    //Recursively sort left and right part of the pivot element
    //Left part of the pivot
    quickSort( a, start, p-1 );
    //Right part of the pivot
    quickSort( a, p+1, end);

    return;
}

int main(){

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    cout<<endl<<"Enter the elements of the array: ";
    
    for(int i= 0; i<n; i++){        //For loop to input n elements into the array
        cin>>a[i];
    }

    //Shuffle the array 
    randomShuffle( a, 0, n-1);

    //Call the quick sort function on the array - quickSort( array_name, start, end);
    quickSort( a, 0, n-1 );

    //Print the sorted array
    for(int i= 0; i< n; i++){
        cout<<a[i]<<" ";
    }


    return 0;
}

