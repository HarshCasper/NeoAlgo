fun mergeSort(list : MutableList<Int>) : MutableList<Int>{
    // check if the given list has more than 1 elements
    if (list.size > 1){
        // a list to store sorted list
        val sortedList = MutableList(list.size) { 0 }
        // taking note of middle element of the list
        val middle = list.size / 2

        // splitting list into a left side and right side
        var leftSide = list.slice(0 until middle).toMutableList()
        var rightSide = list.slice(middle until list.size).toMutableList()

        // performing mergesort on the list and storing the results as the sides name
        leftSide = mergeSort(leftSide)
        rightSide = mergeSort(rightSide)

        var i = 0; var j = 0; var k = 0

        // getting smaller elements from the list until one of them is exhausted
        // once one list gets exhausted we know that the elements in the remaining
        // list are larger than the one's we sorted
        while (i < leftSide.size && j < rightSide.size){
            if (leftSide[i] < rightSide[j]) {
                sortedList[k] = leftSide[i]
                i++
            }
            else {
                sortedList[k] = rightSide[j]
                j++
            }
            k++
        }

        // putting the elements of leftSide if they are left after one list gets
        // exhausted
        while ( i < leftSide.size){
            sortedList[k] = leftSide[i]
            i++
            k++
        }

        // putting the elements of rightSide if they are left after one list gets
        // exhausted
        while ( j < rightSide.size){
            sortedList[k] = rightSide[j]
            j++
            k++
        }

        // returning the sorted list
        return sortedList
    }
    // if the size is less than 1 then the list is considered as sorted
    // in itself, just return the item
    return list
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

    val sorted = mergeSort(list.toMutableList());
    println("sorted list is $sorted")
}