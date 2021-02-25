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

/*
    Enter the number of items to sort - 12
    Enter value 1 - 1
    Enter value 2 - 3
    Enter value 3 - 5
    Enter value 4 - 2
    Enter value 5 - 90
    Enter value 6 - 24
    Enter value 7 - 67
    Enter value 8 - 48
    Enter value 9 - 95
    Enter value 10 - 29
    Enter value 11 - 5
    Enter value 12 - 16
    unsorted list is [1, 3, 5, 2, 90, 24, 67, 48, 95, 29, 5, 16]
    sorted list is [1, 2, 3, 5, 5, 16, 24, 29, 48, 67, 90, 95]

    Time Complexity -
    Best Case Complexity: O(n*log n)
    Worst Case Complexity: O(n*log n)
    Average Case Complexity: O(n*log n)

    Space Complexity -
    The space complexity of merge sort is O(n).
 */
