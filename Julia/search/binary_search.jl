"""Julia program to implement Binary Search algorithm.
Binary Search is a Divide and Conquer strategy based algorithm, where the entire array is divided into two halfs and the
required element is searched for in one of these sections as per the conditions. It is done on sorted arrays.
"""

function binary_search(arr, n, ele)
    low = 1
    high = n
    while high >= low
        mid = low + (high - low) ÷ 2
        # If the mid element is the required element, return that index
        if(arr[mid] == ele)
            return mid
        # ele is greater than mid element then ele would be present in first half of the array
        elseif (arr[mid] > ele)
            high = mid - 1
        #Else if  ele is smaller than mid element then ele would be present in last half of the array
        else
            low = mid + 1
        end
    end
    # If the element is not found return 0
    return 0
end


print("How many numbers are present in the array? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("Array is Empty!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())] 
print("Which number do you want to search in the array? ")
ele = readline()
ele = parse(Int, ele)
# Sort the array in ascending order
arr = sort(arr)
res = binary_search(arr, n, ele)
if (res == 0)
    print("The number $ele is not present in the array")
else
    print("The number $ele is present in the array.")
end


"""
Time Complexity - O(log(n)), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers are present in the array? 5 
Enter the numbers: 1 2 3 4 5
Which number do you want to search in the array? 6
The number 6 is not present in the array

SAMPLE II

How many numbers are present in the array? 3
Enter the numbers: 3 1 2
Which number do you want to search in the array? 2
The number 2 is present in the array.

"""
