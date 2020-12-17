# Depth First Search for graphs


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0 for j in range(vertices)]for i in range(vertices)]

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
        Helps us to check whether a particular edge is present in a graph or not.
        '''
        if self.adjMatrix[v1][v2] != 0:
            return True
        else:
            return False

    def getPathDFShelper(self, sv, ev, visited):
        '''
        Summary line-
        Helps us to perform depth first search in the graph using a stack and adjacency matrix.

        Working-
        We use the visited list to mark `True` for every vertex we visit.
        After being visited, we push the next element of the vertex
        into the stack and continue untill we reach a point where
        the next element is also marked `True` for visited.

        Variable names-
        sv- Starting vertex
        ev- Ending vertex
        '''
        if sv == ev:
            path = [ev]
            return True, path
        visited[sv] = True
        for i in range(self.vertices):
            if self.adjMatrix[sv][i] == 1 and visited[i] == False:
                hasPath, path = self.getPathDFShelper(i, ev, visited)
                if hasPath == True:
                    path.append(sv)
                    return True, path
        return False, []

    def getPathDFS(self, sv, ev):
        visited = [False for i in range(self.vertices)]
        hasPath, path = self.getPathDFShelper(sv, ev, visited)
        if hasPath == True:
            return path
        return list()


if __name__ == "__main__":
    v, e = map(int, input().split())
    if v > 0 and e > 0:
        g = Graph(v)
        for i in range(e):
            v1, v2 = map(int, input().split())
            g.addEdge(v1, v2)
        sv, ev = map(int, input().split())
        path = g.getPathDFS(sv, ev)
        for i in path:
            print(i, end = " ")

# Sample input-
# 4 4
# 0 1
# 0 3
# 1 2
# 2 3
# 1 3

# Sample output-
# 3 0 1

# Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
