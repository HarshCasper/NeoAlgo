"""
Julia program to find the n-th element from Stern's Diatomic Series
Stern's diatomic series is the sequence which generates the integer sequence that arises
in the Calkin-Wilf tree. This sequence can be computed by the fusc function.
"""

function stern_diatomic_num(n)
    if(n == 0)
        return 0
    end    
    
    dp = zeros(Int, n)

    dp[1] = 1
    # Traverse and Fill the `dp` array.
    for i in 2:n
        # If i is even
        if(i % 2 == 0)
            dp[i] = dp[i ÷ 2]
        # If i is odd
        else
            dp[i] = dp[(i - 1) ÷ 2 ] + dp[(i + 1) ÷ 2]
        end
    end
    return dp[n]
end

print("Enter the value of n(where you need the nth Stern's Diatomic number): ")
n = readline()
n = parse(Int, n)
if(n < 0)
    print("Invalid Value of n !!!")
    exit()
end
res = stern_diatomic_num(n)
println("The $n'th Stern's Diatomic is $res.")


"""
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the value of n(where you need the nth Stern's Diatomic number): 258
The 258'th Stern's Diatomic is 8.

SAMPLE 2
Enter the value of n(where you need the nth Stern's Diatomic number): -98
Invalid Value of n !!!
"""
