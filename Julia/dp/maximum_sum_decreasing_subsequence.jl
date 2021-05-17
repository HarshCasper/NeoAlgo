"""
Julia program to implement Maximum Sum Decreasing Subsequence
In this problem, given an array we have to find the maximum sum an decreasing subsequence of that array can make.
This problem is a slight modification to the Longest Decreasing subsequence problem.
The problem can be solved using Dynamic Programming
"""


function maximum_sum_decreasing_subsequence(arr, n)
    max_sum = 0
    dp = Int[]

    # Initialize the dp array with the array values, as the maximum sum 
    # at each point is atleast as the value at that point  
    for i in 1:n
        push!(dp, arr[i])
    end

    for i in 1:n
        for j in 1:(i-1)
            if(arr[i] < arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i]
            end
        end
    end

    # Now Find the maximum element in the dp array 
    max_sum = findmax(dp)[1]
    return max_sum

end


print("What is the length of the array? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("No numbers present in the array!!!")
    exit()
end
arr = Int[]
print("Enter the numbers: ")
arr = [parse(Int, num) for num in split(readline())]
res = maximum_sum_decreasing_subsequence(arr, n)
print("The maximum sum of an  decreasing subsequence of the given array is $res")


"""
Time Complexity: O(num ^ 2), where 'num' is the size of the given array
Space Complexity: O(num)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

What is the length of the array? 10
Enter the numbers: 23 14 5 84 24 222 321 43 123 432
The maximum sum of an  decreasing subsequence of the given array is 444

SAMPLE 2

What is the length of the array? 5
Enter the numbers: 5 4 3 2 1
The maximum sum of an  decreasing subsequence of the given array is 15
"""
