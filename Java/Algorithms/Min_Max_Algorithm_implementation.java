/*
    The MinMax Algorithm is used to find the maximum and minimum element of an Array 
    in less no of comparisons(3*(n/2) - 2 comparisons) as compared to the Brute Force method.
    It uses a Divide N Conquer algorithmic approach(recursively dividing the array) to find minimum 
    and maximum elements 
*/

import java.util.Scanner;

public class Min_Max_Algorithm_implementation {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array:-");
        
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        System.out.println("Enter elements of array");
        
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        
        //Least index of an array/subarrays
        int low = 0; 
        //Highest index of an array/subarrays
        int high = n - 1; 
        
        int output[] = MinMax(arr, low, high);
        System.out.println("Output:");
        System.out.println(String.format("Min: %d Max: %d", output[0], output[1]));
    }

    /* 
        Function that returns minimum and maximum out of 2 elements.
        It returns an array with first element as minimum and second element as maximum out of 2 elements.
    */ 

    public static int[] min_max_of_2_elements(int x, int y){
        int min_max[] = new int[2];
        if(x < y){
            min_max[0] = x;
            min_max[1] = y;
        }
        else{
            min_max[0] = y;
            min_max[1] = x;
        }
        return min_max;
    }

    public static int[] MinMax(int arr[], int low, int high){
        
        // If after dividing array, we have one element left or two elements then return min or max of those elements
        if(low == high || high == low + 1){
            return min_max_of_2_elements(arr[low], arr[high]);
        }

        // Else dividing array recursively into smaller parts.
        else{ 
            int mid = low + ((high - low) / 2);
            int arr1[] = MinMax(arr, low, mid);
            int arr2[] = MinMax(arr, mid+1, high);

            // Returning an array with first element as the min element and second element as max of two elements
            return new int[]{min_max_of_2_elements(arr1[0], arr2[0])[0], min_max_of_2_elements(arr1[1], arr2[1])[1]};
        }
    }
}

/*
    Time Complexity:- O(N)
    Space Complexity:- O(1)
*/

/*
Sample Case:
Enter the size of array:-
8
Enter elements of array:
8 7 3 12 6 4 2 11
Output:
Min: 2 Max: 12
*/
