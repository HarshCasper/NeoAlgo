import java.util.Scanner;

/*
Author: iamvs-2002
*/

/*
Jump Search Algorithm works for sorted array, of size n.
It creates a block of size m = (n)^1/2 and tries to find the element in that block. 
If the item is not in the block, it shifts the entire block.
After finding a correct block it finds the item using linear search algorithm.
Time Complexity = O((n)^1/2)
Space Complexity = O(1)
*/

public class JumpSearchAlgorithm{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Kindly enter the size of the array: ");
        int n = sc.nextInt();

        int array[] = new int[n];
        System.out.println("\nKindly enter the sorted array: ");
        for(int i=0;i<n;i++){
            array[i]=sc.nextInt();
        }
        
        System.out.print("\nEnter the element you want to search: ");
        int key = sc.nextInt();

        JumpSearchAlgorithm jump = new JumpSearchAlgorithm();
        int index = jump.JumpSearch(array,key);

        if(index == -1){
            System.out.println("The element "+key+" was not found!");
        }
        else{
            System.out.println("The element "+key+" was found at index "+index);
        }

    }

    public int JumpSearch(int[] array, int key){
        int sizeofarray = array.length;

        //block size = m
        int m = (int) Math.floor(Math.sqrt(sizeofarray)); 

        //Initialize rear pointer at index m-1, i.e., pointing to the last element in the block
        int rear = m-1;
        //Initialize front pointer at index 0, i.e., pointing to the first element in the block
        int front = 0;

        //Shift the block untill the rear pointer points to a valid index
        //and the key element is greater than the element at the current rear index
        while(rear<sizeofarray && key>array[rear]){
            rear = rear+m;
            front = front+m;
        }

        //If the correct block is found perform the linear search in the block
        for(int i=front; i<=rear && i<sizeofarray; i++){
            if(key==array[i]){
                return i;
            }
        }

        return -1;
    }
}

/*
Sample Outputs:
****************************************
Kindly enter the size of the array: 5

Kindly enter the sorted array: 
1 2 3 4 5

Enter the element you want to search: 1
The element 1 was found at index 0

****************************************
Kindly enter the size of the array: 8

Kindly enter the sorted array: 
0 1 2 3 4 7 8 9

Enter the element you want to search: 3
The element 3 was found at index 3

****************************************
Kindly enter the size of the array: 4

Kindly enter the sorted array:
1 2 2 3

Enter the element you want to search: 2
The element 2 was found at index 1

*/
