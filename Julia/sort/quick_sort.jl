"""Julia program to implement Quick sort
Quick Sort is a Divide and Conquer strategy based sorting algoithm, that partitions the array
around a selected pivot element. In the below implemented version of Quick Sort we always took the 
last element as the pivot element.

"""
function  partition(arr, low, high)
    # Select the last element as pivot
    pivot = arr[high]
    i = low - 1
    for j in low:high
        # Check if there is any element less than the pivot element
        if(arr[j] < pivot)
            i = i + 1
            # Swap such an element with the to the start position
            arr[i], arr[j] = arr[j], arr[i]
        end
    end
    # Now place the pivot to its original position
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)
end

function quick_sort(arr, low, high)
    if (low < high)
        pi = partition(arr, low, high)
        # Recursively call quick_sort function
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)
    end
end
       


print("How many numbers do you want to sort? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("No numbers to sort!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
quick_sort(arr, 1, n)
print("The numbers in sorted order is ")
print(arr)



"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
How many numbers do you want to sort? 5
Enter the numbers: 4 2 5 1 3
The numbers in sorted order is [1, 2, 3, 4, 5]

"""
