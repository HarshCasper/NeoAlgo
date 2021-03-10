
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
    val unsorted = arrayOf(28, 44, 46, 24, 19, 2, 17, 11, 4)
    println("Unsorted array: ${unsorted.contentToString()}")
    combSort(unsorted)
    println("Sorted array: ${unsorted.contentToString()}")

}
