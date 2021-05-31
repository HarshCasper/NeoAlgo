/*
Harry, a blind man has N distinct binary strings all of equal lengths. A binary string only contains '0's and '1's. 
The strings are numbered from 1 to N and all are distinct strings. Harry can only differentiate between these strings 
by touching them. In one touch Harry can identify one character at a position of any particular string from the set. 
Find the minimum number of touches Harry has to make so that he finds that all strings are different.
*/

#include<bits/stdc++.h>
#include <vector>
using namespace std;
int count_touches(int mask, vector<string>& arr, int n, int N, vector<vector<int>>& dp, int pos = 0)
{
	// When mask contains only 1 bit it means every string is recongnised.
	if (mask && (mask & (mask - 1)) == 0)
	{
		return 0;
	}

	// Returning infinite value.
	if (pos == n || mask == 0)
	{
		return 100000000;
	}

	// Adding memoization condition .
	if (dp[mask][pos] != -1)
	{
		return dp[mask][pos];
	}

	int mask1 = 0;
	int mask2 = 0;
	int cnt = 0;

	// Spliting the strings based on character at pos-th position.
	for (int i = 0; i < N; i++)
	{
		if (((1 << i)&mask))
		{
			cnt++;

			if (arr[i][pos] == '1')
			{
				mask2 |= (1 << i);
			}
			else
			{
				mask1 |= (1 << i);
			}
		}
	}

	int a = cnt + count_touches(mask1, arr, n, N, dp, pos + 1) + count_touches(mask2, arr, n, N, dp, pos + 1);
	int b = count_touches(mask, arr, n, N, dp, pos + 1);

	return dp[mask][pos] = min(a, b);

}
int minimumTouchesRequired(int N, vector<string> arr) {

	int n = arr[0].size();

	vector<vector<int>>dp((1 << N), vector<int>(n, -1));

	return count_touches((1 << N) - 1, arr, n, N, dp);
}


int main(){
    int N;
    cout<<"Enter the number of strings: ";
    cin>>N;
    vector <string> arr;
    cout<<"Enter the strings: "<<endl;
    for(int i = 0; i < N; i++){
        string inp;
        cin>>inp;
        arr.push_back(inp);
    }
    cout<<"The minimum number of touches required are: ";
    cout<< minimumTouchesRequired(N, arr);
}


/*
    Sample Input:
    Enter the number of strings: 3
    Enter the strings: 
    11100
    11101
    01100
    
    Sample Output:
    The minimum number of touches required are: 5

    Time Complexity:O((2^N) *n)
    Space Complexity:O((2^N) *n)

    N is the number of strings and n is the length of the string.

*/
