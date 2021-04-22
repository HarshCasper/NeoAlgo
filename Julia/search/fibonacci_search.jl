"""Julia program to implement Fibonacci Search algorithm.
Fibonacci Search is a Divide and Conquer strategy based algorithm that works for sorted arrays
Fibonacci Search avoids CPU costly division operation and uses addition and subtraction opertations
This algorithm uses Fibonacci series as an underlying principle, where every element of the series is defined by:

    fib(n) = fib(n-1) + fib(n-2), where fib(0) = 0, fib(1) = 1
"""

function fibonacci_search(arr, n, ele)

    # We start the series from 1, 1 as the Julia language is 1-based indexing
    fibn2 = 1
    fibn1 = 1
    fibn = fibn1 + fibn2
    while (fibn < n)
        fibn2 = fibn1
        fibn1 = fibn
        fibn = fibn1 + fibn2
    end

    # To denote the eliminted range from left.
    offset = 0

    while (fibn > 1)
        i = min(offset + fibn2, n - 1)
        
        """Compares the element in i'th index with ele and decide the next fibonacci element. If the element doesn't
            turns out to be greater than or less than the element at i'th index then we find the required element"""
        if (arr[i] < ele) 
            fibn = fibn1;
            fibn1 = fibn2;
            fibn2 = fibn - fibn1;
            offset = i;
        elseif (arr[i] > ele) 
            fibn = fibn2;
            fibn1 = fibn1 - fibn2;
            fibn2 = fibn - fibn1;
        else
            return true
        end
        if (arr[offset + 1] == ele)
            return true
        end
    end
    return false
end


print("How many numbers are present in the array? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("Array is Empty!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())] 
print("Which number do you want to search in the array? ")
ele = readline()
ele = parse(Int, ele)
# Sort the array in ascending order
arr = sort(arr)
res = fibonacci_search(arr, n, ele)
if (res == 0)
    print("The number $ele is not present in the array")
else
    print("The number $ele is present in the array.")
end


"""
Time Complexity - O(log(n)), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers are present in the array? 5 
Enter the numbers: 1 2 3 4 5
Which number do you want to search in the array? 6
The number 6 is not present in the array

SAMPLE II

How many numbers are present in the array? 3
Enter the numbers: 3 1 2
Which number do you want to search in the array? 2
The number 2 is present in the array.

"""
