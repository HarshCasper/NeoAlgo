"""Julia program to implement Insertion sort
In Insertion Sort we maintain a sorted part and an unsorted part,
and continously shift elements from unsorted part to the sorted part
thus getting the whole array sorted in the process.
"""

function insertion_sort(arr, n)
    # Begin the iteration from the second element considering, the first element as a part of the sorted part 
    for i in 2:n
        temp = arr[i]
        j = i - 1
        # Find the first element from the beginning of the array that is smaller than the temp element
        # And shift all the elements till then towards right. 
        while j > 0 && temp < arr[j]
            arr[j + 1] = arr[j]
            j = j - 1
        end
        arr[j + 1] = temp
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
insertion_sort(arr, n)
print("The numbers in sorted order is ")
print(arr)



"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
How many numbers do you want to sort? 6
Enter the numbers: 76 243 89 25 8337 72
The numbers in sorted order is [25, 72, 76, 89, 243, 8337]

"""
