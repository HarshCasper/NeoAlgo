""" Julia Program to implement the Cutting a Rod problem
  
We are given a rod of length 'n' and the cost of the rod of different length from
1 to n. We need to find the maximum sell price that can be obtained by cutting the rod
at any lengths.
 
This problem can be solved by using Dynamic Programming
"""

# Build a dp Table in Botom-Up manner, such that the n'th element stores
# the maximum price obtained by a rod of length 'n'
function max_sell_price(m, cost)
    dp = zeros(Int, n + 1)
    for i in 1:n
        curr_max = -1
        for j in 0:(i - 1)
            # Maximum Price obtained by cutting a rod of length zero is zero
            if ((i - j - 1) == 0)
                curr_max = max(curr_max, cost[j + 1])
            else
                curr_max = max(curr_max, cost[j + 1] + dp[i - j - 1])
            end
        end
        #  Stores the maximum cost obtainable for a rod of length i
        dp[i] = curr_max
    end
    return dp[n]
end

print("What is the length of the rod? ")
n = readline()
n = parse(Int, n)
if (n <= 0)
    println("The given rod length is Invalid!!!")
    exit()
end
cost = Int[]
print("Enter the cost of the rod for length 1 to $n :  ")
cost = [parse(Int, num) for num in split(readline())]
max_price = max_sell_price(n, cost)
print("The maximized sell price of the: $max_price")


"""
Time Complexity- O(n^2), where 'n' is the length of the rod
Space Complexity- O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

What is the length of the rod? 5
Enter the cost of the rod for length 1 to 5: 2 5 7 8 10
The maximized sell price of the: 12 

SAMPLE 2

What is the length of the rod? -3
The given rod length is Invalid!!!

"""
