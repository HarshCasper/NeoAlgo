"""Julia program to implement Merge sort
Merge Sort is one of the most popular sorting algorithms that is based on the principle of Divide and Conquer Algorithm.Here, problem is divided into multiple sub-problems. Each sub-problem is solved individually. Finally, sub-problems are combined to form the final solution.
"""
function merge_sort(arr)
    if length(arr) <= 1
        return arr
    end

    middle = trunc(Int, length(arr) / 2)
    L = arr[1:middle]
    R = arr[middle+1:end]

    merge_sort(L)
    merge_sort(R)

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
    println("No numbers to sort")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
merge_sort(arr)
print("The numbers in sorted order is ")
print(arr)
