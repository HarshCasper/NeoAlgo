fun quick_sort(A: Array<Int>, p: Int, r: Int) {
    if (p < r) {
        var q: Int = partition(A, p, r)
        quick_sort(A, p, q - 1)
        quick_sort(A, q + 1, r)

    }
}

fun partition(A: Array<Int>, p: Int, r: Int): Int {
    var x = A[r]
    var i = p - 1
    for (j in p until r) {
        if (A[j] <= x) {
            i++
            exchange(A, i, j)
        }
    }
    exchange(A, i + 1, r)
    return i + 1
}

fun exchange(A: Array<Int>, i: Int, j: Int) {
    var temp = A[i]
    A[i] = A[j]
    A[j] = temp
}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    var n = readLine()!!.toInt()

    println("Enter elements : ")
    var A = Array(n, { 0 })
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()

    quick_sort(A, 0, A.size - 1)

    println("Sorted array is : ")
    for (i in 0 until n)
        print("${A[i]}  ")
}

/*
Output: 

Enter no. of elements: 5
Enter elements:
10
34
22
56
74
Sorted array is:
10  22  34  56  74

*/