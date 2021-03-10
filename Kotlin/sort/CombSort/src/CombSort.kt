// Kotlin code for Comb Sort

fun <T : Comparable<T>> combSort(arr: Array<T>) {
    var arr_size = arr.size
    if (arr_size <= 1) return  //already sorted
    var swaps = false
    while (arr_size > 1 || swaps) {
        arr_size = (arr_size/1.247331).toInt()
        if (arr_size < 1) arr_size = 1
        var i = 0
        swaps = false
        while (i + arr_size < arr.size) {
            if (arr[i] > arr[i + arr_size]) {
                val t = arr[i]
                arr[i] = arr[i + arr_size]
                arr[i + arr_size] = t
                swaps = true
            }
            i++
        }
    }
}

fun main(args: Array<String>) {
    val unsorted = arrayOf(76, 36, 1, 8, 19, 2, 90, 13, 14, 23)
    println("Unsorted array: ${unsorted.contentToString()}")
    combSort(unsorted)
    println("Sorted array: ${unsorted.contentToString()}")

}

// Output :- Sorted array: [1, 2, 8, 13, 14, 19, 23, 36, 76, 90]
