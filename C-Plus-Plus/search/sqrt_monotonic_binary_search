// In this algorithm we will find the square root of a number `n` upto `p` digits after decimal using the binary search algorithm.

#include <iostream>
using namespace std;

// Function to find the square root of a number `n`
float sqrt(int n, int p)
{
	int s = 0;		// s denotes the starting point
	int e = n;		// e denotes the end point
	float ans = -1; // ans will store the final answer
	int mid;		// mid will store the middle element
	while (s <= e)
	{
		// find the middle element
		mid = (s + e) / 2;

		// return `mid` if `n` is a perfect square
		if (mid * mid == n)
			return mid;

		// if `mid*mid` is less than `n`
		else if (mid * mid < n)
		{
			// Change the starting point to mid+1
			s = mid + 1;
			// update the answer
			ans = mid;
		}

		// if `mid*mid` is more than `n`
		// Change the end point to mid-1
		else
			e = mid - 1;
	}

	float temp = 0.1;

	//This for loop will give `p` digits after the decimal to the `ans`
	for (int i = 1; i <= p; i++)
	{
		while (ans * ans <= n)
			ans = ans + temp;

		ans = ans - temp;
		temp = temp / 10;
	}

	//return answer
	return ans;
}

//Driver Function
int main()
{
	int n;
	cout << "Enter the number : ";
	cin >> n;
	cout << "The square root of " << n << " is : " << sqrt(n, 3);
}

/*
SAMPLE I/O =>

1.
Enter the number : 20
The square root of 20 is : 4.472

2.
Enter the number : 16
The square root of 16 is : 4

Time complexity : O(log(n))
Space complexity : O(n)

*/
