
// Java Program to implement DFS using recursive function

import java.io.*;
import java.util.*;
 
class DFS {
    // No. of vertices
    private int V; 
 
    // Array  of lists for 
    // Adjacency List Representation
    private LinkedList<Integer> adj[];
 
    // Constructor
    @SuppressWarnings("unchecked") DFS(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }
 
    // Function to add an edge into the graph
    void add_Edge(int u, int w)
    {
        adj[u].add(w);
    }
 
    // A function used by DFS
    void DFSUtil(int v, boolean visit[])
    {
        // Mark the current node as visited and print it
        visit[v] = true;
        System.out.print(v + " ");
 
        // Recur for all the vertices adjacent to this vertex
        Iterator<Integer> it = adj[v].listIterator();
        while (it.hasNext()) 
        {
            int n = it.next();
            if (!visit[n])
                DFSUtil(n, visit);
        }
    }
 
    // The function to do DFS traversal.
    void DeapthFS(int v)
    {
        // Mark all the vertices as not visited
        boolean visit[] = new boolean[V];
 
        // Call the recursive helper 
        // function to print DFS
        // traversal
        DFSUtil(v, visit);
    }
 
    // Driver Code
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        DFS d = new DFS(4);
 
        d.add_Edge(0, 1);
        d.add_Edge(0, 2);
        d.add_Edge(1, 2);
        d.add_Edge(2, 0);
        d.add_Edge(2, 3);
        d.add_Edge(3, 3);
        
        System.out.println("Enter starting vertex");
        int ver = sc.nextInt();
        System.out.println(
            "Following is Depth First Traversal ");
 
        d.DeapthFS(ver);
    }
}


/* Time Complexity: O(V + E)
   Space Complexity: O(V)

   Example 1
   Input:
   0

   Output:
   0 1 2 3

   Example 2
   Input:
   1

   Output:
   1 2 0 3
*/

