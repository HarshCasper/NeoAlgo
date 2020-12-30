''' 
Euler-circuit-and-Path

Problem Statement : Eulerian Path is a path in graph that
                   visits every edge exactly once.
                   Eulerian Circuit is an Eulerian
                   Path which starts and ends on the
                   same vertex.
                   The task is to find that there
                   exists the Euler Path or circuit
                   or none in given undirected graph.

Input : First line consists of test cases T. First
       line of every test case consists of 2
       integers V and E, denoting the number of
       vertex and edges. Second line of every test
       case consists of 2*E spaced integers denoting
       the edge connected.


Output : Return the int value to print 1 if Euler path
        exists print 2 if Euler cycle exists else 0.

Time Complexity : O(V+E)
Time Complexity : O(N)

'''

# Importing sys module to initalize the maxsize
import sys
# Importing collections model to access deque and defaultdict
from collections import deque, defaultdict

# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Initialize Infinity
INF = 9999999

# Create The graph
class Graph():

    # Add the vertices of the graph

    
    def __init__(self,vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    # Add directed edge from u to v.


    def addEdge(self,u,v): 
        self.graph[u].append(v)

# Check for Euler Path
def Eulerpath(G, no_of_vertices, no_of_edges):
    # G is G.graph
    Nodes_odd_degree = 0
    for node, connectednodes in G.items():
        if (len(connectednodes) %2 == 1):
            Nodes_odd_degree = Nodes_odd_degree + 1
        if Nodes_odd_degree > 2 :
            return 0
    if (Nodes_odd_degree == 0):
        return 2
    else:
        return 1

# -----------------------Driver Code-----------------------

no_of_vertices = int(input("Enter the number of vertices: "))
no_of_edges = int(input("Enter the number of edges: "))
# Create the graph
G = Graph(no_of_vertices)
# Enter the 2*Edge no of vertices
print("Enter the vertices of the edges:")
edges = list(map(int, input().strip().split()))
# Add the undirected graphs from u to v
for i in range(0, len(edges), 2):
    u, v = edges[i], edges[i+1]
    G.addEdge(u, v)
    G.addEdge(v, u)

# OUTPUT
if (Eulerpath(G.graph, no_of_vertices, no_of_edges) == 1):
    print ("The Euler path exists.")
elif (Eulerpath(G.graph, no_of_vertices, no_of_edges) == 0):
    print ("The Euler path does not exists.")

'''
SAMPLE INPUT/OUTPUT:

INPUT

    Enter the number of vertices: 5
    Enter the number of edges: 5
    Enter the vertices of the edges.
    1 0 0 2 2 1 0 3 3 4

OUTPUT

    The Euler path exists.
'''
