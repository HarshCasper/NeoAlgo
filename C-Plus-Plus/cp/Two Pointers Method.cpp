// Given a sorted array A, size of N ( N elements) and a target value X, find if there exists any pair of elements in the Array such that their total sum is equal to X.

/*
Naive Solution will be O(N*N)
But we can solve it in O(N) by using Two pointers Method
One pointer starts from beginning and other from the end and they proceed towards each other simultaneously

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int ar[100009];

bool Pair_exist_by_TwoPointerMethod(int ar[], int N, int X)
{
    int i = 0, j = N - 1, cur_sum = 0;
    while(i < j)
    {
        cur_sum = ar[i] + ar[j];
        if(cur_sum == X)
        {
            return true;
        }
        else if(cur_sum < X)
        {
            i++;
        }
        else if (cur_sum > X )
        {
            j--;
        }
    }
    return false;
}


int main()
{
	int N, X;
	cout << "Input array size and target value\n";
	cin >> N >> X;
	for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    bool solve = Pair_exist_by_TwoPointerMethod(ar , N , X);
    if(solve)
        cout << "Pair found and their total sum is equal to target value\n";
    else
        cout << "Pair doesn't exist in the array\n";
}




/*

Standard Input and Output

Input array size and target value
6 70
10 20 35 50 75 80
Pair found and their total sum is equal to target value

Time Complexity : O(N)
Space Complexity : O(1)

*/



