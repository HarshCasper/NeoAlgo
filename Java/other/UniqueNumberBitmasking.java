/**
We are given an array in which all the elements are 
present twice except one element. The program will 
find out that unique element.
 */

import java.util.Scanner;

public class UniqueNumberBitmasking {

    public static void main(String[] args) {
		
		Scanner sc=new Scanner (System.in);

              System.out.print ("Enter size of array - ");
		int n=sc.nextInt();

		int[] ar=new int[n];
              System.out.print ("Enter elements in array - ");
		for (int i=0; i<n; i++) {
			ar[i]=sc.nextInt();
		}

		int xor=0;
		for (int i=0; i<n; i++) {
			xor=xor^ar[i];
		}

		System.out.println ("Unique element in array - "+xor);
	}
}

/**
Time Complexity : O(N)
Space Complexity : O(N)

Input :

Enter size of array - 7

Output : 

Enter elements in array - 3 8 2 5 3 2 5
Unique element in array - 8

*/

