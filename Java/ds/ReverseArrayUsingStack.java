/*
  Stack is linear data structure used to store elements in computer's memory.
  It follows LIFO(Last In First Out) rule. In java we have collection framework
  which provides stack class and this stack class extends vector class which itself implements list
  interface, collection interface. For this problem we are going to use this Stack class of collection framework.
  Firstly we will push all the elements of an array in the stack
  and then we will perform pop operation till the stack becomes empty.
  It will give us reversed array because the last element which was pushed
  inside the stack will pop out first and the first element will come out last.
 */

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class ReverseArrayUsingStack {
	public static void main(String args[]) {
		  // creating a stack using collection framework of java
	      Stack<Integer> stack = new Stack<Integer>();
	      Scanner in = new Scanner(System.in);
	      System.out.println("Enter number of elements of Array:");
	      int n = in.nextInt();
	      int[] arr = new int [n];
	      System.out.println("Enter the elements of Array:");
	      for(int i=0; i<n; i++) {
	          arr[i] = in.nextInt();
	      }
	      //pushing all the elements of array in stack
	      for(int i=0; i<n; i++) {
	         stack.push(arr[i]);
	      }
	      // creating a new array to hold the reversed array
	      int[] reverseArray = new int[n];
	      for(int i=0; i<n; i++) {
	         reverseArray[i] = stack.pop();
	      }
	      System.out.println("Reversed array is: "+Arrays.toString(reverseArray));
	   }
}

/*
Enter number of elements of Array:
9
Enter the elements of Array:
12
2
67
3
45
1
2
9
6
Reversed array is :[6, 9, 2, 1, 45, 3, 67, 2, 12]
Time Complexity - O(n), here n is number of elements. 
Space Complexity - O(n), because we are using stack.
*/
