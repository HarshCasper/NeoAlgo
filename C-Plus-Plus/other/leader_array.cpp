/*
Program to find leaders in given array
leaders are those elements where its right side element is less than him
eg :- 1 3 2
so 3 and 2 will be the  leader as 3>2 which is its right side element and 1<3 so 1 is not a leader
and there is no element in right of 2 so 2 is also a leader

Input :- 7 10 4 3 6 5 2
Output :- 10 6 5 2 
duplicate values are not allowed eg 7 10 4 3 10 2 then its output will be 10 4 2 only
equal values are also not allowed eg 7 10 10 4 3 2 then 10 4 3 2 will be the output
*/
//First we will see O(n*n) approach
#include <bits/stdc++.h>
using namespace std;

/*void leader(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag = true;//we assign a bool flag which will tell us all the leader elements 
        //when its true and when its false it return noting
        for(int j =i+1;j<n;j++)
          if(arr[i]<=arr[j])
          {
              flag = false;//if the cond is false it turns flag to false
              break;
          }
    if(flag==true)
       cout<<arr[i]<<"\t";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    leader(arr,n);  
}*/
/*
Now we will see a O(n) solution
 In this solution what we do is take a variable named ldr and assign it the n-1 value becoz
we already know that (n-1)th element is always a leader then we start traversing from right 
to left and check if the left element is greater than the current element and if the left element
is greater than current element we print it becoz its a leader
Basically instead of travelling from left to right we are travelling right to left 
*/
void leader(int arr[], int n)
{
    int currldr = arr[n - 1];
    cout << currldr;
    for (int i = n - 2; i >= 0; i--)
    {
        if (currldr < arr[i])
        {
            currldr = arr[i];
            cout << currldr;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    leader(arr, n);
    sort(arr, arr + n);
    return 0;   
}
//Input :- 7 10 4 3 6 5 2
//Output : -2 5 6 10