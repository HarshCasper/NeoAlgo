# Python program for implementation of Shell Sort


def shellSort(arr):

    # Start with a big gap, then reduce the gap

    size = len(arr)
    gap = size // 2

    # Do a gapped insertion sort for this gap size.

    while gap > 0:

        for i in range(gap, size):

            # add a[i] to the elements that have been gap sorted
            # save a[i] in temp and make a hole at position i

            temp = arr[i]

            # shift earlier gap-sorted elements up until the correct
            # location for a[i] is found

            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # put temp (the original a[i]) in its correct location

            arr[j] = temp
        gap //= 2

arr = []

size = int(input('Enter size: '))
print ('Enter elements:')
for i in range(0, size):
    item = int(input())
    arr.append(item)

shellSort(arr)

print ('\nSorted Array:')
for i in range(size):
    print (arr[i])
