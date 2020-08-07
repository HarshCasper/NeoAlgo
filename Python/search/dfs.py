# Python3 Program to print BFS traversal 
# From a given source vertex.  
from collections import defaultdict 
# This class represents a directed graph 
# using adjacency list representation 
class Graph: 
    # Constructor 
    def __init__(self): 
        # default dictionary to store graph 
        self.graph = defaultdict(list) 
    def addEdge(self,u,v): 
        '''function to add an edge to graph '''
        self.graph[u].append(v) 
    def BFS(self, s): 
        '''Function to print a BFS of graph '''
        # Mark all the vertices as not visited 
        visited = [False] * (len(self.graph)) 
        # Create a queue for BFS 
        queue = []  
        # Mark the source node as visited and enqueue it .
        queue.append(s) 
        visited[s] = True
        while queue: 
            # Dequeue a vertex from queue and print it 
            s = queue.pop(0) 
            print (s, end = " ") 
            # Get all adjacent vertices of the dequeued vertex s. 
            # In case an adjacent has not been visited, then mark it visited and enqueue it 
            for i in self.graph[s]: 
                if visited[i] == False: 
                    queue.append(i) 
                    visited[i] = True
  
# Driver code 
if __name__ == "__main__":
    g = Graph() 
                        # (OR)
    '''
    edges=int(input("Please enter the number of edges you need (min 2) :\t "))
    j=1
    while edges >0:
        print("Edge"+str(j)+":")
        x=int(input("Enter x-axis value : \t"))
        y=int(input("Enter y-axis value : \t"))
        g.addEdge(x,y)
        j+=1
        edges-=1
        '''
    g.addEdge(0, 1) 
    g.addEdge(0, 2) 
    g.addEdge(1, 2) 
    g.addEdge(2, 0) 
    g.addEdge(2, 3) 
    g.addEdge(3, 3)              

    print ("Following is Breadth First Traversal"
                    " (starting from vertex 2)") 
    g.BFS(2) 
