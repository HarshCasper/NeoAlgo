//Lomuto partition of quick sort 
//This is similar to the implementation of QuickSort
//The difference is that once we select the last element as the pivot
//we need to keep adjusting its position by sorting and swapping the elements in memory.


import java.util.Scanner;

public class Main
{

	public static void main(String[]args)
    
{
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of the array:");
        int n =sc.nextInt();
        int[] ar = new int[n];
        System.out.println("Enter array elements:");
        for(int i=0;i<n;i++)
        ar[i] =sc.nextInt();
        quickSort(ar, 0, ar.length-1);
        System.out.println("The Sorted array is:");
        for(int i=0;i<n;i++)
        {
            System.out.print(ar[i]+" ");
            
        }
    }
public static void quickSort(int[] ar, int low, int high)
{
    if(low<high)
    {
        int p =partition(ar, low, high);
        quickSort(ar, 0, p-1);
        quickSort(ar, p+1, high);
    }
}
public static int partition(int[] ar, int l, int r)
{
    int pivot =ar[r];
    int i =l;
    for(int j=l;j<r;j++)
    {
        if(ar[j] <=pivot)
            {
            int t =ar[j];
            ar[j] =ar[i];
            ar[i] =t;
            i++;
            } 
    }
    int t =ar[i];
    ar[i] =ar[r];
    ar[r] =t;
    return i;
}
}

//Time Complexity O(n log n)
//Space Complexity O(log n)


/*sample output
Enter size of the array:
5
Enter array elements:
1000
12
13
0
-1
The Sorted array is:
-1 0 12 13 1000 */


