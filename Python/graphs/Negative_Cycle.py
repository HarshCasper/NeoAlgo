"""
Negative Cycle: In a Directed Graph, if the sum of the weight along the
        cycle turns out to be negative, then the graph is said to have
        a negative cycle. Detection of the negative cycle in a graph is very
        important for better implementation of pathfinding algorithms.

Purpose: Given a Directed Weighted Graph with N nodes and M edges, where
        each edge possesses an integer weight. Detect whether the given Graph
        has a negative cycle or not.

Method: Bellman-Ford Algorithm
Intuition: Below is algorithm find if there is a negative weight cycle
        reachable from the source (Consider 1).
    1) Initialize distances from the source to all vertices as infinite and
        distance to the source itself as 0. Create an array dist[] of size N with
        all values as infinite except dist[src] where src is source vertex.
    2) This step calculates the shortest distances. Do the following N-1 times where
        N is the number of vertices in the given graph.
        (*) Do following for each edge u-v
            If dist[v] > dist[u] + weight of edge uv, then update dist[v]
            dist[v] = dist[u] + weight of edge uv
    3) This step reports if there is a negative weight cycle in the graph. Do following
        for each edge u-v
        If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative
        weight cycle”

Time Complexity:  O((N^2)*M)
Space Complexity: O(N)

Argument: Dictionary ( Graph with nodes numbered 1 to N )
Return  : Boolean    ( The graph contain negative cycle or not )
"""
from collections import defaultdict


def Negative_Cycle(n, graph):

    # Initilize the distance of each node to infinite
    distance = [float('inf') for i in range(n + 1)]

    # Considering source vertex as 1, puting distance[1]=0
    distance[1] = 0

    # To keep a count of iteration
    x = 0
    while True:

        # To keep a track of any updation
        boo = False

        # Check for each node and each edge
        for i in graph.keys():
            for j in graph[i].keys():

                # Updation of the distance if the condition satisfies
                if distance[j] > distance[i] + graph[i][j]:
                    boo = True
                    distance[j] = distance[i] + graph[i][j]

        # If there is no updation, then break the loop
        if not boo:
            break
        x += 1

        # If the iteration exceeds the number of nodes, that means
        # the graph has a Negative Cycle
        if x > n:
            return True

    return False

# -------------------------------DRIVER CODE ---------------------------------


if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")

    graph = defaultdict()
    for i in range(1, n + 1):
        graph[i] = defaultdict(int)

    # Initializing the Directed Graph
    for i in range(m):
        a, b, w = map(int, input().split())
        graph[a][b] = w

    # Calculating answer by calling the Negative_Cycle() function
    isNegetive_Cycle = Negative_Cycle(n, graph)

    if isNegetive_Cycle:
        print("The Graph has a Negative Cycle")
    else:
        print("The Graph does not have a Negative Cycle")

"""
Sample Input / Output

                -4            -1           5
           (1)--------->(2)-------->(3)--------->(6)
             ^          /           /
              \        /           /
               \      /  2        /  3
              1 \    /           /
                 \  /           /
                  \V           V
                  (4)         (5)<---------(7)
                                      -2

Enter the number of vertex and edges: 7 7
Enter the edges:
1 2 -4
4 1 1
2 3 -1
2 4 2
3 6 5
3 5 3
7 5 -2
The Graph has a Negative Cycle

                    -4              -5
            (1)----------->(2)------------->(5)
             ^              |
             |              |
         -2  |              | 3
             |              |
             |              |
             |              V
            (3)<-----------(4)
                     5

Enter the number of vertex and edges: 5 5
Enter the edges:
1 2 -4
3 1 -2
2 5 -5
2 4 3
4 3 5
The Graph does not have a Negative Cycle
"""
