"""
Implementation of the MonkeySort (BogoSort) algorithm in Python.
For implementing the this algorithm, we need to import a built-in module,
named as 'random'.
A demonstration on how the random module will be used:
random_demo.py
github.com/noviicee/Search_and_Sort/blob/main/Sorting%20Algos/Monkey%20Sort/random_demo.py
The monkey sort works like what an actual monkey would do,
if it is asked to sort a given set of cards.
"""

import random


def is_sorted(data) -> bool:
	# Determine whether the data is sorted

    return all(data[i] <= data[i + 1] for i in range(len(data) - 1))


def monkey_sort(arr):

	while not is_sorted(arr):
		random.shuffle(arr)
		print("The unordered lists that we get by trying to sort the elements by shuffling them")
		print(arr)
	print("\nThe final sorted list:")
	print(arr)
	
