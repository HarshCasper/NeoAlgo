import java.util.*;

public class ShellSort{
    public static void main(String[] args){
        int array[] = {30, 25, 77, 16 , 80, 32, 67} ;
        shellSort(array);
    }

    public static void shellSort(int array[]){
        int size = array.length;
        int gap = size/2;
        while(gap >= 1){
            for(int i=gap;i<size;i++){
                int temp = array[i];
                int j;
                for(j = i;j>=gap && array[j-gap] > temp; j=j-gap){
                    array[j] =array[j-gap];
                }
                array[j] = temp;
            }
            gap = gap/2;
        }
    
        //printing sorted array
        System.out.print(" ShellSort : ");
        for(int i=0;i<size;i++){
            System.out.print(array[i] + " ");
        }
    }
}

// int sort(int arr[]) 
//     { 
//         int n = arr.length; 
  
//         // Start with a big gap, then reduce the gap 
//         for (int gap = n / 2; gap > 0; gap /= 2) { 
//             // Do a gapped insertion sort for this gap size. 
//             // The first gap elements a[0..gap-1] are already 
//             // in gapped order keep adding one more element 
//             // until the entire array is gap sorted 
//             for (int i = gap; i < n; i += 1) { 
//                 // add a[i] to the elements that have been gap 
//                 // sorted save a[i] in temp and make a hole at 
//                 // position i 
//                 int temp = arr[i]; 
  
//                 // shift earlier gap-sorted elements up until 
//                 // the correct location for a[i] is found 
//                 int j; 
//                 for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
//                     arr[j] = arr[j - gap]; 
  
//                 // put temp (the original a[i]) in its correct 
//                 // location 
//                 arr[j] = temp; 
//             } 
//         } 
//         return 0; 
//     } 
  
//     // Driver method 
//     public stati