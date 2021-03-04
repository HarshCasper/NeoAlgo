/*

Cycle Sort is an in-place sorting algorithm. It is also a comparison based sort and efficient for any other in-place sorting technique. 
It finds the minimum number of memory write to perform the sorting tasks.

Time Complexity:
Average:  O(n2)
Worst  :  O(n2)

Space Complexity: O(1)

*/


public class CycleSort {
    public static void main(String[] args)
    {
        int[] arr = {12, 11, 15, 10, 9, 1, 2, 2, 3, 13, 14, 4, 5, 6, 7, 8};

        CycleSort sorter = new CycleSort();
        sorter.cycleSort(arr);

        System.out.println(java.util.Arrays.toString(arr));
    }

    void cycleSort(int[] array)
    {
        // step 1: loop from the beginning of the array to the second to last item
        for (int currentIndex = 0; currentIndex < array.length - 1; currentIndex++)
        {
            // step 2: save the value of the item at the currentIndex
            int item = array[currentIndex];
            // step 3: save a copy of the current index
            int currentIndexCopy = currentIndex;

            // step 4: loop through all indexes that proceed the currentIndex
            for (int i = currentIndex + 1; i < array.length; i++)
                if (array[i] < item)
                    currentIndexCopy++;

            // step 5: if currentIndexCopy has not changed, the item at the currentIndex is already in the correct position
            if (currentIndexCopy == currentIndex)
                continue;

            // step 6: skip duplicates
            while (item == array[currentIndexCopy])
                currentIndexCopy++;

            // step 7: swap
            int temp = array[currentIndexCopy];
            array[currentIndexCopy] = item;
            item = temp;

            // step 8: repeat steps 4, 6 and 7 above as long as we can find values to swap
            while (currentIndexCopy != currentIndex)
            {

                // step 9: save a copy of the currentIndex
                currentIndexCopy = currentIndex;

                // step 10: repeat step 4
                for (int i = currentIndex + 1; i < array.length; i++)
                    if (array[i] < item)
                        currentIndexCopy++;

                // step 10: repeat step 6
                while (item == array[currentIndexCopy])
                    currentIndexCopy++;

                // step 10: repeat step 7
                temp = array[currentIndexCopy];
                array[currentIndexCopy] = item;
                item = temp;
            }
        }
    }
}
