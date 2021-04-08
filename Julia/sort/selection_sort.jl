# Julia program to implement Selection sort

function selection_sort(arr, n)
    for i in 1:n
        # Let the first element in this iteration be the minimum value
        min = i
        # Find the least element in the concerned part of the array
        for j in (i + 1):n
            if arr[min] > arr[j]
                min = j
            end
        end
        # Swap the least element with the beginning of the concerned part of the array
        arr[i], arr[min] = arr[min], arr[i]
    end
end



print("How many numbers do you want to sort? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("No numbers to sort!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
selection_sort(arr, n)
print("The numbers in sorted order is ")
print(arr)



"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
How many numbers do you want to sort? 5
Enter the numbers: 4 2 5 1 3
The numbers in sorted order is [1, 2, 3, 4, 5]

"""
