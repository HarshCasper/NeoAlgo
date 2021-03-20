#=Given an Array you need to find the maximum sum of all the 
subarrays. Subarrays are consecutive elements of the array.
There are a total of n*(n+1)/2 subarrays in an array with 
n elements. Out of all these sub arrays find the subarray with
the maximum sum. Kadane's Algorithm helps us to do this in 
the least time complexity.=#

## Function

function maxSubArray(array)
    best = 0
    sum = 0
    for i in array
        sum = max(i, sum + i)
        best = max(sum, best)
    end
    return best
end

## Input

n = readline()
n = parse(Int64, n)
arr = Int64[]
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(arr, temp)
end

## Calling the function

print(maxSubArray(arr))

#=
Sample test case:
Input:
    n = 5
    array = 2 -3 5 4 -7
Output:
    9

Time complexity: O(N)
=#
