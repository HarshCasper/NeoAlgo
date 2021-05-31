You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. 
Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) 
with a radius of rj.

For each query queries[j], this program computes the number of points inside the jth circle. Points on the border of the 
circle are also considered inside.

This prgram Returns an array answer, where answer[j] is the answer to the jth query.


Sample Input 

Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: For first Query there are 3 points that are inside the circle.
For 2nd there are 2 points and for 3rd Query there are 2 points that lie inside the circle {query[3]}.





Time Complexity : O(N*Q), where N is the number of points and Q is the number of queries.
Space Complexity: O(Q), Required to store the ans array. 
