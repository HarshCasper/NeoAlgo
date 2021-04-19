// Function to Implement Radix Sort
// The radix sorting algorithm is an integer sorting algorithm, 
// that sorts by grouping numbers by their individual digits (or by their radix).
// It uses each radix/digit as a key, and implements counting sort or 
// bucket sort under the hood in order to do the work of sorting.

// Takes an IntArray as arguments and returns a sorted IntArray to the caller function
fun radixSort(original: IntArray): IntArray {
    // Array needs to be mutable
    var old = original
    for (shift in 31 downTo 0) {
        val tmp = IntArray(old.size)
        // The number of 0s
        var j = 0
        // Move the 0s to the new array, and the 1s to the old one
        for (i in 0 until old.size) {
            // If there is a 1 in the bit we are testing, the number will be negative
            val move = (old[i] shl shift) >= 0
            // If this is the last bit, negative numbers are actually lower
            val toBeMoved = if (shift != 0) move else !move
            if (toBeMoved) {
                tmp[j++] = old[i]
            }
            else {
                // It's a 1, so stick it in the old array for now
                old[i - j] = old[i]
            }
        }
        // Copy over the 1s from the old array
        for (i in j until tmp.size) {
            tmp[i] = old[i - j]
        }
        old = tmp
    }
    return old
}

fun main(args: Array<String>) {
    print("Enter N: ");
    val n= readLine()!!.toInt();
    println("Enter array of N integers: ");
    val arrays = IntArray(n) { readLine()!!.toInt() }
    val array= radixSort(arrays);
    print("Array after Radix Sort is: ")
    for(i in array){
        print("$i ")
    }
}

/*
Time Complexity: O(log n)
Sample Input:
Enter N: 5
Enter array of N integers:
3
-1
2
3
4

Sample Output:
Array after Radix Sort is: -1 2 3 3 4
 */
