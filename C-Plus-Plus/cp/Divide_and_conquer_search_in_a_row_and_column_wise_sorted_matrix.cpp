/*Suppose we have a matrix of dimensions n x m.
We have to search the matrix for a given element if its present or not.
If present we need to return its position else return Not found.
We can easily do this question by traversing the entire array and search the element one by one
The time complexity is O(n*m)
But there is one additional feature given :
The matrix is row wise and column wise sorted i.e on moving from left to right in any row the elements are sorted and also on moving from top to bottom in any column the elements are sorted.

Example:
Input:
n:4
m:4
arr[][]:
10 20 30 40
11 21 31 41
12 22 32 42
13 23 33 43

element:22

Output: 3 2

Approach:We will take a pointer i=0 & j=m-1 at the top-right most corner of the matrix that is mid=arr[0][m-1].
if(mid==element)
Return the position i & j

else if(mid>element)
We know that in that particular column below mid all elements will also be greater so we need to shift one column before
j--

else (mid<element)
Now there are chances the we can find the element in that column below mid element hence
i++;

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

Time Complexity:O(n+m)
*/

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;





int main()
{
    
        int n;
        int m;
        cout<<"Enter the dimensions of the matrix:\n";
        cin>>n>>m;
        
        int arr[n][m];

        cout<<"Enter the elements of the row wise & column wise sorted matrix\n";
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          cin>>arr[i][j];
          
        int element;
          
        cout<<"Enter element to be searched\n";
        cin>>element;


       
        
        int i=0;
        int j=m-1;
        int mid;
        int f=0;
        

     while(i < n && j >= 0)//Base Condition
      {mid=arr[i][j];
          if(mid == element)
          {cout<<"Element found at : "<<i+1<<" "<<j+1<<"\n";
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
      cout<<"Not found"<<"\n";