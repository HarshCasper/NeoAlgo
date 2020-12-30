// To Implement Shell Sort in Kotlin
// =================================
// Shellsort is Associate in Nursing improvement of insertion type that enables the exchange of things that area unit way apart.
// The Main idea of shell sort is to rearrange the list of elements so that, starting anywhere, taking every h-th element produces a sorted list. Such a listing is named as h-sorted.
// It can also be thought as h interleaved lists, each severally sorted.
// Starting with giant values of h permits parts to maneuver long distances within the original list, reducing giant amounts of disorder quickly, and going less work for smaller h-sort steps to try to to.
// If the list is k-sorted then for a few smaller number k, then the list remains h-sorted. Following this idea for a decreasing sequence of h values finishing in one is absolute to leave a sorted list within the end.

import java.util.*
fun main(args:Array<String>){
    println("Enter The number of elements in array:")
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val ar = Array(n) { 0 }
    println("Enter the elements of array:")
    for (i in 0 until n){
        ar[i] = sc.nextInt()
    }
    println("Sorted Array----->\n")
    //creating Gap
    var i = n/2 
    while (i>0){
        var j = i
	//Now Performing insertion sort
        while (j<n){
            val temp = ar[j]
	    // shifting earlier gap-sorted elements until the correct location for a[j] is found 
            var k = j
            while (k >= i && ar[k-i] > temp){
                ar[k] = ar[k-i]
                k -= i
            }
            ar[k] = temp
            j++
        }
        i/=2
    }
    for (el in ar){
        print("$el ")
    }
}

/*
Time Complexity :- O(N^2)
Space Complexity :- O(N)
Input:-
Enter The number of elements in array:
10
Enter the elements of array:
59
8752
215487
1548
1
458
8
48
56
23
Output:-
Sorted Array----->
1 8 23 48 56 59 458 1548 8752 215487
* */