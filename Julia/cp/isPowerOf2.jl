#= Given a number N check if it is a power of 2 in O(1). We will be 
using bitwise operator to get the calculation.=#

## Function

function isPowerOfTwo(n)
    return (n & (n - 1) == 0)
end

## Input

println("Enter the number : ")
n = readline()
n = parse(Int64, n)

## Calling the function

if (isPowerOfTwo(n))
    println("Its a power of 2")
else
    println("Its not a power of 2")
end

#=
Sample Test Case
Input: 
    Enter a number : 4294967296
Output:
    Its a power of 2
Time complexity: O( 1 ) 
=#
