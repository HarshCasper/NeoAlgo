/* Cpp code for Sqrt Monotonic Binary Search,
   In this algorithm we will find the square root of a number `num`
   upto `p` digits after decimal using the binary search algorithm. */

#include <bits/stdc++.h>
using namespace std;

/* Function to find the square root of a number `num` */
float sqrt(int num, int p)
{
	int start = 0;	
	int end = num;		
	float ans = -1; 
	int mid;	
	while (start <= end)
	{
		/* find the middle element */
		mid = (start + end) / 2;

		/* return `mid` 
		   if `num` is a perfect square */
		if (mid * mid == num)
			return mid;

		/* if `mid*mid` is less than `num` */
		else if (mid * mid < num)
		{
			/* change the starting point to mid+1 
			   and update the answer */
			start = mid + 1;
			ans = mid;
		}

		/* if `mid*mid` is more than `num`,
		   change the end point to mid-1 */
		else
			end = mid - 1;
	}

	float temp = 0.1;

	/* This for loop will give `p` digits 
	   after the decimal to the `ans` */
	for (int i = 1; i <= p; i++)
	{
		while (ans * ans <= num)
			ans = ans + temp;

		ans = ans - temp;
		temp = temp / 10;
	}

	/* return answer */
	return ans;
}

/* Driver Function */
int main()
{
	int num;
	cout << "Enter the number : ";
	cin >> num;
	cout << "The square root of " << num << " is : " << sqrt(num, 3);
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
