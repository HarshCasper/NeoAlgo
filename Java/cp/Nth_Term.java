/*
 - Nth Term :
       Print the Nth term of the sequence - 1,2,3,4,6,9,13,19,...
       example - input : Enter N (i.e the Nth term you want to find) : 15
                output : 277

 - Approach :
   1. After the 3rd term of the sequence you will notice that the next term is the sum of (Nth term - 1) and
      (Nth term - 3) i.e for finding the 7th term we will add 6th(7th - 1) and 4th(7th - 3) term which will
      give us sum as 9 + 4 = 13, hence 7th term is 13
   2. We will input the Nth term we want to find,after the input we used for loop which iterates 'n' times and checks the
      condition (i<4) if it is true then array[i] = i + 1, else array[i] = array[i-1] + array[i-3]
*/

import java.util.Scanner;

public class Nth_Term {

	//term method
	public static void term(int n) {
		//array of size n
		long[] array = new long[n];
		//for loop
		for(int i = 0 ; i<n ; i++) {
			//condition check
			if(i<4) {
				//if it is true then array[i] = i + 1
				array[i] = i+1;
			}else {
				//else array[i] = array[i-1] + array[i-3]
				array[i] = array[i-1] + array[i-3];
			}
		}
		//Output the Nth term of the sequence
		System.out.println("The "+ n + "th term of the sequence is : " + array[n-1]);
	}
	//main method
	public static void main(String[] args) {

		Scanner sc  = new Scanner(System.in);

		//Enter N (i.e the Nth term you want to find)
		System.out.print("Enter N : ");
		int n = sc.nextInt();

		//calling term method
		Nth_Term.term(n);
	}
}
/*
- Test Case :
      Input : Enter N : 94
     Output : The 94th term of the sequence is : 3606195506118921

- Complexity Analysis :
 * Time Complexity : O(n)
		  We are using only one for loop, so it iterates maximum 'n' times while traversing for loop

 * Space Complexity : O(n)
		 Auxiliary space : O(n)  +  input space : O(1)
*/
