"""
Topological Sorting:- a topological sort or topological ordering of a
        directed graph is a linear ordering of its vertices such that
        for every directed edge uv from vertex u to vertex v, u comes
        before v in the ordering. Topological Sorting is not possible
        in a cyclic graph.

Purpose: To return the topological ordreing of the of the vertices of
        the provided Directed Acyclic Graph (DAG). The nodes of the
        graph are numbered from 1 to N.

Method: Depth First Search
Intution: Using DFS we can recursively traverse the adjacent vertices
        to find the sink vertex and then storing them in the Topological
        sort array/list.

Time Complexity:  O(N+M)
Space Complexity: O(N)

Argument: Dictionary  ( Graph )
Return  : List        ( Topological Sort )

"""
from collections import defaultdict


def DFS(graph, node, visited, topo):

    # Mark the node Visited
    visited[node] = 1

    # Recursively call all its adjacent nodes
    for each in graph[node]:

        # Check wether it is visited or not
        if not visited[each]:
            DFS(graph, each, visited, topo)

    # After visiting all adjacent node, append the node to the topological list
    topo += [node]


def Topological_Sort(n, graph):

    # Initialize the topo list to store the topological ordering
    # And keep atrack to visited graph
    topo = []
    visited = [0] * (n + 1)

    # Now recursively call for each unvisited Node
    for i in range(1, n + 1):
        if not visited[i]:
            DFS(graph, i, visited, topo)

    return topo[::-1]

# -------------------------------DRIVER CODE ---------------------------------


if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")
    graph = defaultdict(list)

    # Initializing the Directed Graph
    for i in range(m):
        a, b = map(int, input().split())
        graph[a] += [b]

    # Calculating answer by calling the Topological_Sort() function
    ans = Topological_Sort(n, graph)
    print("Topological Ordering of the graph is : ", *ans)

"""
Sample Input / Output

    2------>1---->3
    |             |
    |             |
    |             |
    v             v
    5----->4<-----6

Enter the number of vertex and edges: 6 6
Enter the edges:
2 1
1 3
3 6
6 4
5 4
2 5

Topological Ordering of the graph is :  2 5 1 3 6 4



        4----->5---->2---->3----->6------->1

Enter the number of vertex and edges: 6 5
Enter the edges:
4 5
2 3
6 1
5 2
3 6
Topological Ordering of the graph is :  4 5 2 3 6 1
"""
