import java.util.Scanner;

public class NextPermutation {
    private static void nextPermutation(int[] array, int lenOfArray) {
        if(array == null || lenOfArray == 0) return ; // handling edge case

        int firstDecreasingElement = lenOfArray - 2; // finding first decreasing element in the array traversing from right
        while(firstDecreasingElement >= 0 && array[firstDecreasingElement] >= array[firstDecreasingElement + 1]){
            firstDecreasingElement--;
        }

        if(firstDecreasingElement >= 0){
            int nextMaxElement = lenOfArray - 1; // finding the next larger number than firstDecreasingElement to the right
            while(nextMaxElement > firstDecreasingElement && array[nextMaxElement] <= array[firstDecreasingElement]){
                nextMaxElement--;
            }
            swap(array, firstDecreasingElement, nextMaxElement);// swap both the numbers
        } 
        reverse(array, firstDecreasingElement+1);// reverse the array right to firstDecresingNumber index
    }
    private static void swap(int[] array, int i , int j){// function to swap numbers
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    private static void reverse(int[] array, int startIdx){// function to reverse an array
        int start = startIdx;
        int end = array.length-1;
        while(start < end){
            swap(array, start, end);
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        
        int lenOfArray = sc.nextInt(); //Taking input of length of array
        int array[] = new int[lenOfArray]; //declaring array of size lenOfArray

        //Taking input of array
        for(int i = 0; i < lenOfArray; i++){
            array[i] = sc.nextInt();
        }
        sc.close();
        //Printing original array
        System.out.println("Original Array : ");
        for(int i = 0; i < lenOfArray; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();

        nextPermutation(array, lenOfArray); // calling function to get next permuation of array 

        //Printing next permutation of array
        System.out.println("Next Permutation : ");
        for(int i = 0; i < lenOfArray; i++){
            System.out.print(array[i]+" ");
        }
    }
}

// Sample Output :

// 3
// 1 2 3
// Original Array : 
// 1 2 3 
// Next Permutation : 
// 1 3 2 