# Breadth First Search for a Graph
import queue


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix\
            = [[0 for j in range(self.vertices)]for i in range(self.vertices)]

    def addEdge(self, v1, v2):
        self.adjMatrix[v1][v2] = 1
        self.adjMatrix[v2][v1] = 1

    def removeEdge(self, v1, v2):
        if self.containsEdge(v1, v2):
            self.adjMatrix[v1][v2] = 0
            self.adjMatrix[v2][v1] = 0

    def containsEdge(self, v1, v2):
        '''
        Summary line-
        Helps us to check whether a particular
        edge is present in a graph or not.
        '''
        if self.adjMatrix[v1][v2] != 0:
            return True
        else:
            return False

    def __str__(self):
        return str(self.adjMatrix)

    def bfsHelper(self, sv, ev, visited, path):
        '''
        Summary line-
        Helps us to perform breadth first search in the graph using a queue.

        Working-
        We use the visited list to mark `True` for every element we visit.
        We get the elements from the queue,
        mark it visited and push its neighboring vertices.

        Variable names-
        sv- Starting vertex
        ev- Ending vertex
        '''
        q = queue.Queue()
        q.put(sv)
        visited[sv] = True
        while not q.empty():
            cur = q.get()
            for i in range(self.vertices):
                if self.adjMatrix[cur][i] > 0 and visited[i] is False:
                    path[i] = cur
                    if i == ev:
                        print(ev, end=" ")
                        return True
                    q.put(i)
                    visited[i] = True

    def bfs(self, sv, ev):
        visited = [False for j in range(self.vertices)]
        path = dict()
        if self.bfsHelper(sv, ev, visited, path) is True:
            return path
        return dict()

if __name__ == "__main__":
    print("Enter no of vertices and edges-")
    v, e = map(int, input().split())
    if v > 0 and e > 0:
        g = Graph(v)
        for i in range(e):
            print("Enter vertices having edge between them-")
            v1, v2 = map(int, input().split())
            g.addEdge(v1, v2)
        print("Enter starting and ending vertex")
        sv, ev = map(int, input().split())
        path = g.bfs(sv, ev)
        x = path.get(ev, -1)
        while x != -1:
            print(x, end=" ")
            x = path.get(x, -1)

'''
Sample input-
4 4
0 1
0 3
1 2
2 3
1 3

Sample output-
3 0 1

Time Complexity: O(V+E) where V is number
of vertices in the graph and
E is number of edges in the graph.
'''
