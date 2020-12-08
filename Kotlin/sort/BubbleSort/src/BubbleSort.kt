fun bubbleSort(list: MutableList<Int>): List<Int>{
    // taking a note of the lists length
    val length = list.size - 1

    // the first loop runs for the number of items there are in the list
    for (i in 0 until length) {
        // a swapped variable which tracks if one of the variables was swapped
        // in one iteration
        var swapped =  false

        // inner loop going from first element till the last element
        // in each round we have the last element as the greatest number
        // so next round has one less element
        // i.e equal to the number of iteration we are in currently.
        for (j in 0 until (length - i)) {
            // if current element is bigger than next element
            if (list[j] > list[j + 1]) {
                // do the swap
                list[j + 1] = list[j].also { list[j] = list[j + 1] }
                // take a note of that swap
                swapped = true
            }
        }
        // check if any swaps happened in this iteration. if there aren't any
        // swaps leave the function cause we have a sorted list.
        if (!swapped){
            return list
        }
    }
    return list
}

fun main() {
    val list = listOf(11,22,33,45,34,53,27,36)
    println("unsorted list is $list")
    val sorted = bubbleSort(list.toMutableList());
    println("sorted list is $sorted")
}