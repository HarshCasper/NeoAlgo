/*  PROBLEM STATMENT:
  * Given an array of length n .The task is to reverse the elements of an array.*/

import java.util.Scanner;
public class reverseOfArray 
{
	   // Driver Code
	     public static void main(String[] args) 
	     {
	    	 
		        Scanner sc = new Scanner(System.in);
		        
		        //Size input from user
		        System.out.print("Enter number of elements in the array :");
		        int n = sc.nextInt();
	       
	            int array[] = new int[n];
	        
	            int rev[] = new int[n];
	        
	            System.out.println("Enter "+n+" elements :  ");
	            //Elements input from user
	            for(int i=0; i < n; i++)
	        {
	            array[i] = sc.nextInt();
	        }
	        
                reverse(array, array.length);
         
                if ( array.length == 0)
                System.out.println("null");
         	 
	}
	public static void reverse (int [] a,int n)
	{
		/* Here we are writing the logic to swap first element with
		 * last element, second last element with second element and
		 * so on .On the first iteration of while loop i is the index 
		 * of first element and j is the index of last. On the second
		 * iteration i is the index of second and j is the index of 
		 * second last.
		 */
		int i =0;
		int j = n-1;
		while(i<j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		
				 
	}
		System.out.println("Reversed array is : ");
        for (int k = 0; k < n; k++) {
            System.out.print(a[k] + " ");
	}

        } 
 } 

/* Example :-
 * 1.
 * Enter number of elements in the array : 5
 * Enter 5 elements :  1 2 3 4 5 
 * Reversed array is : 5 4 3 2 1 
 * 
 * 2.
 * Enter number of elements in the array : 9
 * Enter 9 elements : 4 6 9 0 7 8 9 9 4
 * Reversed array : 4 9 9 8 7 0 9 6 4 
 * 
 * 3.
 * Enter number of elements in the array : 0
 * Enter 0 elements :
 * Reversed array is : null
 
 * Time complexity : O(n/2) or O(n) , it only iterate through half of the array, but its in O(n) because response time increases in same order as input increases.


 * 
 * */
 