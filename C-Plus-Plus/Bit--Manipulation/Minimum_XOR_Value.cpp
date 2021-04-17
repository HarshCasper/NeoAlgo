/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Explanation: According to the problem, we are given the size of the array and the numbers present in it. 
So we have to find two such numbers that are the elements of the array and their xor is the minimum in value in comparison to all the possible pairs of the array.

First we will take the input from the user and then sort it using the stl function. Then we will call the function Min_xor() for further calculation. 
The values passed to the function are the size of the array and the the sorted array itself. Then we have created 3 variables.
ele1 and ele 2 will store the value of the the elements that result in the minimum xor and ans stores the xor value.
We have also created a variable x that will store the temporary xor value for each pair and if it is less than the ans, then the value of x will be stored in ans.
After alll the operations, we will print the answer.
*/

#include<bits/stdc++.h>
using namespace std;

void Min_xor(int*A,int n)
{
    int ele1,ele2;
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int x=A[i]^A[i+1];
        if(x<ans)
        {
            ans=x;
            ele1=A[i];
            ele2=A[i+1];
        } 
    }
    cout<<"The Minimum xor value is : "<<ans<<endl;
    cout<<"The corresponding elements are : "<<ele1<<" and "<<ele2;
}

int main() {
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    sort(A,A+n);
    Min_xor(A,n);
    return 0;
}

/*Sample Input :
Example 1:
Enter the size of array : 4
Enter the array : [0, 2, 5, 7]
Output 1:
The Minimum xor value is : 2
The corresponding elements are : 0 and 2

Example 2:
Enter the size of array : 5
Enter the array : [0, 4, 7, 9, 8]
Output 2:
The Minimum xor value is : 1
The corresponding elements are : 8 and 9
*/
