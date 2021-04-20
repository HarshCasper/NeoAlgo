
/* Here we are given a directed graph and 
   we have to print all paths from the source (src) 
   to the destination (dest) of the graph.
*/
import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vtces = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList<>();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            graph[v1].add(new Edge(v1, v2, wt));
            graph[v2].add(new Edge(v2, v1, wt));
        }

        int src = Integer.parseInt(br.readLine());
        int dest = Integer.parseInt(br.readLine());

        boolean[] visited = new boolean[vtces];
        printAllPaths(graph, src, dest, visited, src + "");
    }

    // src -> source
    // dest -> destination
    // psf -> path so far
    public static void printAllPaths(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited, String psf) {
        // When the destination vertex is reached print contents of path so for (psf).
        if (src == dest) {
            System.out.println(psf);
            return;
        }
        // Keep storing the visited vertices in an array (visited here) so that the
        // traversal doesn’t go in a cycle
        visited[src] = true;
        // traverse through graph
        for (Edge edge : graph[src]) {
            if (visited[edge.nbr] == false) {
                printAllPaths(graph, edge.nbr, dest, visited, psf + edge.nbr);
            }
        }
        // unmark the current vertex
        visited[src] = false;
    }
}

/*
 * Sample Input- 7 8 0 1 10 1 2 10 2 3 10 0 3 10 3 4 10 4 5 10 5 6 10 4 6 10 0 6
 * Sample Output- 0123456 012346 03456 0346
 */
