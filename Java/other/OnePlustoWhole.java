/*
One plus to whole

For a given array arr[] of decimal digits, all of which are non-negative numbers.
The digits are stored such that the most significant is at the head of the list, 
and each element of the array contaians single digit only.
It is assumed that none of the numbers have its most significant digit equal to 0.
Your task is to increment the interger so formed by one and return it.
*/

import java.util.*;

public class OnePlustoWhole
{
    //function to return the incremented integer
    public int[] onePlus(int arr[], int size)
    {
        for(int i=size-1; i>=0; i--)
        {
            //if element of the array are somethig less than 9 no carray
            if(arr[i]<9)
            {
                arr[i]++;
                return arr;
            }
            //else if array element is 9 then we crearw new array
            //with one extra digit to keep carry
            arr[i]=0;
        }

        int[] num=new int[size+1];
        num[0]=1;
        
        return num;
    }

    //DRIVER METHOD
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        //size of array
        System.out.println("Enter the number of elements of array: ");
        int size = sc.nextInt();

        int []arr = new int[size];
        //array elements
        System.out.println("Enter the elements for array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("The incremented number is: ");
        int[] res=new OnePlustoWhole().onePlus(arr, size);
        for(int i=0; i<res.length; i++)
        {
            System.out.print(res[i]+" ");
        }
    }
}

/*
EXAMPLE:-

Input--
Enter the number of elements of array: 5
Enter the elements for array: [1, 2, 2, 5, 6]
Output--
The incremented number is: [1, 2, 2, 5, 7]

TIME COMPLEXCITY --> O(N)
SPACE COMPLEXITY --> O(N)
*/
