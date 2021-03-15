'''
bubble_sort() function uses an iterative approach sort the array in increasing
order passed as an argument. It compares adjacent elements and swappes them if
there is any larger element before the smaller element. After the first pass,
the most heaviest element shifts to the last position.
The flag is used to check if any swapping is performed or not. If no swapping is
done, the loop breaks as the array is already sorted.
Time Complexity: O(n^2)
Space Complexity: O(1)
Return Type: No return type as lists are mutable
'''
def bubble_sort(Array):
    for i in range (len(Array)-1):
        flag = True
        for j in range (len(Array)-1):
            if (Array[j] > Array[j+1]):
                flag = False
                Array[j], Array[j+1] = Array[j+1], Array[j]
        if flag:
            break

if __name__=="__main__": 
    print("Enter the elements of the list to be sorted: ")
    Array = [int(x) for x in input().split(" ")]
    bubble_sort(Array)
    print("List after sorting: ")
    for i in Array:
        print(i,end=" ")
