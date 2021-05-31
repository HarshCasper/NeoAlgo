/*Relative Sort Array (Sorting an array according to the other) 

Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative 
positions of the elements in the first array are the same as the elements in the second array A2[ ].
Note: If elements are repeated in the second array, consider their first occurance only.
*/


//Initial template for C++
#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int>mp;
        //storing all the elements of first array in map.
        for(int i=0;i<N;i++)
        {
            mp[A1[i]]++;
        }
        int j=0;
        for(int i=0;i<M;i++)
        {
            //if any element of second array has value more than 0 in map, we
            //store those elements in array and decrement the count in map.
            while(mp[A2[i]]>0)
            {
                A1[j++]=A2[i];
                mp[A2[i]]--;
            }
        } 
        //iterating over the map which helps in storing
        //elements in increasing order.
        for(auto it:mp)
        {
            //we store the elements if their frequency is more than 0.
            if(it.second>0)
            {
                //storing elements as many times as their count in output array.
                while(it.second>0)
                {
                    A1[j++]=it.first;
                    it.second--;
                }
            }
        }
        //returning the output.
        return A1;
    } 
};
int main() 
{ 
	    int n, m;
	    cout<<"Enter size of both array: \n";
	    cin >> n >> m;                
	    vector<int> a1(n);
	    vector<int> a2(m);
	    cout<<"Enter elements of array A1: \n";
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];            
	    }
	    cout<<"Enter elements of array A2: \n";
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];            
	    }
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	    cout<<"Relative sorted array: \n";
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
}

/*
Sample Input/Output:

Input: Enter size of both array:
       11 4
       Enter elements of array A1:
       2 1 2 5 7 1 9 3 6 8 8
       Enter elements of array A2:
       2 1 8 3

Output: Relative sorted array:
	2 2 1 1 8 8 3 5 6 7 9 

Time complexity:  O(m+n)
Space complexity: O(n)    (Assuming n>m)

*/


