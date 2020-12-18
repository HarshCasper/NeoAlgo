#MODULES

# Importing sys module to initalize the maxsize
import sys
# Importing collections model to access deque
from collections import deque
# Importing collections model to access defaultdict
from collections import defaultdict

''' Bridge-Edge-in-Graph '''
'''
Problem Statement :Given an undirected graph and an edge, the
                   task is to find if the given edge is a
                   bridge in graph, i.e., removing the edge
                   disconnects the graph.

Input :The first line of the input contains an integer 'T'
       denoting the number of test cases. Then 'T' test cases
       follow. Each test case consists of two lines.
       Description of  test cases is as follows:
                   The First line of each test case contains
                   two integers 'N' and 'M'  which denotes
                   the no of vertices and no of edges
                   respectively.
                   
                   The Second line of each test case contains
                   M space-separated pairs u and v denoting that
                   there is a bidirectional edge from u to v.

                   The third line contains two space-separated
                   integers denoting the edge to be removed.

Output :Output True if the edge is a Bridge and
        output False otherwise
'''

# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Initialize Infinity
INF = 9999999

# FUNCTIONS
# Create The graph


def creategraph(no_of_edges, array, graph):
    i = 0
    # Since the given Graph is a Biparted Graph
    while (i < 2 * no_of_edges):
        graph[array[i]].append(array[i + 1])
        graph[array[i+1]].append(array[i]) 
        i += 2

# For Breath First Search


def BFS(graph, u, lists, visited):
    # Create the queue to check the next reachable cell
    queue = []
    queue.append(u)
    # List to check if the cell is visited or not
    visited[u] = 1
    while(queue):
        temp = queue.pop(0)
        visited[temp] = 1
        lists.append(temp)
        for i in graph[temp]:
            if visited[i] == 0:
                queue.append(i)
                visited[i] = 1
    return lists

# To Check If the given Edge is a bridge or not


def checkbridge(graph, no_of_vertices, u, v):
    lists = []
    # List to check if the cell is visited or not
    visited = [0]*no_of_vertices
    getlist1 = BFS(graph, u, lists, visited)
    # Now remove given edge
    graph[u].remove(v)
    lists2 = []
    visited2 = [0]*no_of_vertices
    getlist2 = BFS(graph, u, lists2, visited2)
    if (len(getlist1) == len(getlist2)):
        return False
    else:
        return True

# MAIN Function

# INPUTS

print("Enter the number of vertices and the number of edges.")
no_of_vertices, no_of_edges = map(int, input().split())
# no_of_edge space-separated pairs u and v denoting that there
# is a bidirectional edge from u to v.
print("Enter the vertices of the edges.")
array = list(map(int, input().strip().split()))
# Space-separated integers denoting the edge to be
# removed if its a bridge.
print("Enter the expected node of the bridge.")
u, v = list(map(int, input().strip().split())) 
graph = defaultdict(list)
creategraph(no_of_edges, array, graph)


# OUTPUT

if checkbridge(graph, no_of_vertices, u, v):
    print ("The BRIDGE is present.")
else:
    print ("The BRIDGE is not present.")

# SAMPLE
'''
INPUT

    Enter the number of vertices and the number of edges.
    4 3
    Enter the vertices of the edges.
    0 1 1 2 2 3
    Enter the expected node of the bridge.
    1 2

OUTPUT

    The BRIDGE is present.
'''
