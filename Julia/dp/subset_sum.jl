"""Julia program to implement Subset Sum problem.
Given a set, we have to find if there exist a subset with the given sum.
The given problem can be solved using Dynamic Programming.
"""

function subset_sum(set, n, S)

    # Initialize the entire 2D matrix with 0 as value, signifying false.
    dp = zeros(Int, n + 1, S + 1)

    # When the sum is zero, the answer is always true, by forming an empty subset.
    for i in 1:n + 1
        dp[i,1] = 1
    end

    # When the given set is empty and the required sum is not zero, then such a subset cannot e formed.
    for i in 1:S + 1
        dp[1,i] = 0
    end

    """Tabulating the dp array in Bottom-Up manner. In such a way that each cell of the dp[i, j]
       array contains whether a subset of sum j can be formed with elements in the given set till i"""
    for i in 2:n + 1
        for j in 2:S + 1
            if j < (set[i - 1] + 1)
                dp[i,j] = dp[(i - 1),j]
            else
                if (dp[(i - 1),j] == 1)
                    dp[i, j] = 1
                elseif (dp[(i - 1),(j - set[i - 1])] == 1)
                    dp[i, j] = 1
                else
                    dp[i, j] = 0
                end
            end
        end
    end
    return dp[n + 1,S + 1]
end


print("What is the size of the set? ")
n = readline()
n = parse(Int, n)
arr = Int[]
if (n > 0)
    print("Enter the numbers: ")
    arr = [parse(Int, num) for num in split(readline())]
else
    print("The set is Empty!!!")
    exit()
end
print("Enter the sum? ")
S = readline()
S = parse(Int, S)
res = subset_sum(arr, n, S)
if (res == 1)
    print("A subset with the given sum is present in the array.")
else
    print("A subset with the given sum is not present in the array.")
end


"""
Time Complexity - O(n * S), where 'n' is the size of the array and 'S is the Sum
Space Complexity - O(n * S)

SAMPLE INPUT AND OUTPUT

SAMPLE I

What is the size of the set? 3
Enter the numbers: 3 2 1
Enter the sum? 55
A subset with the given sum is not present in the array.

SAMPLE II

What is the size of the set? 4
Enter the numbers: 10 20 30 40
Enter the sum? 60
A subset with the given sum is present in the array.
"""
