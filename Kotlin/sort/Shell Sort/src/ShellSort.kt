// To Implement Shell Sort in Kotlin
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
    var i = n/2 //creating Gap
    while (i>0){
        var j = i
	//Now Performing insertion sort
        while (j<n){
            val temp = ar[j]
	    // shifting earlier gap-sorted elements until the correct location for a[j] is found 
            var k = j
            while (k>=i && ar[k-i]>temp){
                ar[k] = ar[k-i]
                k-=i
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