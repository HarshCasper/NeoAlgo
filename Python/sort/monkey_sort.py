"""
Implementation of the MonkeySort (BogoSort) algorithm in Python.
For implementing the Monkey Sort Algorithm, we need to import a built-in module named as 'random' in Python.
A demonstration on how the random module will be used in Monkey Sort.
random_demo.py->follow: https://github.com/noviicee/Search_and_Sort/blob/main/Sorting%20Algos/Monkey%20Sort/random_demo.py
The monkey sort works somewhat like what an actual monkey would do if it is asked to sort a given set of (let's say) cards.
"""

import random


def is_sorted(data) -> bool:
# Determine whether the data is sorted

    return all(data[i] <= data[i + 1] for i in range(len(data) - 1))


def monkey_sort(arr):


	while not is_sorted(arr):
		random.shuffle(arr)
		print("You can see these are the unordered lists that we get just by trying to sort it's elements by shuffling them")
		print(arr)
	print("\nThe final sorted list:")
	print(arr)

