fun selectionSort(list: MutableList<Int>): List<Int>{
    // run the code as many times as there are elements in the list
    for (i in 0 until list.size){
        // store the first element as the smallest one as well as store the
        // index so that you know which number we are dealing with
        var minimum = list[i];
        var indexMinimum = i

        // check the elements in the list ahead of our currently selected
        // element and see if there are any numbers smaller than it
        for(x in i+1 until list.size){
            // actual checking of the smaller value
            if (list[x] < minimum){
                // change our minimum value
                minimum = list[x]
                // as well as store the index of the minimum value
                indexMinimum = x
            }
        }
        // put the minimum value at the very beginning and put the beginning value
        // at the place of the minimum value
        list[i] = minimum.also { list[indexMinimum] = list[i] }
    }

    // return the sorted list
    return list
}

// driver and example code for selection sort
fun main() {
    val unsorted = listOf(20,12,10,15,2,22,35,27,16)
    val sorted = selectionSort(unsorted.toMutableList())
    print(sorted)
}