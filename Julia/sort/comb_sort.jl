"""Julia program to implement Comb Sort
Comb sort is an improvised Bubble sort. Bubble sort removes its inversions one by one whereas In Comb sort,
more than one inversion is removed by one swap and hence it is more efficient than Bubble sort.
"""

function comb_sort(arr, n)
    flag = 1
    space = n
    while (space > 1 || flag == 1)
        # Here empirically found shrink factor 1.3 is used.
        space = (space * 10) ÷ 13

        # Assigning space its minimum value of 1
        if (space < 1)
            space = 1
        end
        flag = 0

        # Compare elements with the space value
        for i in 1:(n - space)
            if (arr[i] > arr[i + space])
                arr[i], arr[i + space] = arr[i + space], arr[i]
                flag = 1
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
comb_sort(arr, n)
print("The numbers in sorted order is ")
print(arr)


"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
How many numbers do you want to sort? 6
Enter the numbers: 123 13 42 324 153 43 
The numbers in sorted order is [13, 42, 43, 123, 153, 324]
"""
