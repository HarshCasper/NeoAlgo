"""
Problem statement : 
There is a fence with n posts, you are given k colors to paint the fence. 
Each post can be painted with one of the k colors. You have to paint all the posts 
with the k colors such that atmost two adjacent posts have the same color. 
You have to find the total number of ways to paint the fence.

Explanation : 
Suppose we have a single post, The number of ways of painting the fence with k 
colors is k Now we consider 2 posts, Then the number of ways of painting the 
second fence with the same color as the first post is k, and the number of ways 
of painting the second post with a different color is k*(k-1) as we have k-1 colors 
that are different from the first post's color. So the total number of ways of 
painting 2 fences is k*(k-1) + k. Now we consider 3 posts, Then the number of ways 
of painting the third fence same as the second fence is the number of ways of painting 
the second fence with a different color that is k*(k-1). The number of ways of painting 
the third fence using a different color is equal to the total number of ways of painting 
the second fence times (k-1). Hence the total number of ways of painting 3 fences is 
k*(k-1) + (k+k*(k-1))*(k-1). This way we can find the total number of ways of painting 
n fences
"""
def paintfence(n,k):
    same = k
    diff = k*(k-1)
    total = k*k
    for i in range(n-2):
        same = diff
        diff = total*(k-1)
        total = same + diff
    return total


if __name__ == "__main__":
    n = int(input("Enter n, Number of Posts\n"))
    k = int(input("Enter k, Number of Colors\n"))
    res = paintfence(n,k)
    if(res == -1):
        print("Painting the Fence id not possible")
    else:
        print("Number of possiblilities for painting the fence is : "+str(res))

"""
Sample I/O :

Enter n, Number of Posts
3
Enter k, Number of Colors
2
Number of possiblilities for painting the fence is : 6

Time complexity : O(n)
Space complexity : O(n) , where n is the number of posts
"""
