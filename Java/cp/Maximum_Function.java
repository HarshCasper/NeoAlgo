/*
  Maximum Function (in Java) :
     A sequence is given A1,A2,…,An (atleast 3 elements you need to give)
     Find the maximum value of the expression |Ax − Ay|+|Ay − Az|+|Az − Ax|
     over all triples of pairwise distinct valid indices (x,y,z).

  Approach :
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

		long e = sc.nextLong();
		long[] m = new long[(int)e];
		//putting elements in the array
		for(long t = 0 ; t<e ; t++) {
			m[(int)t] = sc.nextLong();
		}
		//sorting the array
		Arrays.sort(m);
		//calculating max
		long max = Math.abs(m[0]-m[1]) + Math.abs(m[1]-m[(int)e-1]) + Math.abs(m[(int)e-1]-m[0]);
		//printing max
		System.out.println("Result = "+max);
	}
}
/*
 - Test Cases :
   1.  Input : 5
               3 4 6 7 1
      Output : Result = 12

   2.  Input : 10
               7 5 3 9 1 2 7 3 8 9
      Output : Result = 16

 - Complexity Analysis :
   * Time Complexity : O(n)
       We are using only one for loop, so it iterates maximum 'n' times while traversing for loop

   * Space Complexity : O(n)
       Auxiliary space : O(1)  +  input space : O(n)
 */
