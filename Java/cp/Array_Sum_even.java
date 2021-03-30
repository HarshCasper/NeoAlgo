import java.util.Scanner;

public class Array_Sum_even {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		while(t-->0) {
			int n= sc.nextInt();
			long arr[]= new long [n];
			for(int i=0; i<n; i++)
				arr[i]= sc.nextLong();
			
			long sum=0;
			for(int i=0; i<n; i++) {
				sum+=arr[i];
			}
			
			
			int flag=0;
			if(sum%2==0) {
				System.out.println(0);
			}
			else {
				for(int i=0; i<n; i++) {
					long p= Math.max(0, (arr[i]/2)-1);
					if(arr[i]!=1 && arr[i]%2==0 && p==0) {
						flag=1;
						System.out.println(1);
						break;
					}
				}
				if(flag==0)
					System.out.println(-1);
			}
		}
	}

}

/*
The problem is to find the minimum number of operations to make the array sum even by change Ai to (Ai)^p, where p=max(0,⌈Ai2⌉−1).
-1 is printed if array sum can not be made even by doing anything, otherwise no of steps to make it even is printed.
Example Input
2
4
7 3 5 1
5
4 2 7 8 10

Example Output
0
1

Time complexity - O(n)

link - https://www.codechef.com/LTIME94C/problems/MKSMEVN/
*/
