/*
  Intersection :
     We have to find intersection of two arrays :
     The intersection of two arrays is a list of numbers which are present in both the arrays
  For example :
     We have to input 2 arrays of integer, let first array be 1 4 3 2 and the second array be 1 3 2
     So, intersection means the numbers which are common in both the arrays
     here, 1 2 3 is common in both the arrays hence, it is the intersection of both the arrays

     If the number is repeating in the array, for example one array is 1 2 2 2 and second array is
     2 3 2 4 2 then the intersection would be 2 2 2 not just 2
*/

import java.util.Arrays;
import java.util.Scanner;

public class Intersection_of_Two_Arrays {

	//method intersection
	public void intersection(int[] array1, int[] array2) {

		int x = 0, y = 0;

		Arrays.sort(array1);
		Arrays.sort(array2);

		for(  ; x < array1.length && y < array2.length ;  )
		{

			if(array1[x] == array2[y])
			{
				System.out.print(array2[y]+" ");
				y = y+1;
				x = x+1;
			}
			else if(array1[x] < array2[y])
			{
				x = x+1;
			}
			else if(array1[x] > array2[y])
			{
				y = y+1;
			}
		}
	}

	//Driver Code
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements you want in the first array : ");
		int first = sc.nextInt();

		//Creating array
		int[] array1 = new int[first];

		System.out.print("Enter the elements in the 1st array : ");
		for(int i = 0 ; i < first ; i++) {
			array1[i] = sc.nextInt();
		}

		System.out.print("Enter the number of elements you want in the second array : ");
		int second = sc.nextInt();

		//Creating array
		int[] array2 = new int[second];

		//Putting elements in the array
		System.out.print("Enter the elements in the 2nd array : ");
		for(int i = 0 ; i < second ; i++) {
			array2[i] = sc.nextInt();
		}

		//Creating object
		Intersection_of_Two_Arrays obj = new Intersection_of_Two_Arrays();

		System.out.print("The intersection of two arrays is : ");

		//calling intersection method
		obj.intersection(array1, array2);
	}
}
/*

Input:
Enter the number of elements you want in the first array : 4
Enter the elements in the 1st array : 1 2 3 4
Enter the number of elements you want in the second array : 3
Enter the elements in the 2nd array : 1 2 3

Output:
The intersection of two arrays is : 1 2 3

Time Complexity : O(n)
Space Complexity : O(n)

*/
