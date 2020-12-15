/*The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space. */
import java.util.Scanner;
public class MoreAlgo {
	
	public static void check(int arr[]) {
		int count=0;
		for(int i=0;i<arr.length-1;i++) {
			count=1;
			for(int j=i+1;j<arr.length;j++) {
				// Counting the number by matching it with other numbers. 
				if(arr[j]==arr[i]) {              
					count++;  		
				}
			}
			if(count>arr.length/2) {
			System.out.println("Number Occuring More than 'n/2'="+arr[i]);
			System.exit(0);
			}
		}
		System.out.print("NO majority Elements ");	
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter Number of elements (Eg. 6) : ");
		//total number of elements user will be enter
		int element_count = input.nextInt();  
		int[] arr = new int[element_count]; 
		System.out.println("Enter "+element_count+" Numbers:");
		for(int i=0;i<element_count;i++){
			// Giving values to array arr
			arr[i] = input.nextInt();		 
		}
		//Passing array to function
		check(arr);                     
	}

}

/*Enter Number of elements (Eg. 6) : 
6
Enter 6 Numbers:
5
5
5
5
4
2
Number Occuring More than 'n/2'=5
*/
/*Time Complexity : o(n^2) , Space Complexity : o(1).
