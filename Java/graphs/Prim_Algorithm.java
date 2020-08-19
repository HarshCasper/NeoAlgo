import java.util.*;

class Prims {
        //Function to get the next vetex of MST based on the min Edge length
        public int getMinEdge(Boolean[] visited,int[] dist,int V){
                int minedge = Integer.MAX_VALUE,minvertex=-1;
                //update the minvertex with smallest edge vertex
                for(int i=0;i<V;i++){
                        if(!visited[i] && minedge>dist[i]){
                                minedge = dist[i];
                                minvertex = i;
                        }
                }
                
                return minvertex;
        }
        
        public void mst(int[][] graph,int V){
                //Array to store the parent node of vertices
                int[] parent = new int[V];
                //Array to store the edge lengths of MST;
                int[] dist = new int[V];
                //Array to check if the node is visited or not
                Boolean[] visited = new Boolean[V];
                //Initialize the dist values as INFINITY and visited as false
                for(int i=0;i<V;i++){
                        dist[i]=Integer.MAX_VALUE;
                        visited[i] = false;
                }
                //0 is going to be root of MST hence
                //make its parent -1 and dist 0
                dist[0] = 0;
                parent[0] = -1;
                //counter loop for selecting V vertices
                for(int k=0;k<V-1;k++){
                        //get vertex with minimum edge
                        int u = getMinEdge(visited,dist,V);
                        //make selected vertex as visited i.e. it is now included in MST
                        visited[u] = true;
                        for(int v=0;v<V;v++){
                                //Conditions to check adjacent unvisited vertices 
                                //Update the dist[v] if graph[u][v] is less than dist[v] 
                                if(!visited[v] && graph[u][v]!=0  && graph[u][v]<dist[v]){
                                        dist[v] = graph[u][v];
                                        parent[v] = u;
                                }
                        }
                }
                //loop to print the solution MST
                System.out.println("Prims MST:");
                for(int u=1;u<V;u++){
                        System.out.println("Edge "+parent[u]+" - "+u+" :length "+dist[u]);
                }
        
        }        
        
                  

        public static void main(String[] args) {
        Prims p = new Prims();

        // number of vertices in graph
        int V = 5;

        // create a 2d array of size 5x5
        // for adjacency matrix to represent graph
        int[][] graph = { { 0, 9, 75, 0, 0 }, { 9, 0, 95, 19, 42 }, { 75, 95, 0, 51, 66 }, { 0, 19, 51, 0, 31 },
        { 0, 42, 66, 31, 0 } };

        p.mst(graph, V);
}
}
