# Shell Sort:
Shell sort is an in-place comparison sort. It can be observed as either a generalization of sorting by exchange or sorting by the method of insertion. The analysis starts by sorting pairs of elements far away from each other, then gradually and progressively reducing the gap between elements to be compared.


### Analysis:
1.	Calculate the value of the gap.<br>
2.	Divide the array into the sub-arrays.<br>
3.	Apply the insertion sort.<br>
4.	Repeat this process until the complete array gets sorted.<br><br>

Let's call the array arr[ ] and the size of the array n.<br>
Shell Sort(Arr, n)<br>
•	Step 1: Set flag = 1, gap_size = N<br>
•	Step 2: Repeat Steps 3 to 6 while flag = 1 or gap_size > 1<br>
•	Step 3: Set flag = 0<br>
•	Step 4: Set gap_size = (gap_size + 1) / 2<br>
•	Step 5: Repeat Step 6 for I = 0 to I < (N -gap_size)<br>
•	Step 6: If Arr[I + gap_size] > Arr[I]<br>
             swap Arr[I + gap_size], Arr[I]<br>
             set flag = 0<br>
•	Step 7: End


### Applications:
•	Calling the overhead stack.<br>
•	Recursion approach exceeds the limit.<br>
•	Insertion sort does not work well as the close elements are very far apart.


### Complexities:
•	Worst case time complexity: O(n^2).<br>
•	Best case time complexity: O(n*log n).<br>
•	Average case time complexity: O(n*log n).<br>
•	Space complexity is of order O(1).
















