# BUBBLE SORT

It is the simplest sorting algorithm which sorts the data in increasing order. It just bubbles up the largest value to the end by pair-wise (adjacent elements) comparisons & swapping.

You just have to traverse the collection of elements from front to end.

The steps and execution of bubble sort are explained briefly with the help of an example.

## ANALYSIS

Let us suppose that we have to sort the given array by using Bubble sort.
Index of each element in the array is written above the array in the diagrammatic representation.

a[5] = [2,1,4,5,3]
Index -> 0 1 2 3 4
Element-> 2 1 4 5 3

This is the initial position of array elements.

#### 1st pass:

Now we have to start pair-wise comparisons & on the first comparison, we find that 2 is great than 1 so both the elements are swapped.

Index -> 0 1 2 3 4
Element-> 1 2 4 5 3

On comparison of 2 & 4, we find they are already sorted so next, we compare 4 & 5 & find that they are also sorted. Hence, we didn’t swap the elements. Now we compare 5 & 3, and as 5 is greater than 3 so we swap them. All of this happens in the first pass. At the end of the first pass, the array is –

Index -> 0 1 2 3 4
Element-> 1 2 4 3 5

#### 2nd pass:

We again start form the front & start pair-wise comparisons & swap wherever necessary. On the first comparison of 1 & 2, they are not swapped as they are already sorted. Same goes for 2 & 4. On the next comparison between 4 & 3, 4 is greater than 3 is swapped with 3.

Index -> 0 1 2 3 4
Element-> 1 2 3 4 5

Now no more comparisons are required as the array is sorted.

### Another Example

Given data: (5,1,4,2,7)

#### 1st pass:

( 5 1 4 2 7 ) –> ( 1 5 4 2 7 )
( 1 5 4 2 7 ) –> ( 1 4 5 2 7 )
( 1 4 5 2 7 ) –> ( 1 4 2 5 7 )
( 1 4 2 5 7 ) –> ( 1 4 2 5 7 )

#### 2nd pass:

( 1 4 2 5 7 ) –> ( 1 4 2 5 7 )
( 1 4 2 5 7 ) –> ( 1 2 4 5 7 )
( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )
( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )

#### 3rd pass:

( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )
( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )
( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )
( 1 2 4 5 7 ) –> ( 1 2 4 5 7 )

## Time & Space Complexity of the Algorithm

The time complexity of Bubble sort is O(n2) because for a collection of data having n items, (n-1) comparisons are performed in the first pass, (n-2) in the second pass & so on. In general, (n-k) comparisons are done in the kth pass resulting in total n(n-1)/2 comparisons from which we can say that the complexity is O(n^2).

#### Worst Case Time Complexity [ Big-O]: O(n^2)

#### Best Case Time Complexity [Big-omega]: O(n)

#### Average Time Complexity [Big-theta]: O(n^2)

#### Space Complexity: O(1)

The space complexity for Bubble Sort is O(1) because only a single additional memory space is required.
