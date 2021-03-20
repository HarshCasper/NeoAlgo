# Cocktail sort in python


def cocktailSort(arr):
    isSwapped = True
    First = 0
    Last = len(arr)-1
    while isSwapped is True:
        # reset isSwapped so that we can use it for this iteration
        isSwapped = False
        # traversing from first to last element
        for i in range(First, Last):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                isSwapped = True

        # if array is already sorted, break the loop
        if isSwapped is False:
            break

        isSwapped = False
        # last element is largest so we'll reduce last by one position.
        Last = Last-1
        # iteration from last to first element
        for i in range(Last-1, First-1, -1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                isSwapped = True
        # first element is smallest so moving a first one position ahead
        First = First+1


# number of elements
n = int(input("Enter number of elements : "))
arr = list(map(int, input("\nEnter the numbers : ").strip().split()))[:n]
cocktailSort(arr)
print("Sorted array is: ")
print(arr)


'''output:

Time complexity: O(n*n)
Space: O(1)

Enter number of elements : 5
Enter the numbers : 12 4 5 34 2
Sorted array is:
[2, 4, 5, 12, 34]

Enter number of elements : 3
Enter the numbers : 20 14 34
Sorted array is:
[14, 20, 34]
'''

