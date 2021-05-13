"""Julia program to implement Ternary Search algorithm.
Ternary Search is a Divide and Conquer strategy based algorithm similar to binary search.
Here we divide the entire array into three parts and iteratively search for the required element
"""

function ternary_search(arr, low, high, ele)
    while (high >= low)
        # FInd the two required midpoints to divide the array into three.
        midA = low + (high - low) ÷ 3
        midB = high - (high - low) ÷ 3
        # Search, if the element is present in the midpoint indices
        if (arr[midA] == ele)
            return true
        elseif (arr[midB] == ele)
            return true
        end
    
        # Identify the part in which the required element belongs to 
        if (ele < arr[midA])
            high = midA - 1
        elseif (ele > arr[midB])
            low = midB + 1
        else
            low = midA + 1
            high = midB - 1
        end
    end
    return false
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
res = ternary_search(arr, 1, n, ele)
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
