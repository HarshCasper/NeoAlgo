"""
BogoSort is also known as permutation sort, and/or stupid sort.
Imagine throwing a pile of cards, and then search for 2 pre-determined cards.
You pick 2 cards, match them if they are the ones you need, if not, you throw them back in the pile.
Pick 2 cards again, match them till you get the required pair. Yes it is stupid, slow and depends upon Luck.

The algorithm successively generates permutations of its input until it finds one that is sorted.
"""
import time
import random

n = int(input("Please Enter the number of Elements you want in Array: "))
# takes the whole line of n numbers
arr = input(
    "Enter the elements separated by a WhiteSpace, for e.g. <1 2 3 4 5>: ")
final_array = list(map(int, arr.split(' ')))


def is_sorted(data) -> bool:
    """
    Determine the Array is sorted or not.
    Returns: bool
    """
    return all(data[i] <= data[i + 1] for i in range(len(data) - 1))


def bogo_sort(final):
    """
    Takes an array and applies Bogo Sorting algorithm it.
    """
    count = 0
    while not is_sorted(final):
        random.shuffle(final)
        print("Shuffling the array randomly.")
        print(final)
        time.sleep(2)
        count += 1
    print("\nObtained the sorted list (after {} round):".format(count - 1))
    print(final)


bogo_sort(final_array)


"""
Test Case 1:

Please Enter the number of Elements you want in Array: 4
Enter the elements separated by a WhiteSpace, for e.g. <1 2 3 4 5>: 2 1 4 3
Shuffling the array randomly.
[3, 2, 4, 1]
Shuffling the array randomly.
[2, 1, 4, 3]
Shuffling the array randomly.
[1, 4, 3, 2]
Shuffling the array randomly.
[3, 2, 4, 1]
Shuffling the array randomly.
[2, 1, 3, 4]
Shuffling the array randomly.
[1, 4, 2, 3]
Shuffling the array randomly.
[2, 3, 1, 4]
Shuffling the array randomly.
[3, 4, 1, 2]
Shuffling the array randomly.
[1, 2, 3, 4]

Obtained the sorted list (after 8 round):
[1, 2, 3, 4]

Process finished with exit code 0

## Number of rounds for the Same array can be different. SEE TEST CASE 2 ##

Test Case 2:

Please Enter the number of Elements you want in Array: 4
Enter the elements separated by a WhiteSpace, for e.g. <1 2 3 4 5>: 2 1 4 3
Shuffling the array randomly.
[1, 3, 4, 2]
Shuffling the array randomly.
[2, 4, 1, 3]
Shuffling the array randomly.
[2, 1, 4, 3]
Shuffling the array randomly.
[1, 2, 4, 3]
Shuffling the array randomly.
[1, 4, 2, 3]
Shuffling the array randomly.
[1, 3, 4, 2]
Shuffling the array randomly.
[1, 2, 4, 3]
Shuffling the array randomly.
[1, 2, 3, 4]

Obtained the sorted list (after 7 round):
[1, 2, 3, 4]

Process finished with exit code 0

_____________________________________________
Time Complexity:
Worst Case : O(∞) [no upper bound]
Average Case: O(n*n!)
Best Case : O(n) [array is already sorted]
"""
