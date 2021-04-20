# Julia program to implement Circle Sort

# Performs recursive circular swaps and returns true if atleast one swap occurs
function rec_sort(arr, high, low)
    isSwap = false

    # If concerned array is empty, Return False
    if (high == low) 
        return false
    end

    # Storing the values of beg, end to later use in the recursive call
    highA = high
    lowA = low
    while( highA < lowA) 
        if (arr[highA] > arr[lowA]) 
            arr[highA], arr[lowA] = arr[lowA], arr[highA] 
            isSwap = true;
        end
        highA = highA + 1
        lowA = lowA - 1
    end

    # If the array has odd number of elements
    if (highA == lowA) 
        if (arr[highA] > arr[lowA + 1])     
            arr[high], arr[lowA+1] = arr[lowA+1], arr[high] 
            isSwap = true
        end
    end

    mid = (low - high) ÷ 2
    isSwapA = rec_sort(arr, high, high+mid)
    isSwapB = rec_sort(arr, high+mid+1, low)

    return (isSwap || isSwapA || isSwapB)
end


function circle_sort(arr, n)
    while (rec_sort(arr, 1, n))
    end 
end


print("How many numbers do you want to sort? ")
n = readline()
n = parse(Int64, n)
if (n <= 0)
    println("No numbers to sort!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
circle_sort(arr, n)
print("The numbers in sorted order is ")
print(arr)



"""
Time Complexity - O(n * log(n)), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers do you want to sort? 6
Enter the numbers: 76 243 89 25 8337 72
The numbers in sorted order is [25, 72, 76, 89, 243, 8337]

SAMPLE II

How many numbers do you want to sort? -3
No numbers to sort!!!
"""
