/*
 - Next Greater Element :
  		given an array, we have to find the next greater element for every element in that array
  		next greater element for an element 'a' is the first greater element on the right side of 'a'
  		if no greater element exist then print -1

 - Approach :
  		1. Using nested for loop, OUTER_LOOP for traversing the given array and INNER_LOOP for checking
     	   the condition
  		2. We check the condition (array[i] < array[j]), if it is true then we initialize
     	   new_array[i] to array[j] and use continue OUTER_LOOP
  		3. If (array[i] < array[j]) is false for every element of the array then we initialize new_array by -1
  		4. After traversing the whole array we get the new_array[] and printing it gives us the
           result
 */

import java.util.Scanner;

public class NextGreaterElement {

	//next_greater_element method
	public static void next_greater_element(int[] array, int n, int[] new_array) {

		OUTER_LOOP : for(int i = 0 ; i < n ; i++) {

			INNER_LOOP : for(int j = i + 1 ; j < n ; j++) {
				//Checking condition
				if(array[i] < array[j]) {
					new_array[i] = array[j];
					continue OUTER_LOOP;
				}
			}
	new_array[i] = -1;
		}
	}
	//main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements you want in the array : ");
		//Input the number of elements you want in the array
		int n = sc.nextInt();

		//Creating array of n elements
		int[] array = new int[n];
		//Creating another array for storing elements
		int[] new_array = new int[n];

		System.out.print("Enter all the elements : ");
		//Putting elements in the array
		for(int i = 0 ; i < n ; i++) {
			array[i] = sc.nextInt();
		}
		//Calling next_greater_element method
		NextGreaterElement.next_greater_element(array, n, new_array);

		//Printing array
		System.out.print("Result : ");
		for(int i = 0 ; i < n ; i++) {
			System.out.print(new_array[i] + " ");
		}
	}
}
/*
 - Test Cases :
      Input : Enter the number of elements you want in the array : 5
              Enter all the elements : 12 34 54 2 62
     Output : Result : 34 54 62 62 -1

 - Complexity Analysis :
 *  Time Complexity : O(n^2)
           We are using nested loops, so it iterates maximum 'n^2' times while traversing for loop

 *  Space Complexity : O(n)
           Auxiliary space : O(n)  +  input space : O(n)
 */
  
