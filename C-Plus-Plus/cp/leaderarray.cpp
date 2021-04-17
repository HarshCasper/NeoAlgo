/*
Program to find leaders in given array
Leaders are those elements where its right side element is less than current element
eg :- 1 3 2
so 3 and 2 will be the  leader as 3>2 which is its right side element and 1<3 so 1 is not a leader
and there is no element in right of 2 so 2 is also a leader

Duplicate values are not allowed eg 7 10 4 3 10 2 then its output will be 10 4 2 only
Equal values are also not allowed eg 7 10 10 4 3 2 then 10 4 3 2 will be the output.

 In this solution what we do is take a variable named ldr and assign it the n-1 value becoz
we already know that (n-1)th element is always a leader then we start traversing from right 
to left and check if the left element is greater than the current element and if the left element
is greater than current element we print it becoz its a leader
Basically instead of travelling from left to right we are travelling right to left 

So the output will be printed from right to left so we used sort so that it gets printed in the 
correct order. 
*/
#include <bits/stdc++.h>
using namespace std;

//Function to find the leader in the array
void leader(int arr[],int n)
{
    int ldr = arr[n-1];
    cout<<ldr;
    for(int i=n-2;i>=0;i--)
    {
        if(ldr<arr[i])
        {
            ldr = arr[i];    
            cout<<ldr;
        }
    }
}

//Driver Code
int main()
{
    int n;
    cin >> n;
    int arr[n]; 
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        leader(arr, n);
//Using sort to reverse the order in ascending order
        sort(arr,arr+n);

}

/*
Time Complexity :- O(n)

SAMPLE I/O:-

Input :- 
N=7
7 10 8 3 6 5 2
Output :-
2 5 6 8 10

Input :-
n=10
10 9 8 7 6 5 4 3 2 1

Output :-
1 2 3 4 5 6 7 8 9 10

*/