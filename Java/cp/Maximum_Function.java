/*
 - Maximum Function (in Java) :
     A sequence is given A1,A2,…,An (atleast 3 elements you need to give)
     Find the maximum value of the expression |Ax − Ay|+|Ay − Az|+|Az − Ax|
     over all triples of pairwise distinct valid indices (x,y,z).

 - Approach :
     1. We need to sort the given array
     2. To find maximum difference of two elements we will subtract 1st element with the last element of the array (|Ax − Ay|)
     3. Next, we can take middle element as 2nd element of the array (Az)
     4. That means, Ax = 1st element of the sorted array, Ay = last element, Az = 2nd element
     5. Therefore, adding |Ax − Ay|+|Ay − Az|+|Az − Ax| will give maximum result everytime
 */

import java.util.Arrays;
import java.util.Scanner;

class MaximumFunction {
	//main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter number of elements you want in array");
		//Input the number of elements you want in the array
		long n = sc.nextLong();

		//Creating array of n Elements
		long[] array = new long[(int)n];

		System.out.println("Enter all the elements");
		//putting elements in the array
		for(long t = 0 ; t<n ; t++) {
			array[(int)t] = sc.nextLong();
		}
		//sorting the array
		Arrays.sort(array);
		//calculating max
		long max = Math.abs(array[0] - array[1]) + Math.abs(array[1] - array[(int)n-1]) + Math.abs(array[(int)n-1] - array[0]);
		//printing max
		System.out.println("Result = " + max);
	}
}
/*
 - Test Cases :
    1.  Input : Enter number of elements you want in array
                10
                Enter all the elements
                7 5 3 9 1 2 7 3 8 9
       Output : Result = 16

 - Complexity Analysis :
    * Time Complexity : O(n)
         We are using only one for loop, so it iterates maximum 'n' times while traversing for loop

    * Space Complexity : O(n)
         Auxiliary space : O(1)  +  input space : O(n)
 */
 
