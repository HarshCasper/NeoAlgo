import java.util.*;
public class DutchFlag {
    private static void dutchFlag(int[] array, int size){
        int start = 0, mid = 0, end = size-1;
        while(mid <= end){
            switch(array[mid]){
                case 0 :
                swap(array, start, mid);
                start++;
                mid++;
                break;

                case 1 :
                mid++;
                break;

                case 2 :
                swap(array,mid, end);
                end--;
               
                break;

            }
        }
    }
    private static void swap(int[] array, int i , int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] array = new int[size]; 
        //Taking array input
        for(int i = 0; i < size; i++){
            array[i] = sc.nextInt();
        }
        
        dutchFlag(array,size);
        System.out.println("Sorted Array : ");
        for(int i = 0; i < size; i++){
            System.out.print(array[i]+" ");
        }
    }
}
