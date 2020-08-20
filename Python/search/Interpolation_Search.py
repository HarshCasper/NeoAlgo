# INTERPOLATION SEARCH

# If the searching element is present in array, then returns index of it, else returns -1


def interpolationSearch(arr, n, x):

    # Assigning indexes

    low = 0
    high = n - 1

    # As array is going to be sorted, an element present in array must be in range defined by corner

    while low <= high and x >= arr[low] and x <= arr[high]:
        if low == high:
            if arr[low] == x:
                return low
            return -1

        pos = low + int(float(high - low) / (arr[high] - arr[low]) * (x
                        - arr[low]))

        # Condition of element found

        if arr[pos] == x:
            return pos

        # If x is larger, x is in upper part

        if arr[pos] < x:
            low = pos + 1
        else:

        # If x is smaller, x is in lower part

            high = pos - 1

    return -1


# Starting with the main code
# Creating array of the size n
# Size would be taken into the variable n from user

arr = []
n = int(input('Enter the size of array : '))

# Entering the elements in the array

print 'Enter elements :'
for i in range(0, n):
    ele = int(input())
    arr.append(ele)
print ('The elements entered are:\n', arr, '\n')

# Sorting our array

print 'The sorted array is: '
arr.sort()
print (arr, '\n')

# Entering the searching element

x = int(input('Enter the element to be searched: '))

index = interpolationSearch(arr, n, x)

# If element was found

if index != -1:
    print ('Element found at index', index)  # Returning the index of the element
else:
    print 'Element not found'  # Returning -1 as element has not found

#SAMPLE INPUT:
#5
#1
#5
#7
#2
#9
#7

#SAMPLE OUTPUT:
#Enter the size of array : Enter elements :
#The elements entered are:
# [1, 5, 7, 2, 9] 

#The sorted array is: 
#[1, 2, 5, 7, 9] 

#Enter the element to be searched: Element found at index 3

#Time Complexity of Interpolation Search Algorithm
#Average Case: O (log log n) 
#Worst Case: O(N)

#Space Complexity of Interpolation Search Algorithm is O(1)
