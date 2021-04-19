# SELECTION SORT
It is a simple sorting algorithm which sorts the data in an increasing order. It divides the data into 2 parts, where left part is sorted & right part is unsorted. Initially, left part is empty & whole collection of data lies in the right part. From unsorted array(right part), smallest element is selected & swapped with the leftmost element. The process continues until the data is sorted.<br>
The steps and execution of selection sort is explained briefly with the help of an example.<br>
## ANALYSIS
Let us suppose that we have to sort the given array by using Selection sort.<br>
Index of each element in the array is written above the array in the diagrammatic representation.<br>
a[5] = [2,1,4,5,3]<br>
Index  ->  0     1      2      3      4<br>
Element->  2     1      4      5      3<br>
This is the initial position of array elements.<br>
#### 1st pass:<br> 
To select first element for the sorted array, we choose the smallest element from the given data. Initially, 2 is stored in the first position & smallest no present in the unsorted array is 1. So, 2 is swapped with 1.<br>
Index  ->  0     1      2      3      4<br>
Element->  1     2      4      5      3<br>
#### 2nd pass:
Now for the second position we see the smallest no present is 2 which is already placed at 2nd position. So no swapping occurs.<br>
Index  ->  0     1      2      3      4<br>
Element->  1     2      4      5      3<br>
#### 3rd pass:
Now for the 3rd position we find the smallest no from the remaining values, which is 3. So now 4 is swapped with 3.<br>
Index  ->  0     1      2      3      4<br>
Element->  1     2      3      5      4<br>
#### 4th pass:
Now for the 4th position we choose the smallest no which is 4. So, now 5 is swapped with 4. The resulting array after this swap is sorted.<br>
Index  ->  0     1      2      3      4<br>
Element->  1     2      3      4      5<br>
## Time & Space Complexity of the Algorithm
#### Worst Case Time Complexity [ Big-O]: O($n^2$) comparisons & O(n) swaps
#### Best Case Time Complexity [Big-omega]: O($n^2$) comparisons & O(1) swaps.
#### Average Time Complexity [Big-theta]: O($n^2$) comparisons & O(n) swaps
#### Space Complexity: O (1) 

