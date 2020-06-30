public class BinarySearch
{
    // This search method work only on sorted array 
    static int Search(int[] array, int element)
    {
        int left = 0;
        int right = array.Length - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (array[middle] == element)
            {
                return middle;
            }

            // If element greater than the middle element we search on the right half 
            if (array[middle] < element)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        // element not found 
        return -1;
    }
}

