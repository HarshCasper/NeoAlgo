/* PROBLEM LINK: https://www.codechef.com/MARCH21C/problems/SPACEARR

**The rules of the game are as follows:
*Initially, a sequence a1,a2,…,aN is given.
*The players alternate turns.
*In each turn, the current player must choose
*an index i and increment ai, i.e. change ai to ai+1.
*Afterwards, if there is no permutation p1,p2,…,pN of the
*integers 1 through N such that ai=pi holds for each valid
*i,the current player loses.
*Otherwise, the game continues with the next turn.
*/

// Code
#include<bits/stdc++.h>
using namespace std;
//Function Code to Find Result of Game
int Game(int arr[],int n)
{
	int sum = 0, c = 0;
        for (int i = 0; i < n; i++) {
	//Cheking if index is graeter or less than element of array  at that position
	    if (arr[i] > (i + 1))
	    { 
        // true, increase value of c  i.e. count
		c = 1;                   
		break;
	     }
	//if not,take the sum of difference of index and array at that index.
	    sum += abs(arr[i] - (i + 1));    
	}
	//c is 1 i.e. arrayy is greater than element of array
	if (c == 1) 
	{
	//second player wins.
	    cout << "Second" << endl;       
	}
	else {
	    // if sum is even.
	  if (sum % 2 == 0)    
	   // second is winner.
	    cout << "Second" << endl;  
	  else
          // otherwise first will win.
	    cout << "First" << endl;  
		}
}
//Driver Code
int main() 
{
	//No of test Cases.
	int t;  
	cin >> t;
	while (t--) {
		 // No of elements in array
		int n;     
		cin >> n;
		int arr[n];
		 // i as Index of Array
		for (int i = 0; i < n; i++)           
			cin >> arr[i];		
                 //Sorting the Array
		sort(arr, arr + n);    
		//Finding who will win 
		Game(arr,n);
	}
	return 0;
}
/*
Example Input
4
4
1 2 3 3
4
1 1 3 3
5
1 2 2 1 5
3
2 2 3
Example Output
First
Second
Second
Second

Time complexity: 0.06 sec using above algo, "MAX time complexity can be 1 sec "
Memory used: 6.5 MB uisng above algo, MAx space complexity for his problem is: 50000 Bytes"
*/


