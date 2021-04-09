#= For any given array there are 2^N subsets. Thus generating each and every subset using BitMasking.
We follow the binary representation of whole numbers and use them as boolean value if a character in the Set
will occur or not. We will remove the duplicate subsets and display the non null unique subsets.
=#

## Function 

function subsets(array, n)
    println("The subsets are: ")
    powerSet = Set()
    for i = 1:(1<<n)
        s = ""
        for j = 1:n
            if (i & (1 << j) > 0)
                temp = string(array[j])
                s *= temp
            end
        end
        if (length(s) > 0)
            println(s)
        end
    end
end

## Input

print("Enter the length of array: ")
n = readline()
n = parse(Int64, n)
print("Enter the elements of array: ")
array = Int64[]
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(array, temp)
end

## Calling the Function 

subsets(array, n)

#=
Sample Test Case:
Input:
    Enter the length of array: 5
    Enter the elements of array: 1 2 3 4 5
Output:
    The subsets are: 
    124
    234
    2
    1234
    134
    34
    24
    4
    123
    3
    5
    23
    13
    14
    12
    1
Time complexity: O(2^N)
Space complexity: O(1)
=#

