print("Enter the elements of the list to be sorted: ")
list = [int(x) for x in input().split(" ")]          # Space seperated input
for i in range (len(list)-1):    
    for j in range (len(list)-1):
        if (list[j] > list[j+1]):         #Checking if current element greater than the next element
            list[j], list[j+1] = list[j+1], list[j]         #Swapping the elements
print("List after sorting: ", list);         #Printing out the sorted list
