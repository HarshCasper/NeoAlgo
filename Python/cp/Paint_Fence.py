"""
___Paint Fence Algorithm___

Problem:
Given a fence with n posts and k colors
Find out the number of ways of painting the fence
such that at most 2 adjacent posts have the same color.

Input:
n : number of posts
k : number of colors

Output:
result: number of ways of painting
        considering the condition above

"""


def paint_fence(n, k):
    if n < 2 or k < (n/2) :
        return -1       # n is not enough or k is not enough to obey the condition
    total = [0]*(n-1)
    same = [0]*(n-1)
    diff = [0]*(n-1)

    same[0] = k           # We start from the case 2  (0 as i) till n (n-2 as i)
    diff[0] = k*(k-1)
    total[0] = k*k
    for i in range(1, n-1):
        same[i] = diff[i-1]
        diff[i] = total[i-1]*(k-1)
        total[i] = same[i]+diff[i]
    return total[n-2]


if __name__ == "__main__":
    post = int(input("Enter n, Number of Posts\n"))
    color = int(input("Enter k, Number of Colors\n"))
    result = paint_fence(post, color)
    if result == -1 :
        print("Painting is not possible following the condition")
    else:
        print("Number of Possiblities:", result)

# Sample Input/Output

# Enter n,Number of Posts
# 3
# Enter k,Number of Colors
# 5
# Number of Possiblities: 120

# Enter n,Number of Posts
# 10
# Enter k,Number of Colors
# 4
# Painting is not possible following the condition

# Enter n,Number of Posts
# 5
# Enter k,Number of Colors
# 3
# Number of Possiblities: 180

# Time Complexity  O(n)
# Space Complexity O(n)

