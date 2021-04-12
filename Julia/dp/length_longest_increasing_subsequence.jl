""" Julia program to find the Length of Longest Increasing Subsequence

In this problem, given an array we have to find the length of the longest increasing subsequence that array can make.
The problem can be solved using Dynamic Programming
"""

function length_longest_increasing_subsequence(arr, n)
    max_len = 0
    # Initialize the dp array with the 1 as value, as the maximum length
    # at each point is atleast 1, by including that value in the sequence
    dp = ones(Int, n)

    """ Now Lets Fill the dp array in Bottom-Up manner
    Compare Each i'th element to its previous elements from 0 to i-1, 
    If arr[i] > arr[j](where j = 0 to i-1), then it qualifies for increasing subsequence and
    If dp[i] < dp[j] + 1, then that subsequence  qualifies for being the longest one"""
    for i in 1:n
        for j in 1:(i-1)
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1
            end
        end
    end

    # Now Find the largest element in the dp array 
    max_len = findmax(dp)[1]
    return max_len
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
res = length_longest_increasing_subsequence(arr, n)
print("The length of the longest increasing subsequence of the given array is $res")


"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
What is the length of the array? 5 
Enter the numbers: 5 4 3 2 1
The length of the longest increasing subsequence of the given array is 1

"""
