import java.util.Scanner;
public class MoreAlgo {
	public static void check(int arr[]) {
		int count=0;
		for(int i=0;i<arr.length-1;i++) {
			count=1;
			for(int j=i+1;j<arr.length;j++) {
				if(arr[j]==arr[i]) {              // Counting the number by matching it with
					count++;  					 // other numbers.
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
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Number of elements (Eg. 6) : ");
		int element_count = sc.nextInt();  //total number of elements user will be enter
		int[] arr = new int[element_count];
		System.out.println("Enter "+element_count+"Numbers:");
		for(int i=0;i<element_count;i++){
			arr[i] = sc.nextInt();		 // Giving values to array arr
		}
		check(arr);                     //Passing array to function
	}
}

/*
Enter Number of elements (Eg. 6) :
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
