public class QuickSort
{
    private static int partition(int[] array, int low, int high)
    {
        int pivot = array[high];

        // index of smaller element 
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                (array[i], array[j]) = (array[j], array[i]);
            }
        }

        (array[i + 1], array[high]) = (array[high], array[i + 1]);

        return i + 1;
    }

    public static void quickSort(int[] array, int low, int high)
    {
        if (low < high)
        {
            int partitioningIndex = partition(array, low, high);
            quickSort(array, low, partitioningIndex - 1);
            quickSort(array, partitioningIndex + 1, high);
        }
    }


    public static void Sort(int[] array)
    {
        quickSort(array, 0, array.Length - 1);
    }
}

