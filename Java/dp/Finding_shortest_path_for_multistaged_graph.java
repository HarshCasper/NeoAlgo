/*
    Finding the Shortest Path from Source node to the Destination node for a Multi-Staged Graph 
    using the DP approach
    Check out -> https://www.geeksforgeeks.org/multistage-graph-shortest-path/ to know more about
    Multi-Staged Graphs
*/

import java.util.*;

class Graph{
    //Method to create a graph using a Matrix of nodes(adjacency Matrix)
    public int[][] create_graph(int n){
        Scanner sc = new Scanner(System.in);
        int adjacency_matrix[][] = new int[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                System.out.println(String.format("Enter the weight of the edge %d%d", i, j));
                adjacency_matrix[i][j] = sc.nextInt();
            }
        }
        return adjacency_matrix; 
    }

    public void printGraph(int[][] graph, int n) 
	{ 
		for (int i = 0; i < n; i++) { 
			System.out.println("\nAdjacency list of vertex " + i);  
			for (int j = 0; j < n; j++) { 
                if(graph[i][j] != 0){
                    System.out.print(" -> "+ j); 
                }
			} 
			System.out.println(); 
		} 
	}
}

public class Finding_shortest_path_for_multistaged_graph {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter the no of Nodes of graph");
        int n = input.nextInt();

        //Array containing Stage No of each node
        int staged_nodes_arr[] = new int[n];

        Graph g = new Graph();
        int graph[][] = g.create_graph(n);
        g.printGraph(graph, n);

        //Note:- Source and dest nodes are not in any stage so both will have value of stage no as 0.
        staged_nodes_arr[0] = 0;
        staged_nodes_arr[staged_nodes_arr.length - 1] = 0;
        for(int i = 1; i<staged_nodes_arr.length - 1; i++){
            System.out.println(String.format("Enter Stage no for node %d", i));
            staged_nodes_arr[i] = input.nextInt();
        }

        System.out.println("Cost of Shortest Path:- " + shortestPath_using_forward_approach(graph, n, staged_nodes_arr));
    }

    //Printing shortest path from source to destination using the parent_arr
    public static void printShortestPath(int parent_arr[]){
        int i = 0;
        String s = i + " ";
        while(i != parent_arr.length - 1){
            i = parent_arr[i];
            s = s + i + " ";
        }
        System.out.print("Path to destination:- " + s + "\n");
    }

    /*
        In the forward Approach, we start traversing the cost_arr[] from the destination node and update 
        the values of each connected node to the current node in the cost_arr[] by finding the minimum
        cost to reach that node. We update the value of a node only if it is less than the current value
        of that node in the cost_arr[]. We also keep updating the parent_arr[] everytime after updating 
        the cost_arr[]. 
    */

    public static int shortestPath_using_forward_approach(int[][] graph, int n, int staged_nodes_arr[]){
        //cost_arr[] contains cost to reach each node for the shortest path
        int cost_arr[] = new int[n];
        Arrays.fill(cost_arr, Integer.MAX_VALUE);
        cost_arr[cost_arr.length - 1] = 0;

        //Creating parent_arr[] to store the previous node for the Shortest path
        int parent_arr[] = new int[n];
        parent_arr[parent_arr.length - 1] = -1;

        for(int i = cost_arr.length - 1; i>0; i--){
            //Previous stage to the current node is stored in "stage"
            int stage;
            if(staged_nodes_arr[i] == 0){
                stage = 3; //Previous stage no of destn node
            }
            else{
                stage = staged_nodes_arr[i] - 1; //Previous stage no of the current node
            }
            //Traversing through the staged_nodes_arr[] to find the node in the previous stage for 
            //current node 
            for(int j = 0; j<staged_nodes_arr.length; j++){
                if(staged_nodes_arr[j] == stage){
                    //If cost to reach current node + edge weight to dest node < cost of dest node, update
                    //cost and parent arrays
                    if(graph[j][i] + cost_arr[i] < cost_arr[j] && graph[j][i] != 0){
                        cost_arr[j] = graph[j][i] + cost_arr[i];
                        parent_arr[j] = i;
                    }
                }
            }
        } 
        printShortestPath(parent_arr);
        return cost_arr[0];
    }
}
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n) where 'n' is no of nodes of graph
*/

/*
Sample Testcase:
Enter the no of Nodes of graph: 10
graph[] =  {{0,3,4,5,0,0,0,0,0,0},  -> Adjacency Matrix
            {0,0,0,0,8,2,0,0,0,0},
            {0,0,0,0,7,11,7,0,0,0},
            {0,0,0,0,0,4,3,0,0,0},
            {0,0,0,0,0,0,0,2,0,0},
            {0,0,0,0,0,0,0,1,7,0},
            {0,0,0,0,0,0,0,0,6,0},
            {0,0,0,0,0,0,0,0,0,9},
            {0,0,0,0,0,0,0,0,0,2},
            {0,0,0,0,0,0,0,0,0,0}};

Enter Stage no for node 1: 1
Enter Stage no for node 2: 1
Enter Stage no for node 3: 1
Enter Stage no for node 4: 2
Enter Stage no for node 5: 2
Enter Stage no for node 6: 2
Enter Stage no for node 7: 3
Enter Stage no for node 8: 3

Output:- 
Cost of Shortest Path:- 14
Path to destination:- A B F I J
*/
