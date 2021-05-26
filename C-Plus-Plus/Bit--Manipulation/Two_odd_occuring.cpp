// Two ocurring number

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements \n";
	cin>>n;
    vector<int>arr;
    int a;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	arr.push_back(a);
	}
   int xors = 0, res1 = 0, res2 = 0; 
        
        for (int i = 0; i < n; i++) 
        xors = xors ^ arr[i]; 
  
   
        int sn = xors & (~(xors - 1)); 
  
    
        for (int i = 0; i < n; i++) 
        { 
            if ((arr[i] & sn) != 0) 
                res1 = res1 ^ arr[i]; 
            else
                res2 = res2 ^ arr[i]; 
        } 
        
        
        cout <<  res1 << " " << res2;
	  
}

/*
Time Complexity: O(n) 
Space Complexity: O(1)
*/

/*Sample Input:
Example 1:- 
Enter number of elements
8
2 2 3 8 4 4 1 1
Example 2:-
Enter number of elements
7
1 1 2 2 5 3 3

Sample Output:
Example 1:- 
3 8
Example 2:-
5 0
*/

