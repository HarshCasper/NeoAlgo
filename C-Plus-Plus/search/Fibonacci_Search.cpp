/* In this C++ program we implement a Divide and Conquer approach using Fibonacci numbers. Using Fibonacci numbers, we calculate mid of data array to search the data item. 
The time complexity of this approach is O(log(n)).

Begin
   Assign the data to the array in a sorted manner.
   Take input of the element to be searched.
   Call FibonacciSearch() function.
   Calculate the mid value using ‘start+fib[index-2]’ expression.
   If the chosen item is equal to the value at mid index, print result and return to main.
   If it is lesser than the value at mid index, proceed with the left sub-array.
   If it is more than the value at mid index, proceed with the right sub-array.
   If the calculated mid value is equal to either start or end then the item is not found in the array.
End */
