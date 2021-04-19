/*
QuickSort Algortihm works on Divide and Conquer Algorithm. It creates two empty arrays to hold elements less than the pivot value and
elements greater than the pivot value, and then recursively sort the sub arrays. There are two basic operations in the algorithm, 
swapping items in place and partitioning a section of the array.
*/

//Importing the Java.util package, it is needed because we are using the scanner object.
import java.util.*

//The function which will sort the given array in ascending order using QuickSort Algortihm
fun quicksort(items:List<Int>):List<Int>{
    //If there is only one element in the list, then there is no need to sort
    if (items.count() < 2){
        return items
    }
   
    //Vaiable pivot stores the index of middle element of the list
    val pivot = items[items.count()/2]
    
    //Variable equalto stores the elements at the pivot index
    val equalto = items.filter { it == pivot }
    
    //Variable lesser stores the list of element with indexes less than the pivot index
    val lesser = items.filter { it < pivot }
   
    //Variable greater stores the list of element with indexes less than the pivot index
    val greater = items.filter { it > pivot }
    
    //Calling the quicksort function recursively on the splitted arrays
    //This will get recursively called until left with multiple arrays with a single element and arranged in order
    return quicksort(lesser) + equalto + quicksort(greater)
}
//Main Driver Code
fun main() {
    val input = Scanner(System.`in`)

    println("Enter the length of the array")
    val arrayLength = input.nextInt()
    val arrayOfElements = arrayListOf<Int>()

    println("Enter the List of numbers you want to Sort:")
    for(index in 0 until arrayLength) {
        val element = input.nextInt()
        arrayOfElements.add(element)
    }
    print("Original List: ")
    for(index in 0..4)
    {
        val number: Int = arrayOfElements[index]
        print("$number\t")
    }
    print("\nOrdered list: ")
    val ordered =  quicksort(arrayOfElements)
    println(ordered)
}

/*
First Testcasee:
Enter the length of the array
6
Enter the List of numbers you want to Sort:
34
33
67
3
2
45
Original List: 34	33	67	3	2   45	
Ordered list: [2, 3, 33, 34, 45, 67]

Time Complexity: O(n log n)
Space Complexity: O(log n)
*/