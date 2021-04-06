import java.util.*;

class ReverseArray {
	
	public static void reverseArray(int arr[]) {
		int length = arr.length;

		for(int i=0;i<length/2;i++) {
			int temp = arr[i];
			arr[i] = arr[length-i-1];
			arr[length-i-1] = temp;
		}
	}

	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int arr[] = new int[N];
		
		for(int i=0;i<N;i++) {
			arr[i] = scan.nextInt();
		}

		reverseArray(arr);
		
		for(int i=0;i<N;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		
	}
}