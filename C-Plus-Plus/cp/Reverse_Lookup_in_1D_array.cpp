/*
Problem : 
	Given an array of size N. Find the total sum of all the subarrays in the array.

-->Efficient Method : (USING REVERSE LOOKUP)
	-> Find the count of subarrays where a particular element is included.
	-> Once we have the repetition number, we can multiply it with the value of element to get its contribution.
	-> For an element with value 'X' at i-th position :-
	    -- the number of subarrays starting from index 0 to i = i + 1 
	    -- the number of subarrays ending on indices from i to N-1 = N - i
    -> The total contribution by X = X * repetitions  = X * ((i + 1) * (N - i)).
    -> Total time complexity => O(N).

Note :- 
Modular arithmethic to avoid overflows:
-> (a + b) % M = ((a % M) + (b % M)) % M
-> (a * b) % M = ((a % M) * (b % M)) % M
where, M = 10^9 + 7
*/

#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

/* function subset_sums() calculates the total sum of all subsets. 
   contribution variable denotes the contribution given by each element in the array.    
*/
long long subset_sums(vector<int>& array, int n){
    long long sum = 0, contribution;
    for (int i = 0; i < n; i++) {
        contribution = (((i+1) % M * (n-i) % M) % M * array[i] % M) % M;
        sum = ((sum % M) + (contribution % M)) % M;
    }
    return sum;
}

int main()
{
    int n, value;
    long long total_sum;
    vector<int> array;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> value;
        array.push_back(value);
    }

    // calculating subset sums
    total_sum = subset_sums(array, n);
    cout << total_sum << endl;

    return 0;
}


/*
Input : 
6
2 3 4 7 8 9

Output:
308

Time Complexity : O(n)
Space Complexity : O(1)
*/
