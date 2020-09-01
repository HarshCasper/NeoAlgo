# Kosaraju's algorithm runs in linear time i.e. O(V+E)

from collections import defaultdict


class Graph:

    def __init__(self, vertex):
        self.vertex = vertex
        self.graph = defaultdict(list)

    # Adding of the edge into the graph
    def add_edge(self, s, d):
        self.graph[s].append(d)

    # dfs (depth first search)
    def dfs(self, d, visited_vertex):
        visited_vertex[d] = True
        print(d, end=' ')
        for i in self.graph[d]:
            if not visited_vertex[i]:
                self.dfs(i, visited_vertex)

    def fill_order(self, d, visited_vertex, stack):
        visited_vertex[d] = True
        for i in self.graph[d]:
            if not visited_vertex[i]:
                self.fill_order(i, visited_vertex, stack)
        stack = stack.append(d)

    def transpose(self):
        g = Graph(self.vertex)

        for i in self.graph:
            for j in self.graph[i]:
                g.add_edge(j, i)
        return g

    # Printing stongly connected components
    def print_scc(self):
        stack = []
        visited_vertex = [False] * (self.vertex)

        for i in range(self.vertex):
            if not visited_vertex[i]:
                self.fill_order(i, visited_vertex, stack)

        gr = self.transpose()

        visited_vertex = [False] * (self.vertex)

        while stack:
            i = stack.pop()
            if not visited_vertex[i]:
                gr.dfs(i, visited_vertex)
                print("")


print("Enter number of vertices you want the graph of: ")
n = int(input())
g = Graph(n)
for i in range(0, n+1):
    print("Enter the elements of an edge: ")
    a = int(input())
    b = int(input())    
    g.add_edge(a, b)

print("Strongly Connected Components:")
g.print_scc()
