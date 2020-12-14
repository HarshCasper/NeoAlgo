"""
Hamiltonian Path: a Hamiltonian path (or traceable path) is a path
    in an undirected or directed graph that visits each vertex exactly
    once.

Problem Link: https://en.wikipedia.org/wiki/Hamiltonian_path
Purpose: To determine the existance of a Hamiltonian Path in the provided
        undirected graph and return the path if such path exist.
        The nodes are numbered from 1 to N
Method : Depth First Search

Time Complexity:  O(N^2)
Space Complexity: O(N)

Argument : Graph (Dictionary)
Return   : Hamiltonian Path (List)

"""
from collections import defaultdict


def DFS(n, graph, pos, ans):
    # Base Case: If all the node is visited, Hamiltonian Path is achieved
    if pos == n:
        return ans

    current = ans[-1]

    # Check for each of the adjoining vertices
    for i in graph[current]:

        # Check wether the node is already visited or not
        if i not in ans:
            ans += [i]
            temp = DFS(n, graph, pos + 1, ans)
            if temp:
                return temp

            ans.pop()

    return False


def Hamiltonial_Path(n, graph):
    # To keep a track of already visited node and the answer
    # We will start exploring the graph from Vertex 1
    answer = [1]

    # Start Exploring from eac node/vertex
    for i in range(1, n + 1):
        
        ans = DFS(n, graph, 1, [i])
        if ans:
            return ans

    return False


# ------------------------DRIVER CODE ------------------------
if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")
    graph = defaultdict(list)
    for i in range(m):
        a, b = map(int, input().split())
        graph[a] += [b]
        graph[b] += [a]
    ans = Hamiltonial_Path(n, graph)
    if not ans:
        print("Hamiltonian Path is not possible in the Given graph")
    else:
        print("Hamiltonian Path is possible in the graph")
        print("The path is : ", *ans)

"""
Sample Input / Output

     5----1------2
     \     \    /
      \     \  /
       \     \/
 3------6-----4

Enter the number of vertex and edges: 6 7
Enter the edges
5 1
1 2
1 4
5 6
6 4
4 2
3 6
Hamiltonian Path is possible in the graph
The path is :  2 4 1 5 6 3


     5----1------2
     \     \
      \     \
       \     \
        6-----4------3

Enter the number of vertex and edges: 6 6
Enter the edges:
5 1
3 4
6 4
1 2
5 6
1 4
Hamiltonian Path is possible in the graph
The path is :  2 1 5 6 4 3
"""
