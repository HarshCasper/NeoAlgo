/*
Problem Statement:

Count the number of triplets in a given array such 
that sum of two is equal to the third number.

*/
import java.util.*;
class countTriplets{
    public static int triplet_counter(int N, int arr[]){
    
        int freq[] = new int[1000000+7]; // creates an array intitalised with 0

        for(int i = 0; i < N; i++) {
            freq[arr[i]]++; // storing the frequency of each element
        }
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j=i+1; j<N; j++) {
                // adds the frequency if the triplet exists
                count = count + freq[arr[i]+arr[j]]; 
            }
        }
        return count;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter The Number of Elements:");
        int N = sc.nextInt();
        int arr[] = new int[N+7];
        System.out.println("Enter "+N+" elements");
        for(int i=0; i<N; i++){
            arr[i] = sc.nextInt();
        }
        int count = triplet_counter(N,arr);
        System.out.println(count);
        sc.close();
    }
}



/* Sample Input Output ->
Input
5
1 2 5 4 3

Output:
4

Explanation:
1 + 2 = 3
1 + 3 = 4
1 + 4 = 5
2 + 3 = 5
Hence, there are 4 such triplets possible.
Complexity Analysis
Time Complexity - O(n^2)
Space Complexity - O(1) */