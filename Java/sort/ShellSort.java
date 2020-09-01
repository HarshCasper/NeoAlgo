import java.util.*;

public class ShellSort{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array : ");
        int n = scan.nextInt();// size of array
        int[] array = new int[n];
        System.out.println("Enter the elements in the array : ");
        for(int i=0;i<n;i++){
            array[i] = scan.nextInt(); //array elements
            //example array : 7 , 85, 24, 45, 1, 29
        }
        scan.close();

        shellSort(array, n); // function call for sorting array
        //Output : 1, 7 24, 29, 45, 85
       
    }

    public static void shellSort(int array[], int size){
        //In shell sort , we use gap to sort the array. Starting the gap from larger value and reduce it till it is 1.
        int gap = size/2;
        while(gap >= 1){
            // All the elements from array[0....gap-1] is already sorted. We add the elements in sorted form till the array is fully sorted.
            for(int i=gap;i<size;i++){
                // Store the value of array[i] to temp;
                int temp = array[i];
                int j;
                // Finding the coorrect place to store the value of temp
                for(j = i; j>=gap && array[j-gap] > temp; j=j-gap){
                    array[j] =array[j-gap];
                }
                array[j] = temp;// correct place of placing temp
            }
            gap = gap/2;
        }
    
        //printing sorted array
        System.out.print(" ShellSort : ");
        for(int i=0;i<size;i++){
            System.out.print(array[i] + " "); // Printing the sorted array
        }
    }
}
