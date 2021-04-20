/**
Given an array of positive and negative elements.
We have to check if there exists a subarray whose
sum is equal to 0 or not.
This problem will take O(n^3) time complexity.
But we can perform it in linear line time i.e in
O(n) time complexity by the use of HashMaps.

We take an array whose ith index will store the sum
from 0th index upto ith index.
Ex : ar[]={1,2,4,-6,7,-3}
arrSum[]={1,3,7,1,8,5}

We know that there is a subarray {2,4,-6} exists with sum=0
from index 1 to index 3. 
Therefore, sum of indices 1,2,3 = 0
sumArr[3]-sumArr[0]=0
i.e. summArr[3]=sumArr[0]

This concludes that if there exists any subarray with
sum=0, then there always exists this condition.
To store all the sums calculated so that we can check them
later, we use a HashMap, since the search time in HashMap 
is of O(1). And calculating sum of the complete array
will take O(n) time.
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

