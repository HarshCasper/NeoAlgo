#= Finding the Nth number in the Fibonacci Sequence using Dynamic Programming
=#

## Function 

function fibonacci(n)
    f = Int64[]
    push!(f, 0)
    push!(f, 1)
    for i = 3:n
        temp = f[i-1] + f[i-2]
        push!(f, temp)
    end
    return f[n]
end

## Input 

print("Enter the number: ")
n = readline()
n = parse(Int64, n)
println("The $(n)th fibonacci number is ")

## Calling the function 

fibonacci(n)

#=
Sample Test Case:
Input: 
    Enter the number: 5
Output:
    The 5th fibonacci number is 3

Time Complexity: O ( N )
=#
