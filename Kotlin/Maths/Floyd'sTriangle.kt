/*
Print Floyd's Triangle in Kotlin
1
2 3
4 5 6
7 8 9 10
*/


import java.util.Scanner 

fun main(args: Array<String>) {
  val reader = Scanner(System.`in`)       
   print("Enter number of rows: ")  
   var rows :Int = reader.nextInt()        
   var number = 1

    for (i in 1..rows) {

        for (j in 1..i) {
            print("$number ")
            ++number
        }

        println()
    }
}

/*
Sample Test case:
Enter number of rows: 4
1
2 3
4 5 6
7 8 9 10
*/
/*
Time Complexity : O(n2)
Auxiliary Space : O(1)
*/


