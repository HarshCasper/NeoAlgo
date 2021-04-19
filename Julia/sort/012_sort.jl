#=Sorting an array of 0,1,2 without comparing elements with each other or using any classic sorting 
algorithm=#

## Function

function sort(arr, n)
    low = 1
    high = n
    mid = 1
    while (mid <= high)
        if (arr[mid] == 0)
            temp = arr[mid]
            arr[mid] = arr[low]
            arr[low] = temp
            mid += 1
            low += 1
        elseif (arr[mid] == 1)
            mid += 1
        else
            temp = arr[mid]
            arr[mid] = arr[high]
            arr[high] = temp
            high -= 1
        end
    end
    return array
end       

## Input 

print("Enter the number of elements in the array ")
n = readline()
n = parse(Int64, n)
arr = Int64[]
print("\n Enter the elements of the array \n")
for i = 1:n
    temp = readline()
    temp = parse(Int64, temp)
    push!(arr, temp)
end

println("The sorted array is ")

## Calling the function

sort(arr,n)

#=
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number of elements in the array 5
Enter the elements of the array 
0 1 2 2 0
The sorted array is 
0 0 1 2 2
=#
