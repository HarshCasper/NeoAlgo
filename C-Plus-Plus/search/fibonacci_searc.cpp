/*
                                              Fibonacci Search

Search for an element in a Sorted Array

Time Complexity : O(log(n))
Auxiliary Space : O(1) 

fibonacci series generalisation:
F(0) = 0
F(1) = 1
F(2) = F(1) + F(0) = 0+1 = 1 
F(n) = F(n-1)+F(n-2) for n>=2
*/

#include<bits/stdc++.h>
using namespace std;

int fibonacciSearch(int arr[],int n,int element)
{   
    /* Initializing fibonacci no */
    int fibM2 = 0;  //(m-2)th fibonacci no.
    int fibM1 = 1;  //(m-1)th fibonacci no. 
    int fibM = fibM1 + fibM2; //mth fibonacci no.

   /*finding smallest fibonacci no. greater than or equal to 
     n in Fibonacci sereies and storing it in fibM */ 

    while(fibM < n)
    {
        fibM2=fibM1;
        fibM1=fibM;
        fibM = fibM1+fibM2;
    }
    
    // to mark range elminated from front 
    int offset = -1;

    /* until there are elements to be inspected 
       we compare arr[fibM2] with element when fibM becomes 1 
       then fibM1 becomes 1 and fibM2 becomes 0 */

    while(fibM>1){
    
    // Check if fibM2 is valid location
    int i = min(offset+fibM2,n-1);
    
    /*
      when element is greater than value at index fibM2 ,
      we move 3 fibonacci variable ,1 fibonacci down reset offset to i.
      we drop approx front 1/3 of remaining array 
    */
    if(arr[i]<element)
    {   
        fibM = fibM1;
        fibM1 = fibM2;
        fibM2 = fibM - fibM1;
        offset = i;
    }
    /*
      when element is less than value at index fibM2 ,
      we move 3 fibonacci variable ,2 fibonacci down
      we drop approx rear 2/3 of remaining array 
    */
    else if(arr[i]>element)
    {
        fibM = fibM2;
        fibM1 = fibM1 - fibM2;
        fibM2 = fibM - fibM1;
    }
    /* if found return index */
    else return i;
    } 
    /* check for last array element */
    if(fibM1 && arr[offset+1]==element)
       return offset+1;
    
    /* element not found return -1*/
    return -1;   
}

int main()
{
    int n;  /* size of array */
    cout<<"Enter Size Of Arrary:"<<"\n";
    cin>>n;
    
    int arr[n]; /* array declaration */
    cout<<"Enter Elements In Array"<<"\n";
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int element;   /* Element that user want's to search */
    cout<<"Enter The Element To Be Searched"<<"\n";
    cin>>element;

    int index = fibonacciSearch(arr,n,element); /* Call fibonacci search function */

    if(index==-1)
    cout<<"Element Not Found"<<"\n";   /* if element is not present */
    else
    cout<<"Element Found At Array Index : "<<index;   /* if Present print index*/

   return 0; 
}

/*

Sample I/O:
1.
Enter Size Of Arrary:
5
Enter Elements In Array
1 6 10 11 78   
Enter The Element To Be Searched
78
Element Found At Array Index :

2.
Enter Size Of Arrary:
4
Enter Elements In Array
1 2 3 4 
Enter The Element To Be Searched
5
Element Not Found


*/
