'''
Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju() which returns an integer denoting the number of strongly connected components in the graph.
'''
# Kosaraju's algorithm to find strongly connected components in Python


from collections import defaultdict as dd

class graph:

    def __init__(self, value):
        self.data = value
        self.graph = dd(list)

    def creategraph(self, s, d):
        self.graph[s].append(d)

    def fillinorder(self, d, visited, stack):
        visited[d] = True
        for i in self.graph[d]:
            if not visited[i]:
                self.fillinorder(i, visited, stack)
        stack = stack.append(d)

    # reverse the matrix
    def reversegraph(self):
        g = graph(self.data)

        for i in self.graph:
            for j in self.graph[i]:
                g.creategraph(j, i)
        return g

    # Depth First Search
    def dfs(self, d, visited):
        visited[d] = True
        print(d, end='')
        for i in self.graph[d]:
            if not visited[i]:
                self.dfs(i, visited)

    # Print stongly connected graph nodes
    def stronglyconnectedgraph(self):
        stack = []
        visited = [False] * (self.data)

        for i in range(self.data):
            if not visited[i]:
                self.fillinorder(i, visited, stack)

        gr = self.reversegraph()

        visited = [False] * (self.data)

        while stack:
            i = stack.pop()
            if not visited[i]:
                gr.dfs(i, visited)
                print("")


g = graph(8)
g.creategraph(0, 1)
g.creategraph(1, 2)
g.creategraph(2, 3)
g.creategraph(2, 4)
g.creategraph(3, 0)
g.creategraph(4, 5)
g.creategraph(5, 6)
g.creategraph(6, 4)
g.creategraph(6, 7)
g.stronglyconnectedgraph()
