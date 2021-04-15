# Kosaraju-Sharir's algorithm is a linear time algorithm
# to find the strongly connected components of a directed graph.

# Strongly Connected Component
class SCC:
    def __init__(self, graph={}, nodeNum=0):
        self.nodeNum = nodeNum
        self.graph = graph
        self.stack = {}
        # Lists for Strongly Connected Components
        self.scc = []
        # Length of Strongly Connected Components
        self.sccCount = []

    #To Load your dataset
    def LoadData(self, path, nodeNum):
        self.nodeNum = nodeNum
        with open(path) as f:
            graph_ = f.readlines()
        for element in graph_:
            key = int(element.split()[0])
            if not self.graph.__contains__(key):
                self.graph[key] = [int(element.split()[1])]
            else:
                self.graph[key].append(int(element.split()[1]))

    # To compute the finishing time of a node
    def FirstPassDFS(self, graph, start, t, searched):
        stack_ = [start]
        v = []
        while stack_:
            vv = stack_.pop()
            if searched[vv] == False:
                v.append(vv)
                searched[vv] = True
                stack_.extend(graph[vv])
        n = len(v)
        t += n
        for i in range(n):
            if not self.stack.__contains__(v[i]):
                self.stack[v[i]] = t - i
        return t

    # To find the Stongly Connectected Component
    def SecondPassDFS(self, graph, start, searched):
        stack = [start]
        list = []
        while stack:
            v = stack.pop()
            if searched[v] == False:
                searched[v] = True
                list.append(v)
                stack.extend(graph[v])
        return list

    # To compute the finishing time of every node
    def FirstPassAlgorithm(self, graphRev, searched, t):
        for i in range(self.nodeNum, 1, -1):
            if searched.__contains__(i) and searched[i] == False:
                t = self.FirstPassDFS(graphRev, i, t, searched)

    # To find the Stongly Connectected Components
    def SecondPassAlgorithm(self, graphWithFinishingTIme, visited):
        for i in range(self.nodeNum, 1, -1):
            if visited.__contains__(i) and visited[i] == False:
                self.scc.append(self.SecondPassDFS(graphWithFinishingTIme, i, visited))
                # To add length of Strongly Connected Component
                self.sccCount.append(len(self.scc[-1]))

    # To reverse all the directed edges in  agraph
    def GraphRev(self):
        graphRev = {}
        searched = {}
        t = 0
        # Reverse all Edges
        for i in self.graph.keys():
            for j in self.graph[i]:
                if not graphRev.__contains__(j):
                    graphRev[j] = [i]
                else:
                    graphRev[j].append(i)
        # Add all nodes to searched list and assign it False
        for i in graphRev.keys():
            searched[i] = False

        # Add all nodes with no outgoing edges to searched list and assign it False
        for i in graphRev.values():
            for j in i:
                if not searched.__contains__(j):
                    searched[j] = False

        # Add all nodes with no outgoing edges to graphRev Dict and assign it []
        for i in searched.keys():
            if not graphRev.__contains__(i):
                graphRev[i] = []

        self.FirstPassAlgorithm(graphRev, searched, t)

    # To create new graph with the finishing time of the nodes
    def GraphWithFinishingTIme(self):
        graphWithFinishingTIme = {}
        visited = {}
        for i in self.stack.keys():
            graphWithFinishingTIme[self.stack[i]] = []
            if self.graph.__contains__(i):
                for j in self.graph[i]:
                    if self.stack.__contains__(j):
                        graphWithFinishingTIme[self.stack[i]].append(self.stack[j])

        # Add all nodes with no outgoing edges to visited list and assign it False
        for i in graphWithFinishingTIme.keys():
            visited[i] = False

        self.SecondPassAlgorithm(graphWithFinishingTIme, visited)

    # To run the Algorithm
    def BringItAll(self):
        self.GraphRev()
        self.GraphWithFinishingTIme()

    # To get the length of every strongly connected component
    def SCC_Counts(self):
        self.BringItAll()
        self.sccCount.sort(reverse=True)
        return self.sccCount

    # To get list of every strongly connected component
    def Scc(self):
        self.BringItAll()
        return self.scc


if __name__ == "__main__":
    choice = input("Enter graph manually or load text file(0: for manual, Any other key: load tex file): ")
    if choice == "0":
        graph = {}
        nodes = int(input("Enter Number of nodes: "))
        num_edges = int(input("Enter Number of Edges: "))
        c = num_edges
        edges = []
        while num_edges != 0:
            edge = input(f"Enter edge number {c - num_edges + 1}: ").split(" ")
            edge_ = [int(i) for i in edge]
            edges.append(edge_)
            num_edges -= 1
        for i in edges:
            if not graph.__contains__(i[0]):
                graph[i[0]] = [i[1]]
            else:
                graph[i[0]].append(i[1])
        g = SCC(graph, nodes)
    else:
        g = SCC()
        path = input("Enter Path for you data: ")
        nodes = int(input("Enter Number of nodes: "))
        g.LoadData(path, nodes)
    print("Length of at most Longest 5 Strongly Connected Components: ")
    print(g.SCC_Counts()[:5])
    print("Longest Strongly Connected Components: ")
    print(g.Scc()[0])

# Sample Input

# Enter graph manually or load text file(0: for manual, Any other key: load tex file): 0
# Enter Number of nodes: 8
# Enter Number of Edges: 11
# Enter edge number 1: 1 2
# Enter edge number 2: 2 3
# Enter edge number 3: 3 1
# Enter edge number 4: 3 4
# Enter edge number 5: 5 4
# Enter edge number 6: 6 4
# Enter edge number 7: 8 6
# Enter edge number 8: 6 7
# Enter edge number 9: 7 8
# Enter edge number 10: 4 3
# Enter edge number 11: 4 6
# Length of at most Longest 5 Strongly Connected Components:
# [7, 1]
# Longest Strongly Connected Components:
# [8, 6, 7, 5, 3, 1, 2]

# Complextiy = O(m+n)
