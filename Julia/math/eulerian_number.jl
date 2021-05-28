"""
Julia program to implement Eulerian Number
Eulerian number is a number found in combinatorial mathematics. It is the number of permutations of the 
numbers 1 to n in which exactly m elements are greater than previous element.
"""


function eulerian(n, m)
    # Build a Dynamic Programming table
    dp = zeros(Int, n + 1, m + 1)

    # Fill the table in Bottom-Up manner
    for i in 2:(n+1)
        for j in 1:(m+1)
            #Update the table only if i greater than j
            if(i > j)
                if(j == 1)
                    dp[i, j] = 1
                else
                    dp[i, j] = (((i - j) * dp[i-1, j-1]) + ((j) * dp[i-1, j]))
                end
            end
        end
    end
    return dp[n + 1,m + 1]
end


print("Enter the value of n? ")
n = readline()
n = parse(Int64, n)
print("Enter the value of m? ")
m = readline()
m = parse(Int64, m)
ans = eulerian(n, m)
print("The required eulerian number is ")
print(ans)


"""
Time Complexity - O(n * m)
Space Complexity - O(n * m)

SAMPLE INPUT AND OUTPUT

SAMPLE I
Enter the value of n? 3
Enter the value of m? 1
The required eulerian number is 4

SAMPLE II
Enter the value of n? 15
Enter the value of m? 6
The required eulerian number is 311387598411
"""
