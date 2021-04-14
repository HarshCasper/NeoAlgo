import java.util.*;

class Graph {
  class Edge implements Comparable<Edge> {
    int src, dest, weight;

    public int compareTo(Edge compareEdge) {
      return this.weight - compareEdge.weight;
    }
  };

  // Union
  class subset {
    int parent, rank;
  };

  int vertices, edges;
  Edge edge[];

  // Graph creation
  public Graph(int v, int e) {
    vertices = v;
    edges = e;
    edge = new Edge[edges];
    for (int i = 0; i < e; ++i)
      edge[i] = new Edge();
  }

  int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
      subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
  }

  void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
      subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
      subsets[yroot].parent = xroot;
    else {
      subsets[yroot].parent = xroot;
      subsets[xroot].rank++;
    }
  }

  // Applying Krushkal Algorithm
  void KruskalAlgo() {
    Edge result[] = new Edge[vertices];
    int e = 0;
    int i = 0;
    for (i = 0; i < vertices; ++i)
      result[i] = new Edge();

    // Sorting the edges
    Arrays.sort(edge);
    subset subsets[] = new subset[vertices];
    for (i = 0; i < vertices; ++i)
      subsets[i] = new subset();

    for (int v = 0; v < vertices; ++v) {
      subsets[v].parent = v;
      subsets[v].rank = 0;
    }
    i = 0;
    while (e < vertices - 1) {
      Edge next_edge = new Edge();
      next_edge = edge[i++];
      int x = find(subsets, next_edge.src);
      int y = find(subsets, next_edge.dest);
      if (x != y) {
        result[e++] = next_edge;
        Union(subsets, x, y);
      }
    }
    System.out.println("Edge  : Weight");
    for (i = 0; i < e; ++i)
      System.out.println(result[i].src + " - " + result[i].dest + " : " + result[i].weight);
  }

  public static void main(String[] args) {
    int vertices = 6; // Number of vertices
    int edges = 8; // Number of edges
    Graph G = new Graph(vertices, edges);
    Scanner sc = new Scanner(System.in);
    for(int i = 0;i<8;i++){
        System.out.print("Source : ");
        G.edge[i].src = sc.nextInt();
        System.out.print("Destination : ");
        G.edge[i].dest = sc.nextInt();
        System.out.print("Weight : ");
        G.edge[i].weight = sc.nextInt();
    }
    G.KruskalAlgo();
  }
}


/*
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
*/
