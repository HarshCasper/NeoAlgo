'''
Articulation Point:- In an undirected graph, any vertex whose removal
        from the graph separates/divides the graph into 2 or more graph
        which are not connected by any edge is called a cut-vertex
        or Articulation Point.

Purpose:- To return a list of all Articulation point in the given
            graph if such a point exists.
Problem Link:- https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph

Method - Depth First Search
Intuition:- The idea behind the solution is to use DFS because it forms a DFS tree.
        In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
        1) u is the root of DFS tree and it has at least two children.
        2) u is not the root of DFS tree and it has a child v such that
            no vertex in the subtree rooted with v has a back edge to one
            of the ancestors (in DFS tree) of u.

Time Complexity:-  O(N+M)
Space Complexity:  O(N)

Argument: Dictionary ( Graph vertex numbered 1 to N)
Return  : List       ( Articulation Point)

'''
from collections import defaultdict

# Global Variable to keep a track of finishing times
Time = 0


def dfs(graph, node, parent, low, f_time, visited, AP):
    global Time

    # Mark the node visited and Initialize the finishing time
    visited[node] = True
    low[node] = Time
    f_time[node] = Time
    Time += 1

    # To count the children from the current Node
    child = 0

    # Check for each adjoining Vertex/Node
    for i in graph[node]:

        if visited[i]:
            low[node] = min(low[node], f_time[i])

        if not visited[i]:
            parent[i] = node
            child += 1
            dfs(graph, i, parent, low, f_time, visited, AP)
            low[node] = min(low[node], low[i])

            # (1) u is the root of the DFS tree and has two or more children.
            if parent[node] == -1 and child > 1:
                AP[node] = 1

            # (2) If u is not root and low value of one of its child is more
            # than discovery value of u.
            if f_time[node] <= low[i] and parent[node] != -1:
                AP[node] = 1


def Articulation_Point(n, graph):

    # Initialize parent finishing time and Low
    parent = [-1] * (n + 1)
    low = [float('inf') for i in range(n + 1)]
    f_time = [float('inf') for i in range(n + 1)]

    # To keep a check on already visited nodes
    visited = [0] * (n + 1)

    # To store the Articulation point
    AP = [0] * (n + 1)

    # Call the DFS function to recursively check for each of the vertex
    for i in graph.keys():
        if(not visited[i]):
            dfs(graph, i, parent, low, f_time, visited, AP)

    # Collect all the Articulation point in a list
    ans = []
    for i in range(n + 1):
        if AP[i]:
            ans += [i]

    # Return all the Articulation Point
    return ans


# -------------------------------Driver Code-------------------------------

if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")
    graph = defaultdict(list)

    for i in range(m):
        a, b = map(int, input().split())
        graph[a] += [b]
        graph[b] += [a]
    ans = Articulation_Point(n, graph)

    # Print the Answer
    if not ans:
        print("There is No Articulation Point in the Graph")
    else:
        print("The Articulation point in the given graph are : ", *ans)

"""
Sample Input / Output

     5----1------2
     \     \
      \     \
       \     \
 3------6-----4

Enter the number of vertex and edges: 6 6
Enter the edges:
5 1
3 6
6 4
1 2
5 6
1 4
The Articulation point in the given graph are :  1 6

     5----1------2
    /\     \    /
   /  \     \  /
  /    \     \/
 3------6-----4

Enter the number of vertex and edges: 6 8
Enter the edges:
5 1
1 2
1 4
5 6
6 4
4 2
3 6
5 3
There is No Articulation Point in the Graph
"""
