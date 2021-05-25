"""Julia program to implement Minimum XOR value.
Given an array of integers, we have to find the minimum XOR value, a pair in the array makes."""


function minimumXOR(arr, n)
    # Sort the array, so that elements with minimum bit difference are present consecutive.
    sort(arr)
    minXOR = typemax(Int64)
    val = 0

    # Compute the XOR values of the consecutive elements of the array.
    for i in 1:(n-1)
        val = arr[i] ⊻ arr[i+1]
        minXOR = min(minXOR, val)
    end

    return minXOR
end



print("How many numbers are present in the array? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("No numbers are present in the array!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
res = minimumXOR(arr, n)
print("The minimum XOR value present in the given array is $res")


"""
SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers are present in the array? 8
Enter the numbers: 25 45 36 458 651 89 52 95 
The minimum XOR value present in the given array is 9

SAMPLE II

How many numbers are present in the array? 5
Enter the numbers: 5 4 3 2 1
The minimum XOR value present in the given array is 1

"""
