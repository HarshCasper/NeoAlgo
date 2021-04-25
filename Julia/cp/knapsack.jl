#= You are a thief who has a bag with some capacity, you broke into a hous
and you found some valuables, you want to take the maximum value back 
with you. You are confused what to pick, no worries, coders are here 
to help you in your burglary. =#

## Function

function knapsack(weights, values, items, capacity)
    if (items == 0 || capacity == 0)
        return 0
    end
    if (weights[items] > capacity)
        return knapsack(weights, values, items - 1, capacity)
    end
    return max(
        knapsack(weights, values, items - 1, capacity - weights[items]) + values[items],
        knapsack(weights, values, items - 1, capacity),
    )
end

## Input

println("Enter the number of items")
n = readline()
n = parse(Int64, n)
println("Enter the capacity of the knapsack")
w = readline()
w = parse(Int64, w)
values = Int64[]
println("Enter the values of each item")
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(values, temp)
end
weights = Int64[]
println("Enter the weights of each item")
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(weights, temp)
end

## Calling the function

print("The maximum value you could take is ")
print(knapsack(weights, values, n, w))

#=
Sample Test Case:
Input:
    Enter the number of items
    3
    Enter the capacity of the knapsack
    50
    Enter the values of each item
    60 100 120
    Enter the weights of each item
    10 20 30
Ouput:
    The maximum value you could take is 220
=#
