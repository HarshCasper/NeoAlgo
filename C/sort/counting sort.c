/* Counting Sort in C - Counting sort is a sorting algorithm that sorts 
the elements of an array by counting the number of occurrences of each unique 
element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

# The average time complexity for Counting Sort is O(n+k). 
# Worst Case Complexity: O(n+k)
# Best Case Complexity: O(n+k)
# Overall complexity = O(max)+O(size)+O(max)+O(size) = O(max+size)

# Counting Sort Algorithm
countingSort(array, size)
  max <- find largest element in array
  initialize count array with all zeros
  for j <- 0 to size
    find the total count of each unique element and 
    store the count at jth index in count array
  for i <- 1 to max
    find the cumulative sum and store it in count array itself
  for j <- size down to 1
    restore the elements to array
    decrease count of each element restored by 1
