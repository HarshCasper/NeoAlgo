"""Julia program to find the n'th number in the tribonacci series
Tribonacci series is a generalization of the Fibonacci sequence, in which the current term
is the sum of the previous three 
"""

function find_tribonacci(n)
    dp = zeros(Int, n + 1)
    dp[1] = 0
    dp[2] = 0
    dp[3] = 1

    for i in 4:n
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    end

    return dp[n]
end


print("Enter the value of n?, where you need the n'th number in the tribonacci sequence. ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("The given value of n is invalid.")
    exit()
end
res = find_tribonacci(n)
println("The $n'th term in the tribonacci series is $res.")


"""
Time Complexity - O(n)
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
Enter the value of n?, where you need the n'th number in the tribonacci sequence. 12
The 12'th term in the tribonacci series is 149.

SAMPLE II
Enter the value of n?, where you need the n'th number in the tribonacci sequence. 1254
The 1254'th term in the tribonacci series is 4020147461713125140.
"""
