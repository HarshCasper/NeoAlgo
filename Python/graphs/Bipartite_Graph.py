"""
Bipartite Graph: A Bipartite Graph is a graph whose vertices can be
        divided into two independent sets, U and V such that every
        edge (u, v) either connects a vertex from U to V or a vertex
        from V to U. A bipartite graph is possible if the graph
        coloring is possible using two colors such that vertices
        in a set are colored with the same color.

Purpose: To check whether the given undirected graph is Bipartite
        Graph or not.

Method: Breadth First Search (BFS)
Intution: Following is a simple algorithm to find out whether a given graph
        is Birpartite or not using Breadth First Search (BFS).

        1. Assign RED color to the source vertex (putting into set U).
        2. Color all the neighbors with BLUE color (putting into set V).
        3. Color all neighbor’s neighbor with RED color (putting into set U).
        4. This way, assign color to all vertices such that it satisfies all
            the constraints of m way coloring problem where m = 2.
        5. While assigning colors, if we find a neighbor which is colored with
            same color as current vertex, then the graph cannot be colored with
            2 vertices (or graph is not Bipartite)

Time Complexity:  O(N+M)
Space Complexity: O(N)

Argument: Dictionary ( Graph where each vertex is numbered from 1 to N )
Reaturn : Boolean    ( The Graph is Bipartite or not )

"""
from collections import defaultdict, deque


def BFS(graph, node, color):

    # Initilize the color of the source node to be 1
    color[node] = 1

    # Initilise the queue with the source node
    queue = deque([node])

    while queue:
        v = queue.popleft()

        # Base Case: Self looped Graph is not Bipartite
        if v in graph[v]:
            return False

        # Check for each adjacent node
        for each in graph[v]:

            # If not colored, Mark its color to be XOR of its preceding node
            if color[each] == -1:
                color[each] = color[v] ^ 1
                queue.append(each)

            # If already colored, Check whether its color is same as preceding node
            # If yes then return False
            if color[each] == color[v]:
                return False

    # If all the nodes in the graph are colored, return True
    return True


def Bipartite_Graph(n, graph):

    # To assign color to each vertex either 0 or 1
    color = [-1] * (n + 1)

    # A boolean to store answer
    answer = True

    for i in range(1, n + 1):

        # For each uncolored node, we have to call BFS() function
        if color[i] == -1:

            # Answer will be the (and) of the previous and the boolean value returned
            # by the BFS() function
            answer = answer and BFS(graph, i, color)

    return answer

# -----------------------------------Driver Code--------------------------


if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")
    graph = defaultdict(list)

    for i in range(m):
        a, b = map(int, input().split())
        graph[a] += [b]
        graph[b] += [a]
    ans = Bipartite_Graph(n, graph)

    # Print the Answer
    if ans:
        print("The graph is Bipartite")

    else:
        print("The graph is not Bipartite")

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
The graph is Bipartite


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
