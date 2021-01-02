class Graph:
    """
    we create an empty adjacency list with values of the nodes as key elements and setting the values as an
    empty list
    """

    elements = []
    """
    Initialing the parents,adjacency list and visited dictionaries.
    """

    def __init__(self, Nodes):
        self.parents = {}
        self.adj_list = {}
        self.node = Nodes
        self.color = {}
        for node in self.node:
            self.adj_list[node] = []
            self.color[node] = "W"
            self.parents[node] = None

    """
    in add_edge function we make and adjacency list of the undirected graph
    """

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    """
    The main dfs algorithm where we iterate over the neighbours of a node and append them to the element list if 
    it has not been visited before by checking the visited dictionary, also calculate the parent of each node.
    """

    def dfs(self, k):
        # self.visited[u] = 1
        if k not in self.elements:
            self.elements.append(k)
            self.color[k] = "B"
        for v in self.adj_list[k]:
            if self.color[v] == "W":
                self.parents[v] = k
                self.dfs(v)

    """
    The print function print the neighbours of each node, the nodes after iterating over the graph in dfs manner and
    also the parent if each node after executing the dfs function.
    """

    def print(self):
        for node in self.node:
            print(node, "->", self.adj_list[node])
        print("Nodes iterated in the graph:", self.elements)
        print("Parents of each node:", self.parents)


"""
We create the node list along with the object of the class Graph.
specify the nodes and the and the edges in the nodes and edges list before the execution of the program
We call all the functions outside the class using the object created which is 'graph'
"""
nodes = ["A", "B", "C", "D", "E", "F", "G"]
edges = [("A", "B"), ("B", "D"), ("B", "C"), ("E", "F"), ("F", "G")]
"""
The next line creates the instance of the class Graph
"""
graph = Graph(nodes)
color = graph.color
"""
The loop iterates over the edges list and adds them to the adjacency list
"""
for i, j in edges:
    graph.add_edge(i, j)
"""
It iterates over all the nodes and does the depth first search on the tree or the forest
"""
for (m,n) in edges:
    if color[m] == "W":
        graph.dfs(m)
"""
Prints the nodes after iterating over the graph and also the parent of each node  
"""
graph.print()
