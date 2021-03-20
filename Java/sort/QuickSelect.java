// This algorihtm is used to find kth smallest element in an unsorted array.

import java.util.Scanner;
class QuickSelect{

    public static int quickSelect(int[] arr, int idx, int lo, int hi){

        int pivot = arr[hi];
        int pi = partition(arr, pivot, lo, hi);
        if(idx == pi){ // if index == pivot index return element at that index
            return arr[pi];
        }else if(idx<pi){ // if index is less than pivot index then search on left side
            return quickSelect(arr, idx, lo, pi-1);
        }else{ // otherwise search on right side
            return quickSelect(arr, idx, pi+1, hi);
        }
        
    }
    
    // code for partitioning -> same as quick sort
    public static int partition(int[] arr, int pivot, int lo, int hi){
        int i=lo, j=lo;
        while(i<=hi){
            if(arr[i]>pivot){
                i++;
            }else{
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;

                i++;
                j++;
            }
        }
        return j-1;
    }

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = sc.nextInt();
		
		int arr[] = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
        
        int k = scn.nextInt();
        
        int sel = quickSelect(arr, k-1, 0, arr.length-1); // passing k-1 because kth smallest would be at k-1 index
        System.out.println(sel);
    }
}

/*
* Sample Input
    no. of elements -> 5
    elements -> 7, -2, 4, 1, 3
    k -> 3

* output -> 3

* time Complexity -> O(n)
*/
