// time complexity O(n);
// find kth smallest element;
/*
Sample Input
5 -> no. of elements
elements -> 
7 
-2 
4 
1 
3
3
*/

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
        int[] arr = {8,5,1,3,7,2,9,6};
        Scanner scn = new Scanner(System.in);
        int k = scn.nextInt();
        int sel = quickSelect(arr, k-1, 0, arr.length-1); // passing k-1 because kth smallest would be at k-1 index
        System.out.println(sel);
    }
}
