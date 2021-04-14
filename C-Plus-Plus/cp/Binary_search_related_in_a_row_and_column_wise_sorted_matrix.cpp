/*Problem Statment:
Given an n x m matrix, where every row and column is sorted in increasing order. 
Given a key, how to decide whether this key is in the matrix.

Approach:
We have a matrix of dimensions n x m.
We have to search the matrix for a given element(key) if its present or not.
If present we need to return its position else return Not found.
We can easily do this question by traversing the entire array and search the element one by one.In this case,the time complexity is O(n*m)

But there is one additional feature given :
The matrix is row wise and column wise sorted i.e on moving from left to right in any row the elements are sorted and also on moving from top to bottom in any column the elements are sorted.
Hence we can optimize our code.

The simple idea is to remove a row or column in each comparison until key is found. 

Example:
Input:
n:4
m:4
arr[][]:
10 20 30 40
11 21 31 41
12 22 32 42
13 23 33 43

key:22

Output: The key 22 is found at position :3 , 2

Algorithm:
We will take a pointer at i=0 & j=m-1 i.e. the top-right most corner of the matrix  mid=arr[0][m-1].

if(mid==key)
Return the position i & j

else if(mid>key)
We know that in that particular column below mid all elements will also be greater than key(hece it won't be found there) so we need to shift to one column backwards.
j--

else (mid<key)
Now there are chances the we can find the element in that column below mid element hence we shift to next row below it.
i++;
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int n;
        int m;
        //Getting matrix dimensions from user
        cout<<"Enter the dimensions of the matrix:\n";
        cin>>n>>m;
        int arr[n][m];
        cout<<"Enter the elements of the row wise & column wise sorted matrix\n";
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          cin>>arr[i][j];
          int key;
         //Getting key from user 
        cout<<"Enter element to be searched\n";
        cin>>key;
        int i=0;
        int j=m-1;
        int mid;
        int f=0;//Flag variable
    while(i < n && j >= 0)//Base Condition
      {   mid=arr[i][j];
          if(mid == element)
          {
            cout<<"Element found at : "<<i+1<<" "<<j+1<<"\n";
            f=1;
            break;
          }
          else if(mid > element)//If mid is greater than the element to be searched it won't be present in that column below mid as other elements will also be greater
           {
               j--;
           }
           else//If mid is less than the element to be searched it can be present in that row below mid 
           { 
               i++;
           }
      }
      if(f==0)
      cout<<"Not found";
    cout << endl;
    return 0;
}

/*
Dry run:
i=0;
j=m-1;
mid=arr[i][j]=40
element=22
22<49
j--;
mid=arr[i][j]=30;
22<30
j--;
mid=arr[i][j]=20;
22>20
i++;
22>21
mid=arr[i][j]=21;
i++;
mid=arr[i][j]=22;
22==22
Hence found
10 20 <-30 <-40
   |
11 21 31 41
   |
12 22 32 42
13 23 33 43

/*
In worst case we would have to traverse from one corner to another hence the
Time Complexity:O(n+m)
Space Complexity:O(1)
/*

