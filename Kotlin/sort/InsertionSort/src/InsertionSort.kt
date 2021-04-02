fun insertionSort(array: MutableList<Int>) : List<Int> {
    // go from the 2nd item in the list till the last item
    for (i in 1 until array.size){
        // store the value
        val value = array[i]
        // store the index of the value
        var temp = i

        /*
        for every new_value below the index of the value
        if the new_value is greater than the value

        if the value is not greater than the loop will end
        */
        while ((array[temp - 1] > value) and (temp >= 0)) {
            // put new_value one index above the current value
            array[temp] = array[temp - 1]
            // decrease the temporary index
            temp -= 1
        }
        /*
            when the loop has ended we know that the value at index
            less then current temp is lesser than current value so
            replace value at temp and close the loop
        */

        array[temp] = value
    }
    return array
}

fun main() {
    print("Enter the number of items to sort - ")
    val lengthOfList = readLine()!!.toInt()

    val list = MutableList(lengthOfList) { 0 }
    list.withIndex().forEach {
        print("Enter value ${it.index + 1} - ")
        list[it.index] = readLine()!!.toInt()
    }
    println("unsorted list is $list")

    val sorted = insertionSort(list.toMutableList());
    println("sorted list is $sorted")
}
