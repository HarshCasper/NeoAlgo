class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    # Search function

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def apply_union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    #  Applying Kruskal algorithm
    def kruskal_algo(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        print("Edge  : Weight")
        for u, v, weight in result:
            print("%d - %d : %d" % (u, v, weight))

if __name__ == '__main__':
  g = Graph(6)
  for i in range(8):
      src = int(input("Source : "))
      dest = int(input("Destination : "))
      weight = int(input("Weight : "))
      g.add_edge(src,dest,weight)
  
  g.kruskal_algo()


'''
Sample Input :
Source : 0
Destination : 1
Weight : 4 
Source : 0 
Destination : 2 
Weight : 4 
Source : 1 
Destination : 2 
Weight : 2 
Source : 2 
Destination : 3 
Weight : 3 
Source : 2 
Destination : 5 
Weight : 2 
Source : 2 
Destination : 4 
Weight : 4 
Source : 3 
Destination : 4 
Weight : 3 
Source : 5 
Destination : 4 
Weight : 3

Sample Output:

Edge : Weight

1 - 2 : 2

2 - 5 : 2

2 - 3 : 3

3 - 4 : 3

0 - 1 : 4

Let E denote the number of Edges and V denote the number of Vertices.
Time Complexity: `O(E log V)`
Space Complexity: `O(E+V)`
'''
