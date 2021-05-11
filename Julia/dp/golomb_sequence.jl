"""Julia program to print the n'th term in the Golomb sequence 
Golomb sequence is a non-decreasing integer sequence where n'th 
term is  equal to the number of times n appears in the sequence"""

function golomb_sequence(n)
    dp = zeros(Int, n + 1)
    dp[1] = 1

    for i in 2:n
        dp[i] = 1 + dp[i - dp[dp[i - 1]]]
    end
    return dp[n]
end

print("Enter the value of n?, where you need the n'th number in the golomb sequence. ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("The given value of n is invalid.")
    exit()
end
res = golomb_sequence(n)
println("The $n'th term in the golomb sequence is $res.")

"""
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the value of n?, where you need the n'th number in the golomb sequence. 5
The 5'th term in the golomb sequence is 3.

SAMPLE 2
Enter the value of n?, where you need the n'th number in the golomb sequence. 867
The 867'th term in the golomb sequence is 79.

"""
