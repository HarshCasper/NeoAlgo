
def merge (array, left, mid, right) :
    firstPortionLength = mid - left + 1 # The (+1) to take the middle element itself
    secondPortionLength = right - mid

    firstPortionArray = []
    secondPortionArray = []

    for i in range (0, firstPortionLength) :
        firstPortionArray[i] = array[left + i]
    for i in range (0, secondPortionLength) :
        secondPortionArray[i] = array[mid + i + 1]  # The (+1) here, because the second portion starts after the mid element

    i = j = 0
    k = left

    while i < firstPortionLength and j < secondPortionLength :
        if firstPortionArray[i] <= secondPortionArray[j] :
            array[k] = firstPortionArray[i]
            i += 1
        else :
            array[k] = secondPortionArray[j]
            j += 1
        k += 1

    # one of the next two while loops, will be executed only (to add the remaining elements)
    while i < firstPortionLength :
        array[k] = array[i]
        i += 1
        k += 1
    while j < secondPortionLength :
        array[k] = array[j]
        j += 1
        k += 1

def insertionSort (array, start, end) :
    length = len(array)
    for k in range (1 + start, end + 1) :
        temp = array[k]
        j = k - 1

        while j >= 0 and temp < array[j] :
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = temp

RUN = 32

def timSort(array):
    length = len(array)
    # Sort individual subarrays of size RUN
    for start in range(0, length, RUN):
        end = min(start + RUN - 1, length - 1)
        insertionSort(array, start, end)

    size = RUN
    while size < length:
        # Merge each two consecutive runs, to make a bigger run
        # then merge every two of the new runs, and so on..
        for left in range(0, length, 2 * size):
            mid = min(left + size - 1, length - 1)
            right = min((left + 2 * size - 1), (length - 1))

            if mid < right:     # if both of mid & right == n - 1, then don't merge (array is already merged)
                merge(arr, left, mid, right)

        size = 2 * size

arr = list (map (int, input ('Enter the Array: ').split ()))
timSort(arr)
print (arr)