/*
Description :
   Given an array of set , you have to find subset of that set using bitwise operators
*/

#include<bits/stdc++.h>
using namespace std;

// function to find the subset
void find_subset(int arr[] , int len)
{
    for(int i=0;i<(1<<len);i++)
    {
        for(int j=0;j<len;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int len;
    cout<<"Enter the size of array "<<endl;
    cin>>len;
    int arr[len];
    cout<<"Enter "<<len<<" in array :"<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    cout<<"The subset are : "<<endl;
    find_subset(arr,len);
    return 0;
}

/*
Time complexity : O(2^n)
Space complexity :O(1)
*/

/*
Input :
Enter the size of array 
4
Enter 4 in array :
1 2 3 4

Output :
The subset are : 
1
2
1 2
3
1 3
2 3
1 2 3
4
1 4
2 4
1 2 4
3 4
1 3 4
2 3 4
1 2 3 4
*/