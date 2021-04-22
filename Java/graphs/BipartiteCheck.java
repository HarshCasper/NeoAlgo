/*
    Bipartite Check problem.
    Given a graph. Check whether the graph is bipartite or not.
    
    A bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets U and V 
    such that every edge connects a vertex in U to one in V. 
    
    Vertex sets U and V are usually called the parts of the graph. 
    
    Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles.[1][2]  (Definition taken from Wikipedia)
    
    Input: No of vertices, edge list of the graph.
    Output: boolean value representing whether the graph is bipartite or not
    
    Code is contributed by Jahnavi Majji
*/

import java.util.*;

public class BipartiteCheck {
    public static void main(String[] args) {
        //driver code;
        Scanner Scanner = new Scanner(System.in);

        //take the necessary input: vertices, edges
        System.out.println("Enter number of vertices and edges: ");
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        List<Integer>[] graph = new ArrayList[vertices];
        for(int i = 0; i < vertices; i++) {
            graph[i] = new ArrayList();
        }

        //build the graph from the edges.
        System.out.println("Enter the source and destination of the edges: ");
        while(edges-- > 0) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();

            --from; --to;   //this is to make sure the vertices of the edges are by 0-index based
            graph[from].add(to);
            graph[to].add(from);
        }

        scanner.close();

        System.out.println("Is the graph Bipartite? " + isGraphBipartite(graph, vertices));

    }

    private static boolean isGraphBipartite(List<Integer>[] graph, int vertices) {
        int[] color = new int[vertices];
        for(int i = 0; i < vertices; i++) {
            color[i] = -1;
        }

        //A queue to perform Breadth First Search
        Queue<Integer> queue = new LinkedList();

        //boolean value storing the result
        boolean isBipartite = true;
        for(int i = 0; i < vertices; i++) {
            //if the vertex is not yet colored, perform Breadth First Search
            if(color[i] == -1) {
                queue.add(i);

                while(!queue.isEmpty()) {
                    int at = queue.poll();

                    //add all uncolored neighboring vertices to the queue
                    for(int to : graph[at]) {
                        if(color[to] == -1) {
                            color[to] = color[at] ^ 1;
                            queue.add(to);
                        }
                        else {
                            //if the neighbor is already colored, the colors of those vertices shouldn't match
                            isBipartite = isBipartite & (color[at] != color[to]);
                        }
                    }
                }
            }
        }

        //return the result
        return isBipartite;
    }
}


/* 
Sample Input: 
Enter number of vertices and edges: 4 4
Enter the source and destination of the edges: 
1 2
2 3
4 3
1 4
    
Output: 
Is the graph Bipartite? true.
    
Time Complexity: O(V + E) where V = vertices, E = edges
Space Complexity: O(E) + O(N) for color array + O(N) for queue

*/ 

