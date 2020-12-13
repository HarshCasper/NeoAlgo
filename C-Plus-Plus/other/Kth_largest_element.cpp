/*
Q Kth largest element 

Given an array a[] and a number K where K is smaller than size of array, 
the task is to find the Kth largest element in the given array.
It is given that all array elements are distinct. */


#include <bits/stdc++.h>
using namespace std;

//find the kth largest Element
void kthLargestElement(int a[], int size, int k){

    priority_queue <int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < size; i++){
        minHeap.push(a[i]);
        
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    cout<< "Kth largest element in the array is: "<< minHeap.top();
}

int main()
{
    int size, k; 
    
    cout << "Enter the size of an Array : ";
    cin >> size;

    cout << "Enter the value of k : ";
    cin>> k;

    cout<< "Enter the elements of the array: " << endl;
    
    int a[size];
    

    for (int i = 0; i < size; i++){
        cin >> a[i];
    }

    kthLargestElement(a,size,k);  
    
    return 0;
}

/*
Input 
Enter the size of an Array : 7                                                                                                                
Enter the value of k : 3                                                                                                                      
Enter the elements of the array:                                                                                                              
7 5 9 8 6 4 10      

Output
Kth largest element in the array is: 8

Space complexity => O(k)
Time complexity => O(nlogk)
*/