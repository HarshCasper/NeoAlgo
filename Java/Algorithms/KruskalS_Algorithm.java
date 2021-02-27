/*
It is an algroithm that help us to figure out the Minimum Spanning Tree of a given graph.
Minimum Spanning Tree is a Spanning Tree which has minimum total weight. If we have a linked undirected graph with a weight combine with each edge.
Then the cost of spanning tree would be the sum of the cost of its edges.
It runs faster in sparse graphs
TIME COMLEXITY:
*/
import java.util.Arrays;
import java.util.Scanner;
class Edge implements Comparable<Edge>{
	int source;
	int destination;
	int weight;
	
	//@Override
	public int compareTo(Edge o) {
		//To Sort in increasing order
		return this.weight - o.weight;  
        	}
      }
    public class KruskalS_Algorithm {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
                int Vertices = scan.nextInt();
		int Edges = scan.nextInt();
                Edge input[] = new Edge[Edges];
		for(int i=0;i<Edges;i++) {
			input[i] = new Edge();
			input[i].source = scan.nextInt();
			input[i].destination = scan.nextInt();
			input[i].weight = scan.nextInt();
		}
		Kruskals(input,Vertices);
	}
       private static void Kruskals(Edge[] input, int v) {
		Arrays.sort(input);
		Edge output[] = new Edge[v-1];
		int parent[] = new int[v];
		for(int i=0;i<v;i++) {
			parent[i]=i;
		}
		int count = 0;
		int i=0;
		while(count != v-1) {
			Edge currentEdge = input[i];
			int sourceParent = findParent(input[i].source,parent);
			int destParent = findParent(input[i].destination,parent);
		
			if(sourceParent != destParent) {
				output[count] = currentEdge;
				count++;
				parent[sourceParent] = destParent;
			}
			i++;
		}
		for(int j=0;j<v-1;j++) {
			if(output[j].source < output[j].destination) {
				System.out.println(output[j].source + " " + output[j].destination + " "+ output[j].weight);
			}else {
				System.out.println(output[j].destination + " " + output[j].source + " "+ output[j].weight);
			}
		}
	}
       private static int findParent(int source, int[] parent) {
		if(parent[source] == source) {
			return source;
		}
		return findParent(parent[source],parent);
	 }
 }
/*
Sample Input
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output
1 2 1
0 1 3
0 3 5
*/
