# LINEAR SEARCH

It is a sequential method of searching a particular element within the given list of elements. The number is searched sequentially, one after another position in the given list. It works at a worst linear time & makes the maximum of n comparisons.

Example –
Given list : 3,2,8,4,6,9,1

#### Best Case Scenario

Element to be searched is 3

No. of comparison = 1 as 3 is present at the first position in the list to be searched.

#### Average Case Scenario

Element to be searched is present in the middle, i.e 4

We start from the first element i.e. 3, & finally, we get 4 after 4 comparisons.

#### Worst Case Scenario

Element to be searched is 1

We start comparisons from the first element in the list & move forward.

No. of comparisons = 7 as 1 is present at the 7th position in the list.

## Time & Space Complexity of the Algorithm

#### Worst Case Time Complexity [ Big-O]: O(n) (when the element to be searched is last in the list)

#### Best Case Time Complexity [Big-omega]: O(1) (when the element to be searched is the first element in the list)

#### Average Time Complexity [Big-theta]: O(n/2)

#### Space Complexity: O (1)
