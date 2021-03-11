#Adaptive Bubble Sort (Loop runs only till the array is unsorted)

print("Enter the elements of the list to be sorted: ")
Array = [int(x) for x in input().split(" ")]          # Space seperated input
for i in range (len(Array)-1):
    flag = True # Flag for checking if the array is sorted or not
    for j in range (len(Array)-1):
        if (Array[j] > Array[j+1]):         #Checking if current element greater than the next element
            flag = False #The array is still unsorted
            Array[j], Array[j+1] = Array[j+1], Array[j]         #Swapping the elements
    if flag: #Checking if the array is already sorted
        break
print("List after sorting: ")#Printing out the sorted list
for i in Array:
    print(i,end=" ")
