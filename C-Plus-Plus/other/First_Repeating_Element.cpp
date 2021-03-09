/*First Repeating Element Algorithm is one of the famous algorithm with the view point of interviews in FAANG companies.
This algorithm helps to find the first repeating element in an array of integers, i.e.,
an element occurs more than once and whose index of first occurence is smallest. 

Base Idea: To check if an element is repeating, we maintain an array idx[] which stores the first occurrence
(index) of a particular  element a[i]  */

/*1. Initialise the idx[] with -1 and minidx with INT_MAX 
2. Keep updating idx[], while traversing the given array */


#include<bits/stdc++.h>     //header file
#include<climits>       //header file
using namespace std;        //for cin and cout

//function for finding First Repeating Element
void FirstRepeatingElement(int a[], int n){

    const long int N = 1e6+2; // we declare such big value of N so that constraints could be satisfied
    int idx[N];     //declaring an array idc of size N
    for(int i=0; i<N; i++){     //initialising array elements value
        idx[i]=-1;
    }

    int minidx=INT_MAX;     //INT_MAX will assign the maximum possible value available to minidx
    int element = -1;

    //for loop for traversing the elements of array idx and updating idx[i]
    for(int i=0; i<n; i++){     
        if(idx[a[i]] != -1){
            minidx = min(minidx, idx[a[i]]);
            element = a[i];
        } else {
            idx[a[i]] = i;
        }
    }

    if(minidx==INT_MAX){
        cout<<"-1"<<endl;
    } else {
        cout<<"The first repeating element is "<<element<<endl;
        cout<<"The number of times "<<element<<" is repeating: "<<minidx+1<<endl;
    }

    return;
}

int main(){

    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //calling out First repeating element function
    FirstRepeatingElement(arr, n);

    return 0;
}


/*Test Case

//Input

Enter the number of elements of the array: 7
Enter the elements of the array: 1 5 3 4 3 5 6

//Output
The first repeating element is 5
Number of times 5 is repeating: 2

//Time Complexity - O(N) where N is the size of the array

*/
