"""Julia program to Find Noble Integer in an array.
Given an array arr, an integer ele is said to be noble integer if
the number of integers greater than ele is equal to ele.
If such an element is not found Return -1. 
"""

function search_noble_integer(arr, n)
    # Traverse the entire array
    for i in 1:(n-1)
        if (arr[i] == arr[i+1])
            continue
        end
        #  If arr[i] equals the number of elements after arr[i], it is a noble Integer
        if(arr[i] == (n - i))
            return arr[i]
        end
    end
    if(arr[n] == 0)
        return arr[n]
    end
    return -1
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
# Sort the array in ascending order
arr = sort(arr)
res = search_noble_integer(arr, n)
if (res == -1)
    print("A Noble Integer is not present in the array.")
else
    print("A Noble Integer $res is  present in the array.")
end


"""
Time Complexity - O(n * log(n)), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers are present in the array? 5
Enter the numbers: 12 34 3 1 99
A Noble Integer 3 is  present in the array.

SAMPLE II

How many numbers are present in the array? 5 
Enter the numbers: 5 4 3 2 1
A Noble Integer is not present in the array.

"""
