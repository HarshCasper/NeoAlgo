#Implementation of the MonkeySort (BogoSort) algorithm in Python.

#For implementing the Monkey Sort Algorithm, we need to import a built-in module named as 'random' in Python.

#A demonstration on how the random module will be used in Monkey Sort.
#random_demo.py->follow: https://github.com/noviicee/Search_and_Sort/blob/main/Sorting%20Algos/Monkey%20Sort/random_demo.py

#The monkey sort works somewhat like what an actual monkey would do if it is asked to sort a given set of (let's say) cards.

def is_sorted(data) -> bool:
    """Determine whether the data is sorted."""
    return all(data[i] <= data[i + 1] for i in range(len(data) - 1))

import random
def monkey_sort(arr):
	while not is_sorted(arr):
		random.shuffle(arr)
		print("You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them")
		print(arr)
	print("\nThe final sorted list:")
	print(arr)

monkey_sort([1,2,8,3])

#Result-
"""
>>> monkey_sort.py
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 8, 3, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 3, 2, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 3, 2, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 2, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 8, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 3, 8, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 3, 1, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 3, 1, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 1, 8, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 8, 1, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 2, 8, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 8, 3, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 2, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 2, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 2, 3, 8]
The final sorted list:
[1, 2, 3, 8]
"""

#Just in case you are not able to visualize it fully-


import time
"""just for a better visulaization of the execution"""
def is_sorted(data) -> bool:
    """Determine whether the data is sorted."""
    return all(data[i] <= data[i + 1] for i in range(len(data) - 1))

import random
def monkey_sort(arr):
	count=0
	while not is_sorted(arr):
		random.shuffle(arr)
		print("You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them")
		print(arr)
		time.sleep(2)
		count+=1
	print("\nThe final sorted list (after {} round of shuffling):".format(count))
	print(arr)

monkey_sort([1,2,8,3])

#Results-
"""
>>> monkey_sort.py
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 1, 3, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 8, 1, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 8, 1, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 3, 2, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 1, 2, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 2, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 3, 2, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 8, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 2, 3, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 2, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 1, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 3, 8, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 3, 1, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 8, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 8, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 8, 1, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 3, 1, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 1, 8, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 1, 3, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 8, 1, 3]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[2, 3, 8, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 2, 8, 1]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 8, 1, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[8, 1, 3, 2]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[3, 2, 1, 8]
You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them
[1, 2, 3, 8]
The final sorted list (after 28 rounds of shuffling):
[1, 2, 3, 8]
"""

"""Just to mention that the '28 rounds' is really optional. The algorithm may take even less than that or even far more from that"""