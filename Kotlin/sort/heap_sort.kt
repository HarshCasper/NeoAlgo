var heapSize = 0

fun left(i: Int): Int {
    return 2 * i
}

fun right(i: Int): Int {
    return 2 * i + 1
}

fun swap(A: Array<Int>, i: Int, j: Int) {
    var temp = A[i]
    A[i] = A[j]
    A[j] = temp
}

fun max_heapify(A: Array<Int>, i: Int) {
    var l = left(i);
    var r = right(i);
    var largest: Int;

    if ((l <= heapSize - 1) && (A[l] > A[i])) {
        largest = l;
    } else
        largest = i

    if ((r <= heapSize - 1) && (A[r] > A[l])) {
        largest = r
    }

    if (largest != i) {
        swap(A, i, largest);
        max_heapify(A, largest);
    }
}

fun buildMaxheap(A: Array<Int>) {
    heapSize = A.size
    for (i in heapSize / 2 downTo 0) {
        max_heapify(A, i)
    }
}

fun heap_sort(A: Array<Int>) {
    buildMaxheap(A)
    for (i in A.size - 1 downTo 1) {
        swap(A, i, 0)
        heapSize = heapSize - 1
        max_heapify(A, 0)

    }
}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    var n = readLine()!!.toInt()

    println("Enter elements : ")
    var A = Array(n, { 0 })
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()

    heap_sort(A)

    println("Sorted array is : ")
    for (i in 0 until n)
        print("${A[i]}  ")
}

/*
Output:
Enter no. of elements :5
Enter elements :
12
23
44
54
1
Sorted array is :
1  12  23  44  54  
*/ 