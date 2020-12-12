/**
Cycle detection in a directed graph
using dfs. Here, ststus array shows if 
the node is in the path that we are 
currently on. This is used to detect 
any presence of back edges.
backegde present <=> cycle present 
**/

import java.io.*; 
import java.util.*;

public class DirectedCycleDetection {
	private static boolean cycle;
	private static void dfs_visit(ArrayList<ArrayList<Integer> > graph, int src, boolean[] status, boolean[] visit) {
		visit[src] = true;
		status[src] = true;
		for(int i = 0; i < graph.get(src).size(); i++)
			if(visit[graph.get(src).get(i)] == false)
			    dfs_visit(graph, graph.get(src).get(i), status, visit);
			else
			    if(status[graph.get(src).get(i)] == true)
				    cycle = true;
	    status[src] = false;
	}

	private static void dfs(ArrayList<ArrayList<Integer> > graph, int v, boolean[] status) {
		boolean[] visit = new boolean[v];
		for(int i = 0; i < v; i++)
			if(visit[i] == false)
				dfs_visit(graph, i, status, visit);
	}

	private static void detect_cycle(ArrayList<ArrayList<Integer> > graph, int v) {
		boolean[] status = new boolean[v];
		dfs(graph, v, status);
		if(cycle == false)
		    System.out.println("No cycle exits in the given graph");
	    else
		    System.out.println("Cycle exists in the given graph");
	}

	public static void main(String[] args) {
		cycle = false;
		int v, e, a, b;
		// all vertices are labelled from 0 to v-1
		Scanner sc= new Scanner(System.in);
		v = sc.nextInt();
		e = sc.nextInt();
		ArrayList<ArrayList<Integer> > graph = new ArrayList<ArrayList<Integer> >(v);
		for (int i = 0; i < v; i++) 
            graph.add(new ArrayList<Integer>());
		// all directed edges
		for(int i = 0; i < e; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			// edge a -> b
			graph.get(a).add(b);
		} 
		detect_cycle(graph, v);
	}
}

/**
Input :
6 8
0 3
0 4
5 0
1 5
1 0
2 1
3 4
4 5
Output :
Cycle exists in the given graph

Time Complexity : O(v+e)
Space Complexity : O(v)
**/