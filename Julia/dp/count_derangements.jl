"""
Julia program to find the number of derangements of a set of n elements.
A Derangement is a permutation of n elements, such that no element appears in its original position.
Here, given a number n, find total number of derangements of a set of n elements
"""

function count_derangements(n)
    
    # Build the dp table in Bottom Up manner
    dp = zeros(Int, n + 1)
    # Assign base cases
    dp[2] = 0
    dp[3] = 1
    for i in 4:n+1
        dp[i] = (i-2) * (dp[i-1] + dp[i-2])
    end
    return dp[n+1]
end


print("Enter a number: ")
n = readline()
n = parse(Int, n)
res = count_derangements(n)
print("The number of derangements in a set of $n numbers is $res.")



"""
Time Complexity - O(n)
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
Enter a number: 4
The number of derangements in a set of 4 numbers is 9.

SAMPLE II
Enter a number: 16
The number of derangements in a set of 16 numbers is 7697064251745.
"""
