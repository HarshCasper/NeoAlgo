# RADIX SORT

It is a non-comparative sorting algorithm. It is used for sorting the array which contains numbers in the range of 1 to $n^2$. It performs digit by digit sort starting from least significant digit to most significant digit.

The steps and execution of radix sort are explained briefly with the help of an example.

## ANALYSIS

Input Data: 170, 45, 75, 90, 802, 24, 2, 66
We start sorting from the least significant digit.

##### Sorting by one’s place

[{170, 90}, {02, 802, 02}, {45, 75}, {66}

##### Sorting by ten's place

[{02, 802, 02}, {45}, {66}, {170, 75}, {90}]

##### Sorting by hundreds place

[{002, 002, 045, 066, 075, 090}, {170}, {802}]

## Time & Space Complexity of the Algorithm

#### Worst Case Time Complexity [ Big-O]: O(w.n) where w is the no of bits required to store each value.

#### Worst Case Space Complexity : O(w+n)
