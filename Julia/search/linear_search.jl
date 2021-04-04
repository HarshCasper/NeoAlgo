"""Julia program to implement Linear Search algorithm.
Given an array, Linear Search searches for an element by traversing the entire array once
and comparing each element with the element to be found out.
"""

function linear_search(arr, n, ele)
    # Traverse the entire array once
    for i in 1:n
        if(arr[i] == ele)
            return true
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
res = linear_search(arr, n, ele)
if res
    print("The number $ele is present in the array.")
else
    print("The number $ele is not present in the array")
end


"""
Time Complexity - O(n), where 'n' is the size of the array
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
