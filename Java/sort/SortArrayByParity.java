/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.
*/

import java.util.Scanner;
class SortArrayByParity{

  public static void printArray(int arr[]){
      int n = arr.length;
      for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
      System.out.println();
  }

  public static void swap(int[] A, int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
  }
    
  // 0 to j-1 -> even
  // j to i-1 -> odd
  public int[] sortArrayByParity(int[] A) {
        if(A.length == 1) return A;

        int i=0;
        int j=0;

        while(i<A.length){
            if(A[i]%2 == 1){
                i++;
            }else{
                swap(A, i, j);
                i++;
                j++;
            }
        }

        return A;
    }

  public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int arr[] = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		int[] ans = sortArrayByParity(arr);
		printArray(ans);
	}
}

/*
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Time Complexity -> O(n)
*/
