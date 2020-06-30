public class RemoveDuplicateElementWithoutExtraSpace{

    /**
     * Method 2
     * Without using any extra space
     *
     * Input  (To be used only for expected output) :
     * 2
     * 5
     * 1, 2, 2, 3, 4, 4, 4, 5, 5
     * 3
     * 1 2 2
     * Output
     * 1 2 3 4 5 
     * 1 2
     */

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
        int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
        int n = arr.length;

        n = removeDuplicates(arr, n);

        // Print updated array
        for (int i=0; i<n; i++)
            System.out.print(arr[i]+" ");
    }

}
