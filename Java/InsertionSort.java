/* Insertion Sort using Iteration */

public class InsertionSort{
 
     public static void insertionSort(int[] ar){
       
    //Starting index from index 1 to create sorted array at left side of the array

             for(int i = 1; i < ar.length; i++){

                 int j = i-1,k = i;                // Assigning j = i-1 and iterating to 0 in sorted part of the array
                 while(j >= 0 && ar[k] < ar[j]){   // checking if element at index i is smaller than elements in the sorted array and then swap them
                     swap(ar,k,j);                 // swapping elements in the same array by passing ar and indexes i and j
                     j--;
                     k--;
                 }

             }

     }

     public static void main(String args[]){
         int[] ar = {19,8,7,6,5,4,3,2,1};
         insertionSort(ar);

         for(int i = 0; i < ar.length; i++){
             System.out.print(ar[i]+" ");
         }System.out.println();
     }
    

     public static void swap(int[] ar, int i , int j){   // swapping elements in the array 
         int temp = ar[i];
         ar[i] = ar[j];
         ar[j] = temp;
     }

}

/* It is an interesting algorithm so I challenge you to apply Insertion Sort using recursion */
/* Good Luck */