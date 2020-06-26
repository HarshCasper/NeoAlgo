#dfs_visit

#a key-value pair represent a vertex and all its outward edges.
adjacent = {}

#stores the list of vertex.
Vertex = []

#stores the dfs order.
stack = []

# a key-value pair represents a vertex and its parent.
parent = {}


def initalizeVertex():
    n = int(input('Enter the no. of vertices.\n'))
    print("Enter the vertexes.")
    for i in range(n):
        vertex = input()
        Vertex.append(vertex)
        adjacent[vertex] = []

def initalizeUndirectedEdges():
    n = int(input("Enter the no. of edges.\n"))
    print("Enter the space seperated edges.")
    for i in range(n):
        a,b = input().split()
        adjacent[a].append(b)
        adjacent[b].append(a)

def initalizeDirectedEdges():
    n = int(input("Enter the no. of edges.\n"))
    print("Enter the space seperated edges.")
    for i in range(n):
        a,b = input().split()
        adjacent[a].append(b)    

def showVertex():
    print('The vertexes are: ')
    print(vertex)
    print('\n')

def showEdges():
    print('The dictionary of edges are: ')
    print(adjacent)
    print('\n')


def dfs(s):
    for neighbour in adjacent[s]:
        if neighbour not in parent.keys():
            parent[neighbour] = s
            stack.append(neighbour)
            dfs(neighbour)
            




#******program starts here.******

initalizeVertex()
#we can call initalizeDirectedEdges if it is directed graph.
initalizeUndirectedEdges()  

#showVertex()
#showEdges()


print('Implementing dFS.')

#for a well connected grapgh, we don't need the below for loop.
#dfs(starting_vertex) will give correct result.
#the below for loop is used for unconnected graphs.
for v in Vertex:
    if v not in parent.keys():
        parent[v] = None
        stack.append(v)
        dfs(v)


print('DFS order is: ')
print(stack)




















