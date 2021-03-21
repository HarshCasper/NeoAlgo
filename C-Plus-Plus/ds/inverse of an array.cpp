/*
INVERSE OF AN ARRAY   
/*
If the array elements are swapped with their corresponding indices,
the array finally results is inverse of an array.

For Example,
If we have 4,0,2,3,1 in original array with indices 0,1,2,3,4 respectively,
so assume a blank array of same size. Now at 4th index, element in inverse array will be 0. 
Similarly, at 0th index, element in inverse array will be 1
and similar swapping for the rest of elemnts 
At last you will be getting 1,4,2,3,0 in inverse array. 

QUESTION-->

Input:
1)First line contains t, number of test cases.
2)Second line contains size of the original array.
3)Third line contains elements of the array.

Output:
1)contains t outputs, inverse array of each original array. */


#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n;
cin>>t;
while(t--){
cin>>n;
// created an original array of size n
int ori[n];
// created an inverse array of size n    
int inv[n]; 

for(int i=0 ; i<n; i++)
// taking inputs of original array
    {
    cin>>ori[i];           
    }

for(int i=0 ; i<n; i++)
/* j is temporary variable, after storing values of original array in j,
At inverse array we store corresponding indices of original array. */
    {    
    int j = ori[i];         
    inv[j] = i;         
    }

for(int i=0; i<n; i++)
//output the inverse array
    {
    cout<<inv[i]<<" ";      
    }

}
return 0;
}


/*
time complexity -: O(n)
 
Sample input:
2
5
4 0 2 3 1
3
0 1 2

Sample Output
1 4 2 3 0
0 1 2
*/

