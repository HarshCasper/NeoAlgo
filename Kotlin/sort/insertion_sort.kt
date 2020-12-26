fun insertion_sort(A: Array<Int>) {
    var n = A.size
    var i: Int
    for (j in 1 until n) {
        var key = A[j]
        i = j - 1
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i]
            i--
        }
        A[i + 1] = key
    }
}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    var n = readLine()!!.toInt()

    println("Enter elements : ")
    var A = Array(n, { 0 })
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()

    insertion_sort(A)

    println("Sorted array is : ")
    for (i in 0 until n)
        print("${A[i]}  ")
}

/*
Output:

Enter no. of elements: 5
Enter elements:
22
12
33
32
11
Sorted array is:
11  12  22  32  33

*/