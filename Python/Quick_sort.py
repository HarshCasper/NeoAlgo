#Quick Sort:  Divide and Conquer algorithm
#best and average time complexity: O(nlogn)
#Worst time complexity: O(n^2)
  

#This funtion is used for the partition of the input array or list
def partition(lis, low, high):

    # Select the pivot element
    pivot = lis[high]
    i = low - 1

    #Changing the postion of the elements. Smaller elements to the left of pivot
    # and greater elemenr from pivot to the right.
    for j in range(low, high):
        if lis[j] <= pivot:
            i = i + 1
            (lis[i], lis[j]) = (lis[j], lis[i])

    (lis[i + 1], lis[high]) = (lis[high], lis[i + 1])

    return i + 1


def quickSort(lis, low, high):
    if low < high:

        # Select pivot position and put all the elements smaller 
        # than pivot on left and greater than pivot on right
        pi = partition(lis, low, high)

        # Sort the elements on the left of pivot
        quickSort(lis, low, pi - 1)

        # Sort the elements on the right of pivot
        quickSort(lis, pi + 1, high)


print("Enter the elements which are to be sorted: ")
list = [int(x) for x in input().split(" ")]   
size = len(list)

#passing the list, first postion of the first element and the size of the list.
quickSort(list, 0, size - 1)

print("List after sorting: ", list)


