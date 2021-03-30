/* Write a program to segregate even and odd numbers in the given array of integers, .
 All the even numbers should be present first, and then the odd numbers.*/

 
#include <bits/stdc++.h>
using namespace std;


void segevenandodd(int ar[], int n)
{

	int i = -1;
    int j = 0;

	while (j != n) 
    {
		if (arr[j] % 2 == 0)
         {
			i++;

			
			swap(arr[i], arr[j]);

		}

		j++;
	}


	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{
	int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
	segevenandodd(ar, n);
	return 0;
}

/*

n = 9

Input ar = 3,9,5,8,1,2,7,6,4

Output = 2,4,6,8,1,3,5,7,9

Time Complexity : O(n)
Space Complexity: O(1)
*/
