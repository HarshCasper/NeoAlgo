# Depth First Search Traversal in Graphs

# Graph class created
class Graph:

    def __init__(self):
        # graph declared to a dictionary
        self.graph = {}
        # visited nodes are maintained in this set
        self.visited = set()

    def add_vertex(self,vertex):
        # vertex is added to the graph dictionary and it's adjacency list is declared
        self.graph[vertex] = []
    
    def add_edge(self,source,destination):
        # directional edges are added in this function
        # the edge is directional, i.e., going from source to destination

        # conditional statements in case the vertex aren't present in the graph
        if destination not in self.graph or source not in self.graph:
            if source not in self.graph:
                print(str(source)+' is not a vertex')
                return 1     # 1 is returned to avoid stopping the running of the program allows the user to re-enter values
            if destination not in self.graph:
                print('\n'+str(destination)+' is not a vertex.')
                return 1     # 1 is returned to avoid stopping the running of the program allows the user to re-enter values

        # edge is added to the graph, from source to destination
        self.graph[source].append(destination)

    def add_edge_bidirected(self,vertex1,vertex2):
        # bidirectional graph edges are added in this function
        # the edge is bidirectional, i.e., the edge goes both ways

        # conditional statements to check if the vertices are present
        if vertex2 not in self.graph or vertex1 not in self.graph:
            if vertex1 not in self.graph:
                print('\n'+str(vertex1)+' is not a vertex'+'\n')
                return 1    # 1 is returned to avoid stopping the running of the program allows the user to re-enter values
            if destination not in self.graph:
                print('\n'+str(vertex2)+' is not a vertex.'+'\n')
                return 1    # 1 is returned to avoid stopping the running of the program allows the user to re-enter values
        
        # edges are added to the adjacency list
        self.graph[vertex1].append(vertex2)
        self.graph[vertex2].append(vertex1)

    def dfs_helper(self,start):
        # function to assist in calling dfs
        # also prints the final dfs traversal

        # checks if the start node is in the graph
        if start not in self.graph:
            print('\n'+str(start)+' not in graph.'+'\n')
            return 1 # 1 is returned to avoid stopping the running of the program, allows the user to re-enter the start vertex
        
        # dfs implementation starts
        print('\n'+'Implementing DFS...')
        self.traversal = [] # the dfs traversal is added to the list in order
        self.dfs(start)

        # prints the dfs implementation neatly
        for i in range(len(self.traversal)):
            if i == (len(self.traversal)-1):
                print(str(self.traversal[i]))
            else:
                print(str(self.traversal[i])+' -> ',end="")
            
    def dfs(self,node):
        # dfs function
        if node not in self.visited:            # checks if the node was already visited
            self.traversal.append(node)         # if the node wasnt traversed already, it's appended to the traversal
            self.visited.add(node)              # the node is marked visited
            for neighbour in self.graph[node]:  # the neighbouring vertices of the node are explored one after the other     
                self.dfs(neighbour)
        
# Code Implementation starts here

# Graph instance is created
G = Graph()

# vertices are added to the graph
for v in range(int(input('How many vertices are in the graph? '))):
    G.add_vertex(str(input("Enter Vertex: ")))

# edges are added to the graph
for e in range(int(input('\n'+'How many edges are in the Graph? '))):
    source,destination = input("Enter Source and Destination Vertices separated by a space: ").split()
    val = G.add_edge(source,destination)

    # If the incorrecct vertex was given, the values are taken again for this iteration
    # This is added to not skip over a count of the edge
    while val == 1:
        source,destination = input("Enter Source and Destination Vertices separated by a space: ").split()
        val = G.add_edge(source,destination)

# start node for the dfs traversal is taken from the user
start_node = input('\n'+"Enter the Start Node for traversal: ")

# dfs is implemented
ret = G.dfs_helper(start_node)

# If the user entered a non-existent vertiex as start node, the following is implemented
# 1 is returned if the vertex is non existent
while ret==1:
    start_node = input('\n'+"Enter the Start Node for traversal: ")
    ret = G.dfs_helper(start_node)

# To implement dfs for bi-directional graphs, replace G.add_edge in lines 88-96
# with G.add_edge_bidirectional