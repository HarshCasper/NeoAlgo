/*
  - Intersection :
       We have to find intersection of two arrays :
       The intersection of two arrays is a list of numbers which are present in both the arrays
     Example :
       input : Enter the number of elements you want in the first array : 4
	           Enter the elements in the 1st array : 1 4 3 2
	 		   Enter the number of elements you want in the second array : 3
	 		   Enter the elements in the 2nd array : 1 2 3
      output : The intersection of two arrays is : 1 2 3
               Intersection of both arrays is [1 2 3] as these elements are present in both the arrays
*/

import java.util.Arrays;
import java.util.Scanner;

public class Inter {

	//method intersection
	public void intersection(int[] array1, int[] array2) {

		int x = 0, y = 0;
		//sorting 1st Array
		Arrays.sort(array1);
		//sorting 2nd Array
		Arrays.sort(array2);

		//for loop
		for(  ; x < array1.length && y < array2.length ;  ) {
			//if array1[x] == array2[y] is true then print array2[y] and increment y and x
			if(array1[x] == array2[y]) {
				System.out.print(array2[y]+" ");
				y = y+1;
				x = x+1;
			//else if array1[x] < array2[y] is true increment x
			}else if(array1[x] < array2[y]) {
				x = x+1;
            //else if array1[x] > array2[y] is true increment y
			}else if(array1[x] > array2[y]) {
				y = y+1;
			}
		}
	}

	//main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		//For 1st Array
		//Input the number of elements you want in the array
		System.out.print("Enter the number of elements you want in the first array : ");
		int first = sc.nextInt();
		//Creating array
		int[] array1 = new int[first];
		//Putting elements in the array
		System.out.print("Enter the elements in the 1st array : ");
		for(int i = 0 ; i < first ; i++) {
			array1[i] = sc.nextInt();
		}

		//For 2nd Array
		//Input the number of elements you want in the array
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
		Inter obj =new Inter();
		System.out.print("The intersection of two arrays is : ");
		//calling intersection method
		obj.intersection(array1, array2);
	}
}
/*
- Test Cases :
       input : Enter the number of elements you want in the first array : 4
	           Enter the elements in the 1st array : 1 4 3 2
	 		   Enter the number of elements you want in the second array : 3
	 		   Enter the elements in the 2nd array : 1 2 3
      output : The intersection of two arrays is : 1 2 3

- Complexity Analysis :
 * Time Complexity : O(n)
         Where, n = array1.length + array2.length
  	     We are using only one for loop, so it iterates maximum 'n' times while traversing for loop
 * Space Complexity : O(n)
	  	 Auxiliary space : O(1)  +  input space : O(n)
*/
  
