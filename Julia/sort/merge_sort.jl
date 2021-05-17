"""Julia program to implement Merge sort
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
First divide the list into the smallest unit (1 element), then compare each element with the adjacent list to sort and merge the two adjacent lists. 
Finally all the elements are sorted and merged.
"""
function merge_sort(arr)
    if length(arr) <= 1
        return arr
    end
    middle = trunc(Int, length(arr) / 2) # Finding the mid of the array
    L = arr[1:middle]
    R = arr[middle+1:end]
    
    merge_sort(L) # Sorting the first half
    merge_sort(R) # Sorting the second half
    
    # Copy data to temp arrays L[] and R[]
    i = j = k = 1
    while i <= length(L) && j <= length(R)
        if L[i] < R[j]
            arr[k] = L[i]
            i+=1
        else
            arr[k] = R[j]
            j+=1
         end
         k+=1
     end
    # Checking if any element was left
     while i <= length(L)
          arr[k] = L[i]
          i+=1
          k+=1
      end
      while j <= length(R)
          arr[k] = R[j]
          j+=1
          k+=1
      end
      arr
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
merge_sort(arr)
print("The numbers in sorted order is ")
print(arr)


"""
Time Complexity - O(n*Log n), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT
How many numbers do you want to sort? 4
Enter the numbers: 8 2 7 6 
The numbers in sorted order is [2, 6, 7, 8]
"""


