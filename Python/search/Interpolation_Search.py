# INTERPOLATION SEARCH

# If the searching element is present in array,
# then it returns index of it, else returns -1


def interpolationSearch(arr, size, search_element):
    # Assigning indexes
    low = 0
    high = size - 1
    # As array is going to be sorted
    # an element present in array must be in range defined by corner
    while low <= high and search_element >=
    arr[low] and search_element <= arr[high]:
        if low == high:
            if arr[low] == search_element:
                return low
            return -1

        position = low + int(float(high - low) /
        (arr[high] - arr[low])*(search_element - arr[low]))

        # Condition of element found

        if arr[position] == search_element:
            return position

        # If x is larger, x is in upper part

        if arr[position] < search_element:
            low = position + 1
        else:
            # If x is smaller, x is in lower part
            high = position - 1

    return -1


# Starting with the main code
# Creating array of the size n
# Size would be taken into the variable n from user
def main():
    arr = []
    size = int(input('Enter the size of array : '))

    # Entering the elements in the array

    print ('Enter elements :')
    for index in range(0, size):
        ele = int(input())
        arr.append(ele)
    print ('The elements entered are:\n', arr, '\n')

    # Sorting our array

    print ('The sorted array is: ')
    arr.sort()
    print (arr, '\n')

    # Entering the searching element

    search_element = int(input('Enter the element to be searched: '))

    index = interpolationSearch(arr, size, search_element)

    # If element was found

    if index != -1:
        # Returning the index of the element
        print ('Element found at index', index)
    else:
        # Returning -1 as element has not found
        print ('Element not found')
main()

""""
SAMPLE INPUT:
5
1
5
7
2
9
7
SAMPLE OUTPUT:
Enter the size of array : Enter elements :
The elements entered are:
[1, 5, 7, 2, 9]
The sorted array is:
[1, 2, 5, 7, 9]
Enter the element to be searched: Element found at index 3
Time Complexity of Interpolation Search Algorithm
Average Case: O (log log n)
Worst Case: O(N)
Space Complexity of Interpolation Search Algorithm is O(1)
"""
