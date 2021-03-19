/* 
  Given an array containing only 0s and 1s,
  find the largest subarray which contains equal no of 0s and 1s.
  This problem is going to reduce into the problem
  of finding length of longest subarray with 0 sum. 
  The concept of taking cumulative sum,
  taking 0’s as -1 will help us in optimizing the approach. 
  This is a very important question from interciew point of
  view as it is a combination of trick,prefix sum and hashing.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/* maxLen function returns the largest subarray with equal
   number of 0 and 1 */

void maxLen(int a[],int n){
	
/* create an empty map to store the ending index of the first subarray
   having some sum */
    unordered_map<int, int>ump;
/* to handle the case when a
   subarray with zero-sum starts from index 0*/
    ump[0] = -1;
     
// preSum stores the prefix sum ,ans stores the maximum length
	int preSum=0,ans=0;
	
// stores ending index of the maximum length subarray having zero-sum
    int ending_index = -1;
	
	for(int i=0;i<n;i++){
		
		// sum of elements so far (replace 0 with -1)
        preSum += (a[i] == 0)? -1 : 1;
        
		// if the sum is seen before
        if (ump.find(preSum) != ump.end())
        {
            /* update length and ending index of maximum length
                subarray having zero-sum */
            if (ans < i - ump[preSum])
            {
                ans = i - ump[preSum];
                ending_index = i;
            }
        }
        /* if the sum is seen for the first time, insert the sum with its
           index into the map */
        else {
            ump[preSum] = i;
        }
	}
	//Print the subarray
	if(ending_index!=-1)
	cout<<"largest subarray with equal number of 0 and 1 :" <<"[" << ending_index - ans + 1 << ", " << ending_index << "]";
    else
    cout<<"No subarray of equal number of 1's and 0's present"<<endl;
}
int main(){
   int n;
   cout<<"Enter the size of array"<<endl;
   cin>>n;	
   int a[n];//declaring an array of n elements
   cout<<"Enter the elements of the array";
   for(int i=0;i<n;i++)
      cin>>a[i];
   maxLen(a,n);
   return 0;
    }
/*
   Time Complexity: O(n)
   Auxilary Space complexity: O(n)

   Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
   Output: 1 to 6 
   (Starting and Ending indexes of output subarray)
   Input: arr[] = {1, 1, 1, 1}
   Output: No such subarray
   Input: arr[] = {0, 0, 1, 1, 0}
   Output: 0 to 3 Or 1 to 4
*/
