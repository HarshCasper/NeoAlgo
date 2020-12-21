"""
Strongly Connected Components : A directed graph is strongly connected
        if there is a path between all pairs of vertices. A strongly
        connected component (SCC) of a directed graph is a maximal
        strongly connected subgraph.

Purpose: To find all the Strongly Connected Components (SCC) in the
        given directed graph.

Method: Kosaraju's Algorithms / Double DFS
Intution: We can find all strongly connected components in O(N+M) time
        using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.

        1) Create an empty stack ‘S’ and do DFS traversal of a graph.
            In DFS traversal, after calling recursive DFS for adjacent
            vertices of a vertex, push the vertex to stack.
        2) Reverse directions of all arcs to obtain the transpose graph.
        3) One by one pop a vertex from S while S is not empty. Let the
        popped vertex be ‘v’. Take v as source and do DFS (call DFSU(node)).
        The DFS starting from v prints strongly connected component of v.

Time Complexity:  O(N+M)
Space Complexity: O(N)

Argument: Dictionary ( Graph with each node numbered from 1 to N)
Return  : List       ( List of diffrent Strongly Connected Components)

"""
from collections import defaultdict


def DFS(graph, node, visited, stack, display):

    # Mark the node Visited
    visited[node] = True

    for i in graph[node]:

        # Recursively call all DFS() function to all its unvisited adjacent
        # nodes
        if not visited[i]:
            DFS(graph, i, visited, stack, display)

    # If the display is True, then Display the SCC
    if display:
        print(node, end=" ")
    else:
        stack.append(node)

# Reverse_Graph() function reverse all the directed edges of the graph


def Reverse_Graph(graph):

    rev_graph = defaultdict(list)
    for i in graph.keys():
        for j in graph[i]:
            rev_graph[j].append(i)

    # Return the reversed graph
    return rev_graph


def SCC_Kosaraju(n, graph):

    # Initilize the Stack
    stack = []

    # To keep a track of all the visited nodes
    visited = [False] * (n + 1)

    for i in range(1, n + 1):

        # (1) Recursively call DFS() to push the unvisited nodes into the stack
        if not visited[i]:
            DFS(graph, i, visited, stack, False)

    # (2) Reverse the Graph
    rev_graph = Reverse_Graph(graph)

    # Mark all the nodes Unvisited
    visited = [False] * (n + 1)

    while stack:
        node = stack.pop()

        # (3) For each unvisited node in the stack, call DFS()
        if not visited[node]:

            # Print the SCC in formated way
            print("[ ", end="")
            DFS(rev_graph, node, visited, stack, True)
            print("]")


if __name__ == "__main__":

    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")

    # Store the graph in the form of Dictionary
    graph = defaultdict(list)

    for i in range(m):
        a, b = map(int, input().split())
        # Directed Graph
        graph[a] += [b]

    print("The Strongly Connected Componentes in the given Directed Graph :")
    SCC_Kosaraju(n, graph)

"""

Sample Input / Output

        1--------->5        4
         ^        / \       ^
          \      /   \     /
           \    /     \   /
            \  /       \ /
             \V         3
              2

Enter the number of vertex and edges: 5 5
Enter the edges:
1 5
5 2
2 1
5 3
3 4
The Strongly Connected Componentes in the given Directed Graph are :
[ 5 2 1 ]
[ 3 ]
[ 4 ]


        1-------->4----------->5
        ^         |           /^
        |         |          /  \
        |         |         /    \
        |         |        V      \
        |         V        6------>7
        2<--------3

Enter the number of vertex and edges: 7 8
Enter the edges:
1 4
2 1
3 2
4 3
4 5
5 6
6 7
7 5
The Strongly Connected Componentes in the given Directed Graph are :
[ 4 3 2 1 ]
[ 6 7 5 ]

"""
