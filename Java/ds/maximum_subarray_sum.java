/*Program To illustate the Maximum Sum of array in Circular Form*/


import java.io.*;  //import of header file
import java.util.*;

class MaximumofCircularSum {
	
	
	static int maxCircularSum(int Givenarray[])// Function that will give maximum sum
	{
		int len = Givenarray.length;

		
		int maximum_kadane_sum = kadane(Givenarray);//Direct Function using Kadane Algo

	
		/*MAximum sum incuding Corner Cases*/
		int wrap = 0;
		for (int i = 0; i < len; i++) {
			wrap += Givenarray[i]; // Calculate array-sum
			Givenarray[i] = -Givenarray[i]; // invert the array (change sign)
		}
          /*Apprpach --> array_sum  - (-maximum sub array sum of inverted array)*/
		
		wrap = wrap + kadane(Givenarray);

		
		return (wrap > maximum_kadane_sum) ? wrap : maximum_kadane_sum;
	}


	static int kadane(int a[])
	{
		int length = a.length;
		int maximum_till_now = 0, max_ending_here = 0;
		for (int i = 0; i < length; i++) {
			max_ending_here = max_ending_here + a[i];
			if (max_ending_here < 0)
				max_ending_here = 0;
			if (maximum_till_now < max_ending_here)
				maximum_till_now = max_ending_here;
		}
		return maximum_till_now;
	}

	public static void main(String[] args)
	{
		int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
		System.out.println("Maximum sum: " + maxCircularSum(a));
	}
} /* This code is contributed by Akshay Sharma*/
