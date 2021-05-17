# Pancake Sort:
When a spatula can be used at any place in the stack and can turn all pancakes over it, pancake sorting is a mathematical problem of sorting a disordered stack of pancakes in order of height. Least number of pancake flips required for a particular number of pancakes is called the pancake number.<br>
For an unsorted array, only the following operation can be performed:<br>
flip(arr, i): Reverse/flip the entire array from 0 to i.


#### Analysis:
Let's call the array arr[ ] and the size of the array n.<br>
• Start with the current size of n and reduce it by one while it's greater than 1. Let  curr_size be the current size. For each  curr_size, do the following.<br>
• Find the greatest element's index in arr[0..curr size-1]. Make the index ‘gi'.<br>
• Call the function flip(arr, gi) to reverse all the elements till the greatest element.<br>
• Call the function flip(arr, curr_size-1) to reverse all elements till the current size-1.

Let’s suppose an array of initial pancake order : [5, 2, 1, 7, 6, 4]<br>
• First flip : [5, 2, 1, 7, 6, 4]<br>
  after first flip : [7, 1, 2, 5, 6, 4]<br>
• Second flip : [7, 1, 2, 5, 6, 4]<br>
  after second flip : [4, 6, 5, 2, 1, 7]<br>
• Third flip : [4, 6, 5, 2, 1, 7]<br>
  after third flip : [6, 4, 5, 2, 1, 7]<br>
• Fourth flip : [6, 4, 5, 2, 1, 7]<br>
  after fourth flip : [1, 2, 5, 4, 6, 7]<br>
• Fifth flip : [1, 2, 5, 4, 6, 7]<br>
  after fifth flip : [5, 2, 1, 4, 6, 7]<br>
• Sixth flip : [5, 2, 1, 4, 6, 7]<br>
  after sixth flip : [4, 1, 2, 5, 6, 7]<br>
• Seventh flip : [4, 1, 2, 5, 6, 7]<br>
  after seventh flip : [2, 1, 4, 5, 6, 7]<br>
• Eight flip : [2, 1, 4, 5, 6, 7]<br>
  after eighth flip : [1, 2, 4, 5, 6, 7]


#### Applications:
• It is used in parallel processor networks as it provides an effective routing algorithm   between processors.<br>
• It is used when only reversing operation is allowed for sorting.


#### Complexities:
• Worst case time complexity: O(n).<br>
• Average case time complexity: O(n).<br>
• Space complexity is of order O(n).















