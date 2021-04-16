"""Julia program to implement Painting Fence algorithm
Given a fence with n posts and k colors
Find out the number of ways of painting the fence
such that at most 2 adjacent posts have the same color.

"""

function painting_fence(n, k)
    if (k < (n ÷ 2) || n < 2)
        return -1
    end
    tot = [0 for i in 1:(n - 1)]
    same = [0 for i in 1:(n - 1)]
    diff = [0 for i in 1:(n - 1)]

    same[1] = k
    diff[1] = k * (k - 1)
    tot[1] = k * k
    for i in 2:(n-1)
        same[i] = diff[i-1]
        diff[i] = tot[i-1] * (k-1)
        tot[i] = same[i] + diff[i]
    end 
    return tot[n-1]
end

print("Enter the number of posts: ")
n = readline()
n = parse(Int, n)
print("Enter the number of colours available: ")
k = readline()
k = parse(Int, k)
ans = painting_fence(n, k)
if( ans == -1)
    println("The given posts cannot be painted with the given colours satisfying the given conditions")
else
    println("The number of ways to paint the given posts is $ans")
end


"""
Time Complexity: O(n), where 'n' is the number of posts
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number of posts: 10
Enter the number of colours available: 4
The given posts cannot be painted with the given colours satisfying the given conditions

SAMPLE 2

Enter the number of posts: 3
Enter the number of colours available: 5
The number of ways to paint the given posts is 120
"""
