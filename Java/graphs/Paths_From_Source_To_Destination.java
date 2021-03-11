import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src; // source
        int nbr; // neighbour
        int wt; // weight

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // creating graph
        int vtces = Integer.parseInt(br.readLine());
        ArrayList < Edge > [] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList < > ();
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

        int src = Integer.parseInt(br.readLine()); // source
        int dest = Integer.parseInt(br.readLine()); // destination

            boolean[] visited = new boolean[vtces]; // visited array tracks if element is visited or not
        printAllPaths(graph, src, dest, visited, src + "");
    }

    // this function will print all paths from source to destination
    public static void printAllPaths(ArrayList < Edge > [] graph, int src, int dest, boolean[] visited, String psf) {
        if (src == dest) { // when we reach destination
            System.out.println(psf); // printing possible paths
            return;
        }
        visited[src] = true; // marked as visited
        // traversing through graph
        for (Edge edge: graph[src]) {
            if (visited[edge.nbr] == false) {
                printAllPaths(graph, edge.nbr, dest, visited, psf + edge.nbr);
            }
        }
        visited[src] = false; // unmarked
    }
}

/* Sample Input- 7 8
                0 1 10
                1 2 10
                2 3 10
                0 3 10
                3 4 10
                4 5 10
                5 6 10
                4 6 10
                0 6
Sample Output-  0123456
                012346
                03456
                0346
*/