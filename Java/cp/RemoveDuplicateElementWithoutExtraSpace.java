import java.util.Scanner;

public class RemoveDuplicateElementWithoutExtraSpace{

    // Function to remove duplicate elements
    // This function returns new size of modified
    // array.
    static int removeDuplicates(int arr[], int n)
    {
        if (n == 0 || n == 1)
            return n;

        // To store index of next unique element
        int j = 0;

        // Doing same as done in Method 1
        // Just maintaining another updated index i.e. j
        for (int i = 0; i < n-1; i++)
            if (arr[i] != arr[i+1])
                arr[j++] = arr[i];

        arr[j++] = arr[n-1];

        return j;
    }

    public static void main (String[] args)
    {
        // taking the input from the user
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array : ");
        int n = sc.nextInt();
        
        int arr[] = new int[n];
        System.out.println("Enter the values for the array elements : ");
        // taking the values for the array from the user
        for(int i=0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }

        n = removeDuplicates(arr, n);

        // Print updated array
        for (int i=0; i<n; i++)
            System.out.print(arr[i]+" ");
    }

}

/*

Example:

Input: 
Enter the length of the array : 5
Enter the values for the array elements : 
1 1 1 3 4

Output:
1 3 4

*/
