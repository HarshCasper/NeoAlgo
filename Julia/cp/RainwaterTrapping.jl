#= This is one of the famous Interview Problems. You are given 
an array of numbers, treat this array as stone heights. When the rainfalls
the water get's filled inside the stone gaps. You need to calculate the amount
of water which will get trapped inside the stones. 
The code calculates the answer in the best time complexity.
=#

## Function

function rainWater(n, array)
    left = zeros(n)
    left[1] = array[1]
    for i = 2:n
        left[i] = max(left[i-1], array[i])
    end
    right = zeros(n)
    right[n] = array[n]
    for i = n-1:-1:1
        right[i] = max(right[i+1], array[i])
    end
    total = 0
    for i = 1:n
        total += min(left[i], right[i]) - array[i]
    end
    return total
end

## Input

println("Enter the length of array!")
n = readline()
n = parse(Int64, n)
array = Int64[]
println("Enter the array !")
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(array, temp)
end

## Calling the function

rainWater(n, array)

#=
Sample Test Case:
Input:
    n = 3
    array = 2 0 2
Output:
    2

Time complexity: O ( N )
=#
