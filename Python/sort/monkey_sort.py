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
	"""
	Takes in any data (here array), and returns a boolean expression:
	True if the array is sorted
	False if the array is not sorted
	"""

	return all(data[i] <= data[i + 1] for i in range(len(data) - 1))


def monkey_sort(arr):
	""" Takes in an array, returns the array in sorted form """

	while not is_sorted(arr):
		random.shuffle(arr)
		print("Unordered lists by sorting the elements by shuffling them")
		print(arr)
	print("\nThe final sorted list:")
	return(arr)

if __name__ == "__main__" :
    number_of_elements = int(input("Enter the number of elements : "))
    print("Enter the elements:")
    unsorted_array=list(map(int, input().split()))

    # calling the monkey_sort function
    sorted_array = monkey_sort(unsorted_array)
    print(sorted_array)
