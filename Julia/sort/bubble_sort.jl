"""Julia program to implement Bubble Sort
In Bubble Sort we compare the adjacent elements and swap them such that the greater
element among them comes in the right-side. After each iteration, one smallest element
goes towars the end of the array.
"""

function bubble_sort(arr, n)
    # Iterate the entire array
    for i in 1:n
        # Iterate till the concerned part only.
        for j in 1:(n-i)
            # Swap adjacent elements if they are in wrong order
            if(arr[j] > arr[j+1])
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
    end
end
            

print("How many numbers do you want to sort? ")
n = readline()
n = parse(Int64, n)
if (n <= 0)
    println("No numbers to sort!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
bubble_sort(arr, n)
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
