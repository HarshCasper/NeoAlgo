/*
PREVIOUS GREATER ELEMENT USING STACK
=========================================
An Efficient Approach to find Previous Greater Element for every 
element in an array. Given an array of Distinct Integers, find closest 
(Positive-Wise) greater on left of every element. If there is no 
greater element on left then print -1.

Time Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/* This function is used to check if top of the 
stack is smaller we remove it or if top is 
greater, then this element is previous greater
element and print it.
*/

void printPrevGreater(int arr[],int n){
    //Stack to store Previous Greater on top of stack.
    stack<int>s;

    /*Store first element of array to 
    check if top item is smaller then
    current item.*/
    s.push(arr[0]);

    /* This loop will help to find the 
       previous greater element from 
       the current value and simply print
       it and if not found print -1.
       NOTE : After every iteration whaterever the remaining element is 
       present at the top is Previous Greater and if stack is empty
       then previous Greater is -1. 
    */
    for(int i=0;i<n;i++){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();

        //pg : Previous Greater
        int pg=s.empty()?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}
// Driver's Code
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printPrevGreater(arr,n);
    return 0; 
}
/*
Testcase '1' :

N = 5
Input : arr[N] = {20, 30, 10, 5, 15}
Output : -1  -1  30  10 30
*/
