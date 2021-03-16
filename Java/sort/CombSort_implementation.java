/*
    Comb Sort is a relatively simple sorting algorithm. It is an improvement over Bubble sort
    by using gap of size more than 1. The gap starts with a large value and starts shrinking by
    1.3 in every iteration until it reaches the value 1.
    You can check out more about this Sorting Algorithm here:- https://en.wikipedia.org/wiki/Comb_sort
*/

import java.util.Scanner;

public class CombSort_implementation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of the array:- ");
        int n = input.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the elements of the array:- ");
        
        for(int i =0; i<n; i++){
            arr[i] = input.nextInt();
        }

        comb_sort(arr);

        System.out.println("\nSorted Array is:- ");
        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
    }

    //Method to swap two elements of an Array
    public static void swap_elements_in_array(int idx_1, int idx_2, int arr[]){
        int temp;
        temp = arr[idx_1];
        arr[idx_1] = arr[idx_2];
        arr[idx_2] = temp;
    }

    public static void comb_sort(int arr[]){
        int gap = arr.length;
        //A flag is use to check whether the elements of the array in a gap are sorted or not.
        boolean flag = true;
        while(gap != 1 || flag){
            //Dividing size of gap in every iteration by 1.3
            gap = (int)Math.floor(gap/1.3);
            if(gap < 1){
                gap = 1;
            }
            flag = false;

            for(int i = 0; i <= arr.length-gap-1; i++){
                if(arr[i] > arr[i+gap]){
                    swap_elements_in_array(i, i+gap, arr);
                    flag = true;
                }
            }
        }
    }
}

/*
    Time Complexity:- Best Case - O(n*logn)
                      Average Case:- O(n^2/2^P) where P is no of increments
                      Worst Case:- O(n^2) like Bubble Sort
    
    Space Complexity:- O(1)
*/

/*
    Sample Testcase:-
    Enter the size of array:-
    6
    Enter the elements of the array:-
    12 3 5 23 17 10
    Sorted Array is:-
    3 5 10 12 17 23
*/