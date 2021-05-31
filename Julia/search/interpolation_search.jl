"""Julia program to implement Interpolation Search algorithm.
It is simliar to a person searching for a name in a telephone directory 
The algorithm calculates where in the remaining array space the required item would be, 
based on the values at the bounds of the search space and the required element, usually via a linear interpolation
"""

function interpolation_search(arr, n, ele)
    low = 1
    high = n
    while low <= high && ele >= arr[low] && ele <= arr[high]
        if(low == high)
            # If element found
            if(arr[low] == ele)
                return true
            end
            return false
        end
        # Formula to return the value of 'pos'
        pos = low + (((high - low) ÷ (arr[high] - arr[low]))* (ele - arr[low]))
        # If the pos element is the required element, return that index
        if(arr[pos] == ele)
            return true
        end
        # Else find the section of the array in which the required element belongs to
        if(arr[pos] < ele)
            low = pos + 1
        else
            high = pos - 1
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
res = interpolation_search(arr, n, ele)
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
