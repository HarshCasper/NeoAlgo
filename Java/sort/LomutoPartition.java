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
        {
            ar[i] =sc.nextInt();
        }
        System.out.println("The array before sorting is:");
        for(int i=0;i<n;i++)
        {
            System.out.print(ar[i]+" ");
        }
        quickSort(ar, 0, ar.length-1);
        System.out.println("\n");
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
        // from the above function the pivot is choosen 
        //and the quicksort function is called  as two parts
        //from 0 to p-1 and other is p+1 to the higher end
        //from 0 to p-1 and other is p+1 to the higher end limit of the array
        quickSort(ar, 0, p-1);
        quickSort(ar, p+1, high);
    }
@@ -54,7 +54,7 @@ public static int partition(int[] ar, int l, int r)
    int i =l;
    for(int j=l;j<r;j++)
    {
        //swapping is done on comparing woth the pivot element
        //swapping is done on comparing with the pivot element
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
10
Enter array elements:
10 9 8 7 6 5 4 3 2 1
The array before sorting is:
10 9 8 7 6 5 4 3 2 1 
The Sorted array is:
1 2 3 4 5 6 7 8 9 10  */
