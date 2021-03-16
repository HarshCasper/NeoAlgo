/*
 * Jump Game :
 *
 * We need to find the minimum number of jumps to reach the end of the array starting from the first element of the array,
 * jumps value would be (-1) if we are not able to reach the end of the array
 *
 *
 * example : array = {2,3,0,1,4,1,1,2,0,3,5}
 *           minimum jumps = 5  {2 to 3, 3 to 4, 4 to 2, 2 to 3, 3 to 5}
 *
 *
 * Explanation : (Greedy Solution)
 *
 *  1. we will check if array's length is equal to or less than 1 or not
 *     i.e  if array's length is equal to 1 then we have only one element in the array and it is already at the end
 *          and program will return 0
 *
 *  2. Now, we will check if the first element of array is 0 or not,
 *     i.e if it is 0 then we can't make any jump and program will return -1
 *
 *  3. Now, we will use the for loop from i = 1 till array's length
 *     when (i == array.length - 1) this is true then we have reached the end and we will return jumps
 *
 *  4. i + array[i] is the number of steps we take from the current position and we will compare it with
 *     max_Jump_Reach and then we will use Math.max which will compare both and return the maximum and assigns
 *     it to the max_Jump_Reach again
 *
 *  5. we have used checks-- so that we can iterate the for loop till the checks == 0 and find the maximum
 *     value for max_Jump_Reach and afterwards we will update checks by (max_Jump_Reach - i)
 *
 * */
package NeoAlgo;

import java.util.Scanner;



public class JumpGame {


	public int jumpGame(int array[]) {



//Initializing max_Jump_Reach, checks, jumps


		int max_Jump_Reach = array[0]; // iterates 1 time

		int checks = array[0]; // // iterates 1 time

		int jumps = 1; // iterates 1 time



// If array has only 1 element then it is already at last element so return 0

		if (array.length <= 1) { // iterates 1 time

			return 0; // iterates 1 time

		}  // Starts from Line 57



// If first element is 0 then we can't jump to any other element in the array

		if (array[0] == 0) { // iterates 1 time

			return -1; // iterates 1 time

		}  // Starts from Line 67



// Traverse array


		for (int i = 1; i < array.length; i++) { // iterates (n+1) time as condition is checked (n+1) times


// Check if we reached last element or not


			if (i == array.length - 1) { // iterates n times

				return jumps; // iterates n times

			}  // Starts from Line 84


// Update max_Jump_Reach


			max_Jump_Reach = Math.max(max_Jump_Reach, i + array[i]); // iterates n times


// Decreasing checks by 1


			checks--; // iterates n times


// No more checks left


			if (checks == 0) { // iterates n times

				jumps++; // iterates n times


				if (i >= max_Jump_Reach) { // iterates n times

					return -1; // iterates n times

				}  // Starts from Line 111



// Initialize checks again


				checks = max_Jump_Reach - i; // iterates n times



			}  // Starts from Line 106


		}  // Starts from Line 78


		return -1;// iterates 1 time


	}  // Starts from Line 40



// main method


	public static void main(String[] args) {


		try {

// Using Scanner to get the input

			Scanner sc = new Scanner(System.in); // iterates 1 time


// Number of elements we want to put in array

			int number = sc.nextInt(); // iterates 1 time


			int[] array = new int[number]; // iterates 1 time



// Putting values in array using for loop


			for(int i = 0 ; i < array.length ; i++) { // iterates (n+1) times

				array[i] = sc.nextInt(); // iterates n times

			}  // Starts from Line 164


// Creating new object

			JumpGame object = new JumpGame(); // iterates 1 time


// Initializing the value returned by jumpGame method to jumps

			int jumps = object.jumpGame(array); // iterates 1 time


// Printing Jumps

			System.out.println("minimum number of Jumps required : "+jumps); // iterates 1 time


		}catch(Exception e) {


		}  // Starts from Line 186

	}  // Starts from Line 142

}  // Starts from Line 37


/*
 * Test Cases :
 *  1.  Input : 7
 *              2 1 3 4 1 2 3
 *     Output : minimum number of Jumps required : 3
 *
 *  2.  Input : 4
 *              1 0 0 3
 *     Output : minimum number of Jumps required : -1
 *
 *  3.  Input : 1
 *              0
 *     Output : minimum number of Jumps required : 0
 * */


/*
 * Time Complexity :
 *     By calculating every statement's iteration we got a function T(n)
 *     i.e T(n) = 12n + 16;
 *     and for larger values of n our function only depends on 'n'
 *     therefore,
 *                Average Time Complexity is O(n);
 *
 * Space Complexity :
 *     Auxiliary Space Complexity is O(1)
 *     Auxiliary Space Complexity is the extra space used by the algorithm not including space used by the input
 *
 *     Space Complexity is O(n)
 *     Space Complexity includes both Auxiliary and input space
 * */
