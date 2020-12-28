/* Q Kth smallest element 

Given an array a[] and a number K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct. */


#include <bits/stdc++.h>
using namespace std;

//find the kth samllest Element
void kthSmallestElement(int arr[], int size, int k){

    priority_queue <int> maxHeap;
    
    for(int i = 0; i < size; i++){
        maxHeap.push(arr[i]);
        
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    cout<< "Kth smallest element in the array is: "<< maxHeap.top();
}

int main()
{
    int size, k;
     
    cout << "Enter the size of an Array : ";
    cin >> size;

    cout << "Enter the value of k : ";
    cin>> k;

    cout<< "Enter the elements of the array: " << endl;

    int arr[size];
    

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    kthSmallestElement(arr, size, k);  
    
    return 0;
}

/*
Input 
Enter the size of an Array : 7                                                                                                                
Enter the value of k : 3                                                                                                                      
Enter the elements of the array:                                                                                                              
7 5 9 8 4 6 10      

Output
Kth smallest element in the array is: 6 

Space complexity => O(k)
Time complexity => O(nlogk)
*/