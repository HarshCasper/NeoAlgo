"""
Strongly Connected Components : A directed graph is strongly connected
        if there is a path between all pairs of vertices. A strongly
        connected component (SCC) of a directed graph is a maximal
        strongly connected subgraph.

Purpose: To find all the Strongly Connected Components (SCC) in the
        given directed graph.
Method: Tarjan's Algorithm / Depth First Search
Intution: Tarjan Algorithm is based on following facts:
        1. DFS search produces a DFS tree/forest
        2. Strongly Connected Components form subtrees of the DFS tree.
        3. If we can find the head of such subtrees, we can print/store all
            the nodes in that subtree (including head) and that will be one SCC.
        4. There is no back edge from one SCC to another (There can be cross
        edges, but cross edges will not be used while processing the graph).

Time Complexity:  O(N+M)
Space Complexity: O(N)

Argument: Dictionary ( Graph with each node is numbered from 1 to N)
Reaturn : List       ( Strongly Connected Components)

"""
from collections import defaultdict

# Global variable to keep a track of finishing time of diffrent nodes
Time = 0

# Depth First Search recuresive function


def DFS(graph, node, low, ids, visited, chk, stack, ans):
    global Time

    # Update the stack
    stack.append(node)

    # Mark the node visited and Checked
    chk[node] = 1
    visited[node] = 1

    # Initialize the id and low to the Time
    ids[node] = Time
    low[node] = Time
    Time += 1

    for i in graph[node]:

        # For each not visited node, recursievely call DFS()
        if not visited[i]:
            DFS(graph, i, low, ids, visited, chk, stack, ans)

        # If the node is already checked, Initialize the low to min value
        if chk[i]:
            low[node] = min(low[node], low[i])

    # After checking each adjacent vertex, if id == low, than the node is
    # the Head of a Strongly Connected Component

    if ids[node] == low[node]:

        # Pop the stack until we find the Head Node and mark the poped
        # Node as unchecked and store them in temp variable
        temp = []
        while 1:
            no = stack.pop()
            temp.append(no)
            chk[no] = 0
            low[no] = ids[node]
            if no == node:
                break

        # Append the poped elements as an SCC to the answer
        ans.append(temp)

    return True


def SCC_Tarjan(n, graph):

    # To keep a track of already visited and checked nodes
    visited = [0] * (n + 1)
    chk = [0] * (n + 1)

    # To mantain a stack which will help in tracing the elemnts
    # when the head is found
    stack = []

    # ids to keep the Finishing time of each vertex and
    # low to store the lowest finishing time in all its adjacent nodes
    low = [0] * (n + 1)
    ids = [0] * (n + 1)

    ans = []
    for i in range(1, n + 1):

        # For all unvisited node, we will call the DSF() function
        if not visited[i]:
            DFS(graph, i, low, ids, visited, chk, stack, ans)

    return ans


if __name__ == "__main__":

    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")

    # Store the graph in the form of Dictionary
    graph = defaultdict(list)

    for i in range(m):
        a, b = map(int, input().split())
        # Directed Graph
        graph[a] += [b]

    ans = SCC_Tarjan(n, graph)

    print("The Strongly Connected Componentes in the given Directed Graph are :")
    for i in ans:

        # Formated Output
        print("[", end="")
        print(*i, end="")
        print("]", end=" , ")

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
[4] , [3] , [2 5 1] ,


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
[7 6 5] , [2 3 4 1] ,

"""
