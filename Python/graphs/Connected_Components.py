"""
Connected Components:- In an undirected graph, a connected
        component is a subgraph such that there exists at least
        one path connecting any of the two nodes of that graph.
Purpose: Given an undirected graph with N nodes and M edges where
        each node is numbered between 1 and N find the total number
        of connected components in the graph.
Method: Breadth-First Search
Intuition: For every node of the graph that is not yet visited,
        1. we will call BFS() function to traverse the graph and
            marking the nodes visited.
        2. increase the count of connected components by 1
Time Complexity:  O(N+M)
Space Complexity: O(N)
Argument: Dictionary ( Graph )
Return:   Integer    ( Number of connected components )
"""
from collections import defaultdict, deque


# Breadth-First Search
def BFS(graph, node, visited):

    # Initilizing the queue with the source node and mark the node visited
    q = deque([node])
    visited[node] = 1

    while q:
        # Pop the leftmost node of the queue
        v = q.popleft()

        for each in graph[v]:

            # If the node is not visited yet, then mark it visited and push
            # into the queue
            if not visited[each]:
                visited[each] = 1
                q.append(each)

    return 1


def Connected_Components(n, graph):

    # Variable visited to keep a track of already visited nodes
    visited = [0] * (n + 1)

    # To count the number of Connected Components
    count = 0

    # Iterate through each node and check if it is visited or not
    for i in range(1, n + 1):

        # if not visited, call BFS() function and increase the count by 1
        if not visited[i]:
            BFS(graph, i, visited)
            count += 1

    # Return the answer
    return count


# ------------------------------- DRIVER CODE -----------------------------

if __name__ == "__main__":

    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")

    # Store the graph in the form of Dictionary
    graph = defaultdict(list)

    for i in range(m):
        a, b = map(int, input().split())

        # Undirected Graph
        graph[b] += [a]
        graph[a] += [b]

    ans = Connected_Components(n, graph)
    print("Number of connected components: ", ans)
        
"""
Sample Input / Output
        1-----------2         4    7
        |           |         |   /
        |           |         |  /
        |           |         | /
        |           |         |/
        3-----------5         6
Enter the number of vertex and edges: 7 6
Enter the edges:
1 2
1 3
2 5
3 5
4 6
6 7
Number of connected components:  2
Explanation: Connected components are (1, 2, 3, 5) and (4, 6, 7)
        1----------2        4        7
         \           \      /\      /
          \           \    /  \    /
           \           \  /    \  /
            \           \/      \/
             3-----------5-------6
Enter the number of vertex and edges: 7 8
Enter the edges:
1 2
1 3
2 5
3 5
4 5
5 6
6 4
6 7
Number of connected components:  1
"""
