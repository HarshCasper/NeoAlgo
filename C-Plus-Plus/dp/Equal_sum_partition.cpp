/* 
 Problem description:

 Given a set of positive numbers, find if we can equally divide
 the set into two subsets such that the sum of elements in both the 
 subsets is equal.


                          APPROACH
---------------------------------------------------------------  
We will use Dynamic Programming approach to solve this problem.
Firstly, we will check whether the given array is of even length 
or not, if not the answer will be always NO, else we will check 
whether a subset lies in the array such that its sum is equal to 
half the sum of all the elements of the array, if such subset 
exists then answer would be YES, else answer is NO.


*/

#include<bits/stdc++.h>
using namespace std;


bool EqualPartition(int* array, int array_size ){
    int array_sum=0;
    
    //Finding the sum of all elements of array
    for(int i=0;i<array_size;i++){
        array_sum = array_sum + array[i];
    }
    
    // Checking whether array sum is odd or not, if odd, return false
    if((array_sum % 2) != 0){
        return false;
    }

    // Dividing array sum by 2
    array_sum = array_sum / 2;
    bool dp[array_size + 1][array_sum + 1]; //Declaring dp matrix

     //Initialising DP matrix with true and false
    for(int i=0; i<=array_size; i++){
        for(int j=0; j<=array_sum; j++){
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
            
        }
    }
    /*
      Filling DP matrix int dp[][], where dp[i][j] stores whether a given sum = j,
      can be obtained as a sum of elements of a subset, using the first (i+1) elements
      of array.
    */
    for(int i=1; i<=array_size; i++){
        for(int j=1; j<=array_sum; j++){
            if(dp[i][j] <= array_sum){
                dp[i][j] = ( dp[i][j-array[i-1]] ) || (dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*
     Return the last element of the DP matrix, which stores true, if sum = (sum of array/2)
     can be obtained as a sum of elements of a subset, using all the elements of array, else 
     it stores false.
     */
    return dp[array_size][array_sum];

}



int main(){
    int array_len;
    cin >> array_len;
    int my_array[array_len + 1];
    for(int i=0; i<array_len; i++){
        cin >> my_array[i];
    } 
    
    //Function call to check whether the array can be divided into two subsets of equal sum or not.
    if(EqualPartition(my_array, array_len)){
        cout<<"YES"<<"\n";

    }
    else{
        cout<<"NO"<<"\n";
    }
      
    
  
    
	return 0;
}


/*
Sample Test Cases:

Input: 
6
2 3 4 2 3 2
Output:
YES

Input:
5
4 2 5 3 1
Output:
NO

Time Complexity: O(sum*size)
Auxiliary Space: O(sum*size)
where,
sum = sum of array/2
size= size of array

*/
