# HEAP SORT

It is a comparison-based sorting algorithm. It is a kind of improved selection sort. It is based on the binary heap data structure. We first have to create a heap with the input data & then a sorted array is created by repeatedly removing the largest element from the heap and inserting it into the array. The heap is updated after each removal to maintain the heap property.

Input data : 4,9,3,7,2

<pre>
1) First of all we need to create a max heap with the input data.
 4(0) Array -
 / \ Index: 0 1 2 3 4
 9(1) 3(2) Elements: 4 9 3 7 2
 / \
 7(3) 2(4)

2) Then we swap the first element of the list with the final element & decrease the range of list by 1. Now we shift the new first element to its appropriate index in the heap & keep doing this recursively till the range of the list is one element.
After comparison at index 1, the heap remains the same.
After comparisons & swapping at index 0, the heap becomes
 9(0) Array -
 / \ Index: 0 1 2 3 4
 7(1) 3(2) Elements: 9 7 3 4 2
 / \
 4(3) 2(4)
After next comparison & swap, the heap becomes
 9(0) Array –
 / \ Index: 0 1 2 3 4
 7(1) 4(2) Elements: 9 7 4 3 2
 / \
 3(3) 2(4)

Finally, the array is sorted.
</pre>

## Time & Space Complexity of the Algorithm

#### Worst Case Time Complexity [ Big-O]: O(n.logn)

#### Best Case Time Complexity [Big-omega]: O(n.logn)

#### Average Time Complexity [Big-theta]: O(n.logn)

#### Space Complexity: O (1)
