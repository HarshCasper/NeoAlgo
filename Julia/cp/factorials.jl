#=Given a number N, find its factorial using recursion. It is quite easy
but we want to add recursion algorithms in Julia.=#

## Function 

function fact(n)
    if (n == 0)
        return 1
    end
    if (n == 1)
        return 1
    end
    return n * fact(n - 1)
end

## Input

n = readline()
n = parse(Int64, n)

## Calling the Function

fact(n)

#=
Sample Test Case:
Input:
    n=10
Output:
    3628800
Time complexity: O( N )
=#
