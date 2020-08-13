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
