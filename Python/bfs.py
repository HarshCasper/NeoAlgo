# breadth first search

#a key-value pair represent a vertex and all it's outward edges.
adjacent = {}

#stores the list of vertex.
Vertex = []

# a key-value pair represents a vertex and its level.
# level of the root node is zero.
level = {}

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
    print(Vertex)
    print('\n')

def showEdges():
    print('The dictionary of edges are: ')
    print(adjacent)
    print('\n')


def bfs():
    frontier = []
    neighbour = []

    start = input('Enter the first node.\n')
    
    level[start] = 0
    parent[start] = None
    level_no = 1

    frontier.append(start)

    while len(frontier):
        neighbour = []

        for u in frontier:
            for v in adjacent[u]:
                if v not in level.keys():
                    level[v] = level_no
                    parent[v] = u
                    neighbour.append(v)

        frontier = neighbour.copy()
        level_no +=1    




# program starts here.

initalizeVertex()
initalizeUndirectedEdges()  

#showVertex()
#showEdges()

print('Implementing BFS.')
bfs()

print(level)







