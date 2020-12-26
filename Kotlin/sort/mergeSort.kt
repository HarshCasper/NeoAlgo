fun main(args: Array<String>) {
    val array = readLine()!!.split(" ").map { it.toInt() }.toIntArray() // 1) Read the input and split into array
    mergeSort(array)

    for(i in array) println(i)
   }
   
   fun mergeSort(array : IntArray, helper:IntArray = IntArray(array.size), low:Int = 0, high : Int = array.size-1) {
    if(low < high) {
        val middle:Int = (low+high)/2 // 2) calculating the middle element
        mergeSort(array, helper, low, middle) // 3) to sort left half
        mergeSort(array, helper, middle+1, high) // 4) to sort right half
        merge(array, helper, low, middle, high) // 5) Merge them
    }
}

fun merge (array: IntArray, helper: IntArray, low: Int, middle:Int, high: Int){
   // a) copying both halves into helper array
    for(i in low..high) helper[i] = array[i]
    
    var helperLeft = low
    var helperRight = middle + 1 // b) helper variables
    var current = low
    
    /*Iterate through helper array. Compare the left and right half, copying back the smaller element
    * from the two halves into original array*/
    
    while (helperLeft <= middle && helperRight <= high) { // c) condition to check helper left and helper right
        if(helper[helperLeft] <= helper[helperRight]) { // d) Check if value at helperLeft index is less than that of value at helper right
            array[current] = helper[helperLeft]
            helperLeft++
        } else { // e) right element is smaller than left element
            array[current] = helper[helperRight]
            helperRight++
        }
        current++
    }

   // f) copy the rest of leftside of array into target
    val remaining = middle – helperLeft
    for (i in 0..remaining) {
    array[current + i] = helper[helperLeft + i]
    }

}

//PS: time complexity for mergesort = O(n log n) for average case