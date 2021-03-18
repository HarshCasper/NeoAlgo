/*
  Jump Game :
      We need to find the minimum number of jumps to reach the end of the array starting from the first
      element of the array, jumps value would be (-1) if we are not able to reach the end of the array

  Example : array = {2,3,0,1,4,1,1,2,0,3,5}
            minimum jumps = 5  {2 to 3, 3 to 4, 4 to 2, 2 to 3, 3 to 5}

  Explanation : (Greedy Solution)

   1. We will check if array's length is equal to or less than 1 or not
          i.e  if array's length is equal to 1 then we have only one element in the
          array and it is already at the end and program will return 0

   2. Now, we will check if the first element of array is 0 or not,
          i.e if it is 0 then we can't make any jump and program will return -1

   3. Now, we will use the for loop from i = 1 till array's length when (i == array.length - 1)
      this is true then we have reached the end and we will return jumps

   4. (i + array[i]) is the number of steps we take from the current position and we will compare it with
      max_Jump_Reach and then we will use Math.max which will compare both and return the maximum and assigns
      it to the max_Jump_Reach again

   5. We have used checks-- so that we can iterate the for loop till the checks == 0 and find the maximum
      value for max_Jump_Reach and afterwards we will update checks by (max_Jump_Reach - i)
 */
import java.util.Scanner;

public class JumpGame {
	// jumpGame method
	public static int jumpGame(int array[]) {

		//Initializing max_Jump_Reach, checks, jumps
		int max_Jump_Reach = array[0];
		int checks = array[0];
		int jumps = 1;

		// If array has only 1 element then it is already at last element so return 0
		if (array.length <= 1) {
			return 0;
		}
		// If first element is 0 then we can't jump to any other element in the array
		if (array[0] == 0) {
			return -1;
		}
		// Traverse array
		for (int i = 1; i < array.length; i++) {

			// Check if we reached last element or not
			if (i == array.length - 1) {
				return jumps;
			}
			// Update max_Jump_Reach
			max_Jump_Reach = Math.max(max_Jump_Reach, i + array[i]);

			checks--;

			if (checks == 0) {
				jumps++;
				if (i >= max_Jump_Reach) {
					return -1;
				}
				// Initialize checks again
				checks = max_Jump_Reach - i;
			}
		}
		return -1;
	}

	// main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// Number of elements we want to put in array
		int number = sc.nextInt();
		int[] array = new int[number];

		// Putting values in array using for loop
		for(int i = 0 ; i < array.length ; i++) {
			array[i] = sc.nextInt();
		}
		// Initializing the value returned by jumpGame method to jumps
		int jumps = JumpGame.jumpGame(array);

		System.out.println("minimum number of Jumps required : "+jumps);
	}
}
/*
- Test Cases :
   1.  Input : 7
               2 1 3 4 1 2 3
      Output : minimum number of Jumps required : 3

   2.  Input : 4
               1 0 0 3
      Output : minimum number of Jumps required : -1

   3.  Input : 1
               0
      Output : minimum number of Jumps required : 0

- Complexity Analysis :
    * Time Complexity : O(n)
		  We are using only one for loop, so it iterates maximum 'n' times while traversing for loop

    * Space Complexity : O(n)
		 Auxiliary space : O(1)  +  input space : O(n)
*/
