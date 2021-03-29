import sort.HeapSort
import java.io.IOException
import java.util.*

class ExponentialSearch : SearchAlgorithms<Int> {

    override fun findIndexOf(arr: ArrayList<Int>, value: Int): Int {
        val size = arr.size

        // If x is present at first location itself
        if (arr[0] == value) {
            return 0
        }

        // Find range for binary search by repeated doubling
        var bound = 1
        while (bound < size && arr[bound] <= value) {
            bound *= 2
        }

        return binarySearch(arr, value, bound / 2, Math.min(bound + 1, size - 1))
    }

    /**
     * This method implements the Generic Binary Search
     *
     * @param array The array to make the binary search
     * @param key The number you are looking for
     * @param left The lower bound
     * @param right The  upper bound
     * @return the location of the key
     */
    private fun <T : Comparable<T>> binarySearch(array: ArrayList<T>, key: T, left: Int, right: Int): Int {

        // this means that the key not found
        if (right < left) {
            return -1
        }

        // find median
        val median = (left + right).ushr(1) // (It mean: >>> 1 or left + right /2)
        val comp = key.compareTo(array[median])

        if (comp < 0) {
            return binarySearch(array, key, left, median - 1)
        }

        return if (comp > 0) {
            binarySearch(array, key, median + 1, right)
        } else {
            median
        }
    }

    object Run {
        @Throws(IOException::class)
        @JvmStatic
        fun main(args: Array<String>) {
            val dataInputs = arrayListOf(6, 5, 3, 1, 8, 7, 2, 4)
            // sort data inputs
            HeapSort().sort(dataInputs)
            System.out.print("---------Input---------\n$dataInputs\n")

            val searchAlgorithms: SearchAlgorithms<Int> = ExponentialSearch()
            val randomInput = Random().nextInt(10)
            val result = searchAlgorithms.findIndexOf(dataInputs, randomInput)
            System.out.print("---------Result---------\n")
            if (result != -1) {
                System.out.print("Found $randomInput at index $result")
            } else {
                System.out.print("$randomInput not found in dataInputs!")
            }
        }
    }
}
