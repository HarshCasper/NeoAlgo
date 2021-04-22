/**
Given an array of positive and negative elements.
We have to check if there exists a subarray whose
sum is equal to 0 or not.
 */

import java.util.HashMap;
import java.util.Scanner;

public class SubarraySumZero {

    public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		System.out.print ("Enter size of array - ");
		int n=sc.nextInt();
		
		int[] ar=new int[n];
		System.out.println("Enter elements in array - ");
		for (int i=0; i<n; i++) {
			ar[i]=sc.nextInt();
		}
		
		// the ith index of sumArray will store
		// sum from 0th index to ith index.
		int[] sumArray=new int[n];
		int sum=0;
		
		// Map will keep track of the sums that we calculate
		HashMap<Integer, Boolean> map=new HashMap<Integer, Boolean>();

		boolean flag=false;
		
		for (int i=0; i<n; i++) {
			sumArray[i]=sum + ar[i];
			sum=sumArray[i];
			
			if (sum==0 || map.containsKey(sumArray[i])) {
				flag=true;
				break;
			} else {
				map.put(sumArray[i], true);
			}
		}
		
		if (flag) {
			System.out.println("Subarray with sum=0 is present");
		} else {
			System.out.println("Subarray with sum=0 is not present");
		}
	}
}

/*
Time Complexity : O(n)
Space Complexity : O(n)

Input 1 :

Enter size of array - 9
Enter elements in array - 
1 3 -5 2 8 9 -11 6 4

Output 1 :

Subarray with sum=0 is present

Input 2 :

Enter size of array - 6
Enter elements in array - 
4 2 6 -7 5 1

Output 2 :

Subarray with sum=0 is not present
*/

