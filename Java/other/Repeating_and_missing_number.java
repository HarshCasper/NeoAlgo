/*
PROBLEM STATEMENT:
Given an array, arr of size n with elements ranging from 1 to n. In the given array, one number(from 1 to n) is missing and one is repeating.
For example: for n = 6, given array is 1 6 3 5 1 2, in this array 4 is missing and 1 is repeating.
The task is to find these repeatng and missing numbers in the array.

APPROACH:
The approach is to simply use the mathematical formulas for summation of n numbers:
sum of n elements, sumn = n*(n+1)/2
and sum of squares of n elements, sumsqn = n*(n+1)*(2*n+1)/6
Now, let us assume x is the repeating number and y is the missing number
total denotes the sum of all the numbers present in the array, and totalsq denotes the sum of squares of numbers present in the array.
Therefore, we get
sumn = total - x + y, i.e.,
=> x - y = total - sumn ----- (1)
Also, 
sumsqn = totalsq - x^2 + y^2
=> sumsqn = totalsq - ((x + y)*(x - y))	
=> sumsqn = totalsq - ((x + y)*(total - sumn))		{using (1)}
=> x + y = (sumsqn - totalsq)/(sumn - total) ----- (2)
Now, we have two equations and two variables, therfore these equations can easily be solved. The values of x and y are:
x = (((sumsqn - totalsq)/(sumn - total)) + total - sumn)/2
y = x - total + sumn
*/

import java.util.Scanner;
import java.lang.Math;
class array
{
	//function to find repeating and missing number in an array
	public static void RepMissNum(int[] arr, int n)
	{
		// sum of n numbers
		int sumn = n*(n+1)/2;
		// sum of numbers present in the array
		int total = 0;
		for(int i = 0; i < n; i++){
			total += arr[i];
		}
		// sum of squares of n numbers
		int sumsqn = n*(n+1)*(2*n+1)/6;
		int totalsq = 0;
		// finding sum of squares of numbers present in the array
		for(int i = 0; i < n; i++){
			totalsq += Math.pow(arr[i], 2);
		}
		// Using formulas mentioned above to find the repeating and missing numbers
		int rep = (((sumsqn - totalsq)/(sumn - total)) + total - sumn)/2;
		int miss = rep - total + sumn;
		System.out.println("Repeating number is: " + rep);
		System.out.print("Missing number is: " + miss);
	}

	public static void main(String[] args)
	{
		System.out.print("Enter size of the array: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println("Enter elements of array: ");    
		int arr[] = new int[n];          
		for(int i = 0; i < n; i++){
			arr[i] = sc.nextInt();
		}

		RepMissNum(arr, n);
	}
}

/*
TEST CASE:
Input:
8
[6, 2, 7, 4, 5, 1, 6, 8]
Output:
Repeating number is: 6
Missing number is: 3

TIME COMPLEXITY: O(n), due to  for loop used to calculate sum of numbers in the array, where 'n' denotes size of array
SPACE COMPLEXITY: O(1), no extra space used.
*/