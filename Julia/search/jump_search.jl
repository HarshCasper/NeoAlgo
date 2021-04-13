"""Julia program to implement Jump Search algorithm.
Jump Search is a searching algorithm similar to binary search, where a sorted array is searched. 
In this algorithm, only fewer comparisons are done, by jumping ahead some elements while traversal
"""


function jump_search(arr, num, ele)

    # Size by which the traversing index should be jumped is calculated.
    jump = floor(Int, sqrt(num))
    step = jump
    temp = 1
    
    """ The entire sorted array is divided into blocks of sqrt(n) size and the block just after which the
        required element is present is being identified. and the previous block starting index is stored in temp""" 
    while (arr[min(step, num)] < ele)
        temp = step
        step = step + jump
        if (temp >= num)
            return false
        end
    end

    # The identified block, is searched via linea search for the required element.
    while (arr[temp] < ele)
        temp = temp + 1
        if (arr[temp] == ele)
            return true
        end
        # Check if the end of the array or end of the block is reached 
        if (temp == min(step, num))
            return false
        end
    end
    if (arr[temp] == ele)
        return true
    else
        return false
    end
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
res = jump_search(arr, n, ele)
if (res == 0)
    print("The number $ele is not present in the array")
else
    print("The number $ele is present in the array.")
end



"""
Time Complexity - O(n^(0.5)), where 'n' is the size of the array
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
