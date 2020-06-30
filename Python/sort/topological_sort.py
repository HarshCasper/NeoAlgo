#topological sort

#a key-value pair represent a vertex and all it's outward edges.
adjacent = {}
#stores the list of vertex.
Vertex = []
# a key-value pair represents a vertex and its parent.
parent = {}
#stores the topological sort in reverse order.
topological_sort = []

def initalizeVertex():
    n = int(input('Enter the no. of vertices.\n'))
    print("Enter the vertexes.")
    for i in range(n):
        vertex = input()
        Vertex.append(vertex)
        adjacent[vertex] = []

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

def t_sort(s):
    for neighbour in adjacent[s]:
        if neighbour not in parent.keys():
            parent[neighbour] = s
            #stack.append(neighbour)
            t_sort(neighbour)
    topological_sort.append(s)      


# program starts here

initalizeVertex()
initalizeDirectedEdges()  
#showVertex()
#showEdges()
print('Implementing Topological Sort.')
#for a well connected grapgh, we don't need the below for loop.
#dfs(starting_vertex) will give correct result.
#the below for loop is used for unconnected graphs.
for v in Vertex:
    if v not in parent.keys():
        parent[v] = None
        t_sort(v)

print('Topological sort order is: ')
print(topological_sort[::-1])
